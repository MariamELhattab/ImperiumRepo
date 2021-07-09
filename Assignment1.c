#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//N : number of students
int N;

struct Student *stdPtr;


/* ---------------------------------Defining Structure--------------------------------- */
struct Student
{
	char *name;
	int std_ID;
	int day,month,year;
	int score_std;
	char flag;
	struct Student *next;
};



/* -------------------------------Dynamic Array Functions-------------------------------- */
void insertInTheBeginning_DA(struct Student *stdPtr);
void insertAtTheEnd_DA(struct Student *stdPtr);
void insertInTheMiddle_DA(struct Student *stdPtr, int location);
void insert (struct Student *stdPtr,char *name_f,int ID,int year,int month,int day,int score);
void printArray(struct Student *stdPtr);


/* --------------------------------Linked List Functions-------------------------------- */
void InsertFirst_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore);
void InsertEnd_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore);
void InsertAtPos_LL (int pos,char *InName, int InID, int InDay, int InMonth, int InYear, int InScore);
void PrintList (void);


/* ----------------------initializing both head and tail pointers------------------------ */
struct Student *Head = NULL;
struct Student *Tail = NULL;


/* ---------------------------------Linked List Length----------------------------------- */
int length = 0;


/* ----------------------------------------MAIN------------------------------------------ */
int main(void) {

	clock_t t1DA,t1LL,t2DA,t2LL,t3DA,t3LL;
	N=10000;
	int i;

	stdPtr = (struct Student *) malloc(N*sizeof(struct Student));

	for (i=0; i<N ; i++)
	{
		insertInTheBeginning_DA(stdPtr);
	}
	for (i=0; i<N ; i++)
	{
		InsertFirst_LL ("student1", 10, 10, 10, 10, 10);
	}

	t1DA = clock();
	insertInTheBeginning_DA(stdPtr);
	t1DA = clock() - t1DA;
	double time_taken1DA = ((double)t1DA)/CLOCKS_PER_SEC; // in seconds
	printf("Insert in the beginning in Dynamic array time taken: %*.9lf\n", 5,time_taken1DA);

	t1LL = clock();
	InsertFirst_LL ("student1", 10, 10, 10, 10, 10);
	t1LL = clock() - t1LL;
	double time_taken1LL = ((double)t1LL)/CLOCKS_PER_SEC; // in seconds

	printf("Insert in the beginning in Linked list time taken:   %*.9lf\n\n",5, time_taken1LL);

	t2DA = clock();
	insertInTheMiddle_DA(stdPtr,N/2);
	t2DA = clock() - t2DA;
	double time_taken2DA = ((double)t2DA)/CLOCKS_PER_SEC; // in seconds

	printf("Insert in the middle in Dynamic array time taken: %*.9lf\n", 5,time_taken2DA);

	t2LL = clock();
	InsertAtPos_LL (N/2,"student2", 50, 50, 50, 50, 50);
	t2LL = clock() - t2LL;
	double time_taken2LL = ((double)t2LL)/CLOCKS_PER_SEC; // in seconds

	printf("Insert in the middle in Linked list time taken:   %*.9lf\n\n",5, time_taken2LL);


	t3DA = clock();
	insertAtTheEnd_DA(stdPtr);
	t3DA = clock() - t3DA;
	double time_taken3DA = ((double)t3DA)/CLOCKS_PER_SEC; // in seconds

	printf("Insert at the end in Dynamic array time taken: %*.9lf\n", 5,time_taken3DA);

	t3LL = clock();
	InsertEnd_LL ("student3", 9, 9, 9, 9, 9);
	t3LL = clock() - t3LL;
	double time_taken3LL = ((double)t3LL)/CLOCKS_PER_SEC; // in seconds

	printf("Insert at the end in Linked list time taken:   %*.9lf\n\n", 5,time_taken3LL);


	return 0;
}

/* ----------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */
/* --------------------------------------------DYNAMIC-------------------------------------------- */
/* ---------------------------------------------ARRAY--------------------------------------------- */
/* -------------------------------------------FUNCTIONS------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */

void insertInTheBeginning_DA(struct Student *stdPtr)
{
	int i;

	for (i=0; i<N;i++)
	{
		if ((stdPtr+i)->flag != 1)
		{
			break;
		}
	}

	if (i==N)
	{
		N++;
		stdPtr = realloc(stdPtr,N*sizeof(struct Student));
	}

	for (; i>0 ;i--)
	{
		*(stdPtr+i)=*(stdPtr+i-1);
	}
	insert (stdPtr,"student1",9,9,9,9,9);
}

void insertAtTheEnd_DA(struct Student *stdPtr)
{
	int i;

	for (i=N-1; i>= 0 ;i--)
	{
		if ((stdPtr+i)->flag != 1)
		{
			break;
		}
	}

	if(i==-1)
	{
		N++;
		i++;
		stdPtr = realloc(stdPtr,N*sizeof(struct Student));
	}
	else
	{
		for (;i<N-1;i++)
		{
			*(stdPtr+i)=*(stdPtr+i+1);
		}
	}
	insert (stdPtr+N-1,"student3",50,50,50,50,50);
}

