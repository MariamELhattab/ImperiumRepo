#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//N : number of students
int N;

struct Student *stdPtr1;
struct Student *stdPtr2;
struct Student *stdPtr3;

struct Student
{
	char name[100];
	int std_ID;
	int day,month,year;
	int score_std;
	char flag;
};

int j;

void insertInTheBeginning_DA(struct Student *stdPtr);
void insertAtTheEnd_DA(struct Student *stdPtr);
void insertInTheMiddle_DA(struct Student *stdPtr, int location);
void insert (struct Student *stdPtr,char *name_f,int ID,int year,int month,int day,int score);
void showArray(struct Student *stdPtr);

#include <time.h>

int main(void) {

	N=10000;
	int i;

	stdPtr1 = (struct Student *) malloc(N*sizeof(struct Student));

	for (i=0; i<N ; i++)
	{
		insertInTheBeginning_DA(stdPtr1);
	}

	clock_t t1;
	t1 = clock();
	insertInTheBeginning_DA(stdPtr1);
	t1 = clock() - t1;
	double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

	printf("fun() took %.9f seconds to execute \n", time_taken1);

	stdPtr2 = (struct Student *) malloc(N*sizeof(struct Student));

	for (i=0; i<N ; i++)
	{
		insertInTheBeginning_DA(stdPtr2);
	}

	clock_t t2;
	t2 = clock();
	insertInTheMiddle_DA(stdPtr2,N/2);
	t2 = clock() - t2;
	double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds

	printf("fun() took %.9f seconds to execute \n", time_taken2);


	stdPtr3 = (struct Student *) malloc(N*sizeof(struct Student));
	for (i=0; i<N ; i++)
	{
		insertAtTheEnd_DA(stdPtr3);
	}
	clock_t t3;
	t3 = clock();

	insertAtTheEnd_DA(stdPtr3);

	t3 = clock() - t3;
	double time_taken3 = ((double)t3)/CLOCKS_PER_SEC; // in seconds

	printf("fun() took %.9f seconds to execute \n", time_taken3);

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

	if (i==N)
	{
		N++;
		stdPtr = realloc(stdPtr,N*sizeof(struct Student));
	}

	for (; i>0 ;i--)
	{
		*(stdPtr+i)=*(stdPtr+i-1);
	}
	insert (stdPtr,"daly",9,9,9,9,9);
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
	insert (stdPtr+N-1,"amr",50,50,50,50,50);
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
	insert (stdPtr+(location-1),"mariam",10,10,10,10,10);
}

void insert (struct Student *stdPtr,char *name_f,int ID,int year,int month,int day,int score)
{
	strcpy(stdPtr->name,name_f);
	stdPtr->std_ID=ID;
	stdPtr->year=year;
	stdPtr->month=month;
	stdPtr->day=day;
	stdPtr->score_std=score;
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

