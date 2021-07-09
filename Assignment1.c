#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Student
{
	char *name;
	int std_ID;
	int day,month,year;
	int score_std;
	char flag;
    struct Student *next;
};

void InsertFirst_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore);
void InsertEnd_LL (char *InName, int InID, int InDay, int InMonth, int InYear, int InScore);
void InsertAtPos_LL (int pos,char *InName, int InID, int InDay, int InMonth, int InYear, int InScore);
void PrintList (void);

//initializing both head and tail pointers
struct Student *Head = NULL;
struct Student *Tail = NULL;

int length = 0;//Variable to know the size of the list

int main()
{
/*Driver Program To Test Linked List Part*/
/*Driver Program To Test Linked List Part*/
    char choice;
                    int pos = 0;

    while(1){
    printf("\nEnter:\n1 To Insert At First\n2 To Insert At The End\n3 To Insert At The Position You Want\n4 To Print The List\n5 To Exit\nChoice: ");
    fflush(stdin);
    scanf("%c", &choice);

        switch (choice){
            case '1':
                InsertFirst_LL("AMR FIRST",1,1,1,1,1);
                break;
            case '2':
                InsertEnd_LL("AMR END",1,1,1,1,1);
                break;
            case '3':
                printf("\nEnter The Position: ");
                scanf("%d",&pos);
                InsertAtPos_LL(pos,"AMR POS",1,1,1,1,1);
                break;
            case '4':
                PrintList();
                break;
            case '5':
                return 0;
            default:
                printf("\nInvalid Choice\n");
                break;
        }
    }    }

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
