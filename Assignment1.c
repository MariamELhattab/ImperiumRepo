/******************************************************************************
 *
 * Assignment 1
 *
 * File Name: Assignment1.c
 *
 * Description: Students data storing using dynamic arrays and linked lists
 *
 * Author: Ahmed Mamdouh Ahmed Aboudief			Sec:1		BN:21
 *         Amr Maged Hassan Taha                Sec:3		BN:19
 *         Mariam Amr Youssef ElHattab			Sec:4		BN:10
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* N : number of students */
int N;

/* Variable to know the size of the Linked list */
int length = 0;

/* Structure to carry each student data */
struct Student
{
	/* Student data */
	char name[100];
	int std_ID;
	int day,month,year;
	int score_std;

	/* Flag to determine wether the location is empty or not */
	char flag;

	/* Next pointer for Linked list */
	struct Student *next;
};

/* Initializing both head and tail pointers */
struct Student *Head = NULL;
struct Student *Tail = NULL;

/*******************************************************************************
 *                      Functions Declarations                                 *
 *******************************************************************************/

void insertInTheBeginning_DA(struct Student *stdPtr);
void insertAtTheEnd_DA(struct Student *stdPtr);
void insertInTheMiddle_DA(struct Student *stdPtr, int location);
void insert (struct Student *stdPtr);
void showArray(struct Student *stdPtr);
void InsertFirst_LL (void);
void InsertEnd_LL (void);
void InsertAtPos_LL (int pos);
void PrintList (void);

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 
int main()
{
	printf("Welcome\n");

	struct Student *stdPtr;

	stdPtr = (struct Student *) malloc(N*sizeof(struct Student));

	return 0;
}


void insertInTheBeginning_DA(struct Student *stdPtr)
{
	/* i : Counter for loops */
	int i;

	/* Making sure there is an empty slot in the dynamic array */
	for (i=0; i<N;i++)
	{
		if ((stdPtr+i)->flag != 1)
		{
			break;
		}
	}

	/* If there is no space for additional student the program will assert */
	assert(i!=N);

	/* Shifting from the last position to make room in the beginning for insertion */
	for (; i>0 ;i--)
	{
		*(stdPtr+i)=*(stdPtr+i-1);
		(stdPtr+i-1)->flag=0;
	}

	insert (stdPtr);
}

void insertAtTheEnd_DA(struct Student *stdPtr)
{
	/* i : Counter for loops */
	int i;

	/* Making sure there is an empty slot in the dynamic array */
	for (i=N-1; i>= 0 ;i--)
	{
		if ((stdPtr+i)->flag != 1)
		{
			break;
		}
	}

	/* If there is no space for additional student the program will assert */
	assert(i!=-1);

	/* Shifting from the first position to make room at the end for insertion */
	for (;i<N-1;i++)
	{
		*(stdPtr+i)=*(stdPtr+i+1);
		(stdPtr+i+1)->flag=0;
	}

	insert (stdPtr+N-1);
}

void insertInTheMiddle_DA(struct Student *stdPtr, int location)
{
	/* i : Counter for loops */
	int i;

	/* If the required location is not empty we should make room for it */
	if ((stdPtr+location-1)->flag == 1)
	{
		/* Making sure there is an empty slot in the dynamic array */
		for (i=0; i<N;i++)
		{
			if ((stdPtr+i)->flag != 1)
			{
				break;
			}
		}

		/* If there is no space for additional student the program will assert */
		assert(i!=N);

		/* If the empty slot is before the required location we should shift to the left */
		if (i<location-1)
		{
			for (;i<N-1;i++)
			{
				*(stdPtr+i)=*(stdPtr+i+1);
				(stdPtr+i+1)->flag=0;
			}
		}
		/* If the empty slot is after the required location we should shift to the right */
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
	/* Assigning the wanted data to the new Student */

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
	/* i : Counter for loops */
	int i;

	for (i=0;i<N;i++)
	{
		printf("[%d] std data:\n",i);
		printf("Name: %s\n",(stdPtr+i)->name);
		printf("ID: %d\n",(stdPtr+i)->std_ID);
		printf("Birthdate: %d,%d,%d\n",(stdPtr+i)->day,(stdPtr+i)->month,(stdPtr+i)->year);
		printf("Score: %d\n\n",(stdPtr+i)->score_std);
	}
}

void InsertFirst_LL (void)
{
	struct Student *NewStudent = (struct Student *) malloc (sizeof(struct Student));

	/* Assigning the wanted data to the new Student */

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

	if (length == 0)
	{
		/* If the list is empty */
		Head = NewStudent;
		NewStudent->next = NULL;
	}
	else
	{
		/* If we already have a Student at first */
		NewStudent->next = Head;
		Head = NewStudent;
	}
	length ++;
}

void InsertEnd_LL (void)
{
	struct Student *NewStudent = (struct Student *) malloc (sizeof(struct Student));

	/* Assigning the wanted data to the new Student */

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

	if (length == 0)
	{
		/* To handle beginning the insertion at the end (list is empty) */
		Head = Tail = NewStudent;
		NewStudent->next = NULL;
	}
	else if (Tail==NULL)
	{ 
		/* To handle inserting multiple Students at first then inserting at the end */
		struct Student *current = Head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		Tail = NewStudent;
		current->next = NewStudent;
	}
	else
	{
		NewStudent->next = NULL;
		Tail->next = NewStudent;
		Tail=NewStudent;
	}

	length ++;
}

void InsertAtPos_LL (int pos)
{
	struct Student *NewStudent = (struct Student *) malloc (sizeof(struct Student));

	if (pos<0||pos>length)
	{
		printf("Invalid Position");
	}
	else if (pos == 0)
	{
		InsertFirst_LL();
	}
	else if (pos==length)
	{
		InsertEnd_LL();
	}
	else
	{
		struct Student *current = Head;

		/* Assigning the wanted data to the new Student */

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

		/* Searching for the wanted position */
		for (int i=1;i<pos;i++)
		{
			current = current->next;
		}

		NewStudent->next = current->next;
		current->next = NewStudent;
	}

	length ++;
}

void PrintList (void) 
{
	/* i : Counter for loops */
	int i;

	struct Student *current = Head;

	printf("\n----------------PRINTING-------------------\n");

	for ( i=0; i<=length ; i++)
	{
		printf("Student %d:\nName: %s\nID: %d\nDate of birth: %d/%d/%d\nLast year score: 
				%d\n",i+1,current->name,current->std_ID,current->day,current->month,current->year,current->score_std);

				printf("-------------------------------------------\n");

		current = current->next;
	}
}
