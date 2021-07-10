#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//N : number of students
int N;

/* ---------------------------------Defining Structure--------------------------------- */
struct Student
{
	char *name;
	int std_ID;
	int day,month,year;
	int score_std;
};

struct StudentDA
{
	struct Student stdData;
	char flag;
};

struct StudentLL
{
	struct Student stdData;
	struct StudentLL *next;
};

struct Student *stdPtr;
struct StudentDA *stdPtrDA;
struct StudentLL *stdPtrLL;

/* -------------------------------Dynamic Array Functions-------------------------------- */
void insertInTheBeginning_DA(struct StudentDA *stdPtrDA);
void insertAtTheEnd_DA(struct StudentDA *stdPtrDA);
void insertInTheMiddle_DA(struct StudentDA *stdPtrDA, int location);
void insert (struct StudentDA *stdPtrDA,char *name_f,int ID,int year,int month,int day,int score);
void printArray(struct StudentDA *stdPtrDA);


/* --------------------------------Linked List Functions-------------------------------- */
void InsertFirst_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore);
void InsertEnd_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore);
void InsertAtPos_LL (int pos,char *InName, int InID, int InDay, int InMonth, int InYear, int InScore);
void PrintList (void);


/* ----------------------initializing both head and tail pointers------------------------ */
struct StudentLL *Head = NULL;
struct StudentLL *Tail = NULL;


/* ---------------------------------Linked List Length----------------------------------- */
int length = 0;


/* ----------------------------------------MAIN------------------------------------------ */
int main(void) {

	puts ("Hello, welcome on board :)\n");

	printf("Size of structure: %lu\n",(long unsigned int)sizeof(struct Student));
	printf("Size of node: %lu\n\n",(long unsigned int)sizeof(struct StudentLL));

	clock_t t1DA,t1LL,t2DA,t2LL,t3DA,t3LL;
	double time_taken1DA,time_taken2DA,time_taken3DA;
	double time_taken1LL,time_taken2LL,time_taken3LL;
	N=10;
	int i;

	stdPtrDA = (struct StudentDA *) malloc(N*sizeof(struct StudentDA));

	for (i=0; i<N ; i++)
	{
		insertInTheBeginning_DA(stdPtrDA);
	}

	t1DA = clock();
	insertInTheBeginning_DA(stdPtrDA);
	t1DA = clock() - t1DA;
	time_taken1DA = ((double)t1DA)/CLOCKS_PER_SEC; // in seconds
	printf("Insert in the beginning in Dynamic array time taken: %.9f\n",time_taken1DA);

	t2DA = clock();
	insertInTheMiddle_DA(stdPtrDA,N/2);
	t2DA = clock() - t2DA;
	time_taken2DA = ((double)t2DA)/CLOCKS_PER_SEC; // in seconds
	printf("Insert in the middle in Dynamic array time taken: %.9f\n",time_taken2DA);

	t3DA = clock();
	insertAtTheEnd_DA(stdPtrDA);
	t3DA = clock() - t3DA;
	time_taken3DA = ((double)t3DA)/CLOCKS_PER_SEC; // in seconds
	printf("Insert at the end in Dynamic array time taken: %.9f\n",time_taken3DA);

	free(stdPtrDA);

	stdPtrLL = (struct StudentLL *) malloc(N*sizeof(struct StudentLL));

	for (i=0; i<N ; i++)
	{
		InsertFirst_LL ("student1", 1, 1, 1, 1, 1);
	}

	t1LL = clock();
	InsertFirst_LL ("student1", 1, 1, 1, 1, 1);
	t1LL = clock() - t1LL;
	time_taken1LL = ((double)t1LL)/CLOCKS_PER_SEC; // in seconds
	printf("\nInsert in the beginning in Linked list time taken: %.9f\n", time_taken1LL);

	t2LL = clock();
	InsertAtPos_LL (N/2,"student2", 2, 2, 2, 2, 2);
	t2LL = clock() - t2LL;
	time_taken2LL = ((double)t2LL)/CLOCKS_PER_SEC; // in seconds
	printf("Insert in the middle in Linked list time taken: %.9f\n", time_taken2LL);

	t3LL = clock();
	InsertEnd_LL ("student3", 3, 3, 3, 3, 3);
	t3LL = clock() - t3LL;
	time_taken3LL = ((double)t3LL)/CLOCKS_PER_SEC; // in seconds
	printf("Insert at the end in Linked list time taken: %.9f\n",time_taken3LL);

	return 0;
}

