#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Student
{
	char name[100];
	int std_ID;
	int day,month,year;
	int score_std;
	char flag;
    struct Student *next;
};

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
    return 0;
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

    //Changing Head Pointer

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

    //Changing Tail and Head Pointers if needed
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
