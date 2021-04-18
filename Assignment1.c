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
};

void insertInTheBeginning_DA(struct Student *stdPtr);
void insertAtTheEnd_DA(struct Student *stdPtr);
void insertInTheMiddle_DA(struct Student *stdPtr, int location);
void insert (struct Student *stdPtr);
void showArray(struct Student *stdPtr);

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