/* ----------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */
/* --------------------------------------------DYNAMIC-------------------------------------------- */
/* ---------------------------------------------ARRAY--------------------------------------------- */
/* -------------------------------------------FUNCTIONS------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */

void insertInTheBeginning_DA(struct StudentDA *stdPtrDA)
{
	int i;
	if ((stdPtrDA)->flag == 1)
	{
		for (i=0; i<N;i++)
		{
			if ((stdPtrDA+i)->flag != 1)
			{
				break;
			}
		}
		if (i==N)
		{
			N++;
			stdPtrDA = (struct StudentDA *) realloc(stdPtrDA,N*sizeof(struct StudentDA));
		}

		for (; i>0 ;i--)
		{
			*(stdPtrDA+i)=*(stdPtrDA+i-1);
		}
	}
	insert (stdPtrDA,"student1",1,1,1,1,1);
}

void insertAtTheEnd_DA(struct StudentDA *stdPtrDA)
{
	int i;
	if ((stdPtrDA+N-1)->flag == 1)
	{
		for (i=N-1; i>= 0 ;i--)
		{
			if ((stdPtrDA+i)->flag != 1)
			{
				break;
			}
		}

		if(i==-1)
		{
			N++;
			i++;
			stdPtrDA = (struct StudentDA *)realloc(stdPtrDA,N*sizeof(struct StudentDA));
		}
		else
		{
			for (;i<N-1;i++)
			{
				*(stdPtrDA+i)=*(stdPtrDA+i+1);
			}
		}
	}
	insert (stdPtrDA+N-1,"student3",4,4,4,4,4);
}

void insertInTheMiddle_DA(struct StudentDA *stdPtrDA, int location)
{
	int i;

	if (location<1||location>N)
	{
		printf("Invalid Position\n");
		return;
	}
	if ((stdPtrDA+location-1)->flag == 1)
	{
		for (i=0; i<N;i++)
		{
			if ((stdPtrDA+i)->flag != 1)
			{
				break;
			}
		}

		if (i==N)
		{
			N++;
			stdPtrDA = (struct StudentDA *)realloc(stdPtrDA,N*sizeof(struct StudentDA));
		}

		if (i<location-1)
		{
			for (;i<location-1;i++)
			{
				*(stdPtrDA+i)=*(stdPtrDA+i+1);
			}
		}
		else
		{
			for (; i>location-1 ;i--)
			{
				*(stdPtrDA+i)=*(stdPtrDA+i-1);
			}
		}
	}
	insert (stdPtrDA+(location-1),"student2",2,2,2,2,2);
}

void insert (struct StudentDA *stdPtrDA,char *name_f,int ID,int year,int month,int day,int score)
{
	stdPtrDA->stdData.name=name_f;
	stdPtrDA->stdData.std_ID=ID;
	stdPtrDA->stdData.year=year;
	stdPtrDA->stdData.month=month;
	stdPtrDA->stdData.day=day;
	stdPtrDA->stdData.score_std=score;
	stdPtrDA->flag=1;
}