void insertInTheMiddle_DA(struct Student *stdPtr, int location)
{
	int i;

	if ((stdPtr+location-1)->flag == 1)
	{
		for (i=0; i<N;i++)
		{
			if ((stdPtr+i)->flag != 1)
			{
				break;
			}
		}

		if (i==N)
		{
			N++;
			stdPtr = realloc(stdPtr,N*sizeof(struct Student));
		}

		if (i<location-1)
		{
			for (;i<location-1;i++)
			{
				*(stdPtr+i)=*(stdPtr+i+1);
			}
		}
		else
		{
			for (; i>location-1 ;i--)
			{
				*(stdPtr+i)=*(stdPtr+i-1);
			}
		}
	}
	insert (stdPtr+(location-1),"student2",10,10,10,10,10);
}

void insert (struct Student *stdPtr,char *name_f,int ID,int year,int month,int day,int score)
{
	stdPtr->name=name_f;
	stdPtr->std_ID=ID;
	stdPtr->year=year;
	stdPtr->month=month;
	stdPtr->day=day;
	stdPtr->score_std=score;
	stdPtr->flag=1;
}

void printArray(struct Student *stdPtr)
{
	int i=0;

	for (i=0;i<N;i++)
	{
		printf("[%d] std data:\n",i);
		printf("Name: %s\n",(stdPtr+i)->name);
		printf("ID: %d\n",(stdPtr+i)->std_ID);
		printf("Birthdate: %d,%d,%d\n",(stdPtr+i)->day,(stdPtr+i)->month,(stdPtr+i)->year);
		printf("Score: %d\n\n",(stdPtr+i)->score_std);
	}
}

/* ----------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */
/* --------------------------------------------LINKED--------------------------------------------- */
/* ---------------------------------------------LIST---------------------------------------------- */
/* -------------------------------------------FUNCTIONS------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */

void InsertFirst_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore){
	struct Student *NewStudent = (struct Student *) malloc (sizeof(struct Student));
	//Assigning the wanted data to the new Student
	NewStudent->name = InName;
	NewStudent->std_ID = InID;
	NewStudent->day = InDay;
	NewStudent->month = InMonth;
	NewStudent->year = InYear;
	NewStudent->score_std = InScore;

	//Changing Head Pointer

	if (length == 0){//If the list is empty
		Head = Tail = NewStudent;
		NewStudent->next = NULL;
	}

	else{//If we already have a Student at first
		NewStudent->next = Head;
		Head = NewStudent;
	}

	length ++;

}

void InsertEnd_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore){
	struct Student *NewStudent = (struct Student *) malloc (sizeof(struct Student));

	//Assigning the wanted data to the new Student
	NewStudent->name = InName;
	NewStudent->std_ID = InID;
	NewStudent->day = InDay;
	NewStudent->month = InMonth;
	NewStudent->year = InYear;
	NewStudent->score_std = InScore;

	//Changing Tail and Head Pointers if needed
	if (length == 0){//To handle beginning the insertion at the end (list is empty)
		Head = Tail = NewStudent;
		NewStudent->next = NULL;
	}
	else{
		NewStudent->next = NULL;
		Tail->next = NewStudent;
		Tail=NewStudent;
	}

	length ++;

}

void InsertAtPos_LL (int pos,char *InName, int InID, int InDay, int InMonth, int InYear, int InScore){
	struct Student *NewStudent = (struct Student *) malloc (sizeof(struct Student));

	if (pos<0||pos>length)
		printf("Invalid Position");
	else if (pos == 0)
		InsertFirst_LL(InName, InID, InDay, InMonth, InYear, InScore);

	else if (pos==length)
		InsertEnd_LL(InName, InID, InDay, InMonth, InYear, InScore);

	else{
		struct Student *current = Head;
		//Assigning the wanted data to the new Student
		NewStudent->name = InName;
		NewStudent->std_ID = InID;
		NewStudent->day = InDay;
		NewStudent->month = InMonth;
		NewStudent->year = InYear;
		NewStudent->score_std = InScore;
		//Searching for the wanted position
		for (int i=1;i<pos;i++)
			current = current->next;

		NewStudent->next = current->next;
		current->next = NewStudent;
	}

	length ++;

}

void PrintList (void) {
	if(length == 0){
		printf("The List Is Empty\n");
	}
	else{

		struct Student *current = Head;
		printf("\n----------------PRINTING-------------------\n");

		for (int i = 0;i<=length;i++){
			printf("Student %d:\nName: %s\nID: %d\nDate of birth: %d/%d/%d\nLast year score: %d\n",i+1,current->name,current->std_ID,current->day,current->month,current->year,current->score_std);
			printf("-------------------------------------------\n");
			current = current->next;
		}
	}
}
