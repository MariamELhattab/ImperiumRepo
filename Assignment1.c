#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//N : number of students
int N=5;

struct Student
{
	char name[100];
	int std_ID;
	int day,month,year;
	int score_std;
	char flag;
    struct Student *next;
};

void insertInTheBeginning_DA(struct Student *stdPtr);
void insertAtTheEnd_DA(struct Student *stdPtr);
void insertInTheMiddle_DA(struct Student *stdPtr, int location);
void insert (struct Student *stdPtr);
void showArray(struct Student *stdPtr);
void InsertFirst_LL (void);
void InsertEnd_LL (void);
void InsertAtPos_LL (int pos);
void PrintList (void);

//initializing both head and tail pointers
struct Student *Head = NULL;
struct Student *Tail = NULL;

int length = 0;//Variable to know the size of the list

int main()
{
	printf("Welcome\n");

	struct Student *stdPtr;

	stdPtr = (struct Student *) malloc(N*sizeof(struct Student));

	return 0;
}


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

	assert(i!=N);

	for (; i>0 ;i--)
	{
		*(stdPtr+i)=*(stdPtr+i-1);
		(stdPtr+i-1)->flag=0;
	}
	insert (stdPtr);
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

	assert(i!=-1);

	for (;i<N-1;i++)
	{
		*(stdPtr+i)=*(stdPtr+i+1);
		(stdPtr+i+1)->flag=0;
	}
	insert (stdPtr+N-1);
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

		assert(i!=N);

		if (i<location-1)
		{
			for (;i<N-1;i++)
			{
				*(stdPtr+i)=*(stdPtr+i+1);
				(stdPtr+i+1)->flag=0;
			}
		}
		else
		{
			for (; i>0 ;i--)
			{
				*(stdPtr+i)=*(stdPtr+i-1);
				(stdPtr+i-1)->flag=0;
			}
		}
	}
	insert (stdPtr+(location-1));
}

void insert (struct Student *stdPtr)
{

	printf("Enter the student name: ");
	fflush(stdin); fflush(stdout);
	gets(stdPtr->name);

	printf("Enter the student ID: ");
	fflush(stdout);
	scanf("%d",&(stdPtr->std_ID));

	printf("Enter the student birth date\nyear: ");
	fflush(stdout);
	scanf("%d",&stdPtr->year);
	printf("month: ");
	fflush(stdout);
	scanf("%d",&stdPtr->month);
	printf("day: ");
	fflush(stdout);
	scanf("%d",&stdPtr->day);

	printf("Enter the student score: ");
	fflush(stdout);
	scanf("%d",&stdPtr->score_std);

	stdPtr->flag=1;
}

void showArray(struct Student *stdPtr)
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

void InsertFirst_LL (void){
    struct Student *NewStudent = (struct Student *) malloc (sizeof(struct Student));
    //Assigning the wanted data to the new Student
    printf("Enter the name: ");
    fflush(stdin);
    gets(NewStudent->name);
    printf("Enter the ID: ");
    scanf("%d",&NewStudent->std_ID);
    printf("Enter the day: ");
    scanf("%d",&NewStudent->day);
    printf("Enter the month: ");
    scanf("%d",&NewStudent->month);
    printf("Enter the year: ");
    scanf("%d",&NewStudent->year);
    printf("Enter the score: ");
    scanf("%d",&NewStudent->score_std);
        if (length == 0){//If the list is empty
            Head = NewStudent;
            NewStudent->next = NULL;
        }

        else{//If we already have a Student at first
            NewStudent->next = Head;
            Head = NewStudent;
        }
    length ++;
}

void InsertEnd_LL (void){
    struct Student *NewStudent = (struct Student *) malloc (sizeof(struct Student));
    //Assigning the wanted data to the new Student
    printf("Enter the name: ");
    fflush(stdin);
    gets(NewStudent->name);
    printf("Enter the ID: ");
    scanf("%d",&NewStudent->std_ID);
    printf("Enter the day: ");
    scanf("%d",&NewStudent->day);
    printf("Enter the month: ");
    scanf("%d",&NewStudent->month);
    printf("Enter the year: ");
    scanf("%d",&NewStudent->year);
    printf("Enter the score: ");
    scanf("%d",&NewStudent->score_std);

    if (length == 0){//To handle beginning the insertion at the end (list is empty)
        Head = Tail = NewStudent;
        NewStudent->next = NULL;
    }
    else if (Tail==NULL){ //To handle inserting multiple Students at first then inserting at the end
        struct Student *current = Head;
        while (current->next != NULL)
            current = current->next;
        Tail = NewStudent;
        current->next = NewStudent;
    }
    else{
        NewStudent->next = NULL;
        Tail->next = NewStudent;
        Tail=NewStudent;
    }
    length ++;
}

void InsertAtPos_LL (int pos){
    struct Student *NewStudent = (struct Student *) malloc (sizeof(struct Student));

    if (pos<0||pos>length)
            printf("Invalid Position");
    else if (pos == 0)
            InsertFirst_LL();

    else if (pos==length)
            InsertEnd_LL();

    else{
            struct Student *current = Head;
            //Assigning the wanted data to the new Student
            printf("Enter the name: ");
            fflush(stdin);
            gets(NewStudent->name);
            printf("Enter the ID: ");
            scanf("%d",&NewStudent->std_ID);
            printf("Enter the day: ");
            scanf("%d",&NewStudent->day);
            printf("Enter the month: ");
            scanf("%d",&NewStudent->month);
            printf("Enter the year: ");
            scanf("%d",&NewStudent->year);
            printf("Enter the score: ");
            scanf("%d",&NewStudent->score_std);
            //Searching for the wanted position
            for (int i=1;i<pos;i++)
                current = current->next;

            NewStudent->next = current->next;
            current->next = NewStudent;
    }
    length ++;
}

void PrintList (void) {
    struct Student *current = Head;
    printf("\n----------------PRINTING-------------------\n");
    for (int i = 0;i<=length;i++){
        printf("Student %d:\nName: %s\nID: %d\nDate of birth: %d/%d/%d\nLast year score: %d\n",i+1,current->name,current->std_ID,current->day,current->month,current->year,current->score_std);
        printf("-------------------------------------------\n");
        current = current->next;
    }
}