void printArray(struct StudentDA *stdPtrDA)
{
	int i=0;

	for (i=0;i<N;i++)
	{
		fflush(stdout);

		printf("[%d] std data:\t",i);
		printf("Name: %s\t",(stdPtrDA+i)->stdData.name);
		printf("ID: %d\t",(stdPtrDA+i)->stdData.std_ID);
		printf("Birthdate: %d,%d,%d\t",(stdPtrDA+i)->stdData.day,(stdPtrDA+i)->stdData.month,(stdPtrDA+i)->stdData.year);
		printf("Score: %d\n",(stdPtrDA+i)->stdData.score_std);

	}
	puts("=========================================================");
}

/* ----------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */
/* --------------------------------------------LINKED--------------------------------------------- */
/* ---------------------------------------------LIST---------------------------------------------- */
/* -------------------------------------------FUNCTIONS------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------- */

void InsertFirst_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore){
	struct StudentLL *NewStudentLL = (struct StudentLL *) malloc (sizeof(struct StudentLL));
	//Assigning the wanted data to the new Student
	NewStudentLL->stdData.name = InName;
	NewStudentLL->stdData.std_ID = InID;
	NewStudentLL->stdData.day = InDay;
	NewStudentLL->stdData.month = InMonth;
	NewStudentLL->stdData.year = InYear;
	NewStudentLL->stdData.score_std = InScore;

	//Changing Head Pointer

	if (length == 0){//If the list is empty
		Head = Tail = NewStudentLL;
		NewStudentLL->next = NULL;
	}

	else{//If we already have a Student at first
		NewStudentLL->next = Head;
		Head = NewStudentLL;
	}

	length ++;

}

void InsertEnd_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore){
	struct StudentLL *NewStudentLL = (struct StudentLL *) malloc (sizeof(struct StudentLL));

	//Assigning the wanted data to the new Student
	NewStudentLL->stdData.name = InName;
	NewStudentLL->stdData.std_ID = InID;
	NewStudentLL->stdData.day = InDay;
	NewStudentLL->stdData.month = InMonth;
	NewStudentLL->stdData.year = InYear;
	NewStudentLL->stdData.score_std = InScore;

	//Changing Tail and Head Pointers if needed
	if (length == 0){//To handle beginning the insertion at the end (list is empty)
		Head = Tail = NewStudentLL;
		NewStudentLL->next = NULL;
	}
	else{
		NewStudentLL->next = NULL;
		Tail->next = NewStudentLL;
		Tail=NewStudentLL;
	}

	length ++;

}

void InsertAtPos_LL (int pos,char *InName, int InID, int InDay, int InMonth, int InYear, int InScore){
	struct StudentLL *NewStudentLL = (struct StudentLL *) malloc (sizeof(struct StudentLL));

	if (pos<0||pos>length)
		printf("Invalid Position");
	else if (pos == 0)
		InsertFirst_LL(InName, InID, InDay, InMonth, InYear, InScore);

	else if (pos==length)
		InsertEnd_LL(InName, InID, InDay, InMonth, InYear, InScore);

	else{
		struct StudentLL *current = Head;
		//Assigning the wanted data to the new Student
		NewStudentLL->stdData.name = InName;
		NewStudentLL->stdData.std_ID = InID;
		NewStudentLL->stdData.day = InDay;
		NewStudentLL->stdData.month = InMonth;
		NewStudentLL->stdData.year = InYear;
		NewStudentLL->stdData.score_std = InScore;
		//Searching for the wanted position
		for (int i=1;i<pos;i++)
			current = current->next;

		NewStudentLL->next = current->next;
		current->next = NewStudentLL;
	}

	length ++;

}

void PrintList (void) {
	if(length == 0){
		printf("The List Is Empty\n");
	}
	else{

		struct StudentLL *current = Head;
		printf("\n----------------PRINTING-------------------\n");

		for (int i = 0;i<=length;i++){
			printf("Student %d:\nName: %s\nID: %d\nDate of birth: %d/%d/%d\nLast year score: %d\n",i+1,current->stdData.name,current->stdData.std_ID,current->stdData.day,current->stdData.month,current->stdData.year,current->stdData.score_std);
			printf("-------------------------------------------\n");
			current = current->next;
		}
	}
}
