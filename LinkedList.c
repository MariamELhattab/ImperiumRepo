#include <stdio.h>
#include <stdlib.h>

struct node {
    char name[30];
    int ID;
    int day,month,year;
    int score;
    struct node *next;
};
//initializing both head and tail pointers
struct node *Head = NULL;
struct node *Tail = NULL;

int length = 0;//Variable to know the size of the list

void InsertFirst (void){
    struct node *NewNode = (struct node *) malloc (sizeof(struct node));
    //Assigning the wanted data to the new node
    printf("Enter the name: ");
    fflush(stdin);
    gets(NewNode->name);
    printf("Enter the ID: ");
    scanf("%d",&NewNode->ID);
    printf("Enter the day: ");
    scanf("%d",&NewNode->day);
    printf("Enter the month: ");
    scanf("%d",&NewNode->month);
    printf("Enter the year: ");
    scanf("%d",&NewNode->year);
    printf("Enter the score: ");
    scanf("%d",&NewNode->score);
        if (length == 0){//If the list is empty
            Head = NewNode;
            NewNode->next = NULL;
        }

        else{//If we already have a node at first
            NewNode->next = Head;
            Head = NewNode;
        }
    length ++;
}

void InsertEnd (void){
    struct node *NewNode = (struct node *) malloc (sizeof(struct node));
    //Assigning the wanted data to the new node
    printf("Enter the name: ");
    fflush(stdin);
    gets(NewNode->name);
    printf("Enter the ID: ");
    scanf("%d",&NewNode->ID);
    printf("Enter the day: ");
    scanf("%d",&NewNode->day);
    printf("Enter the month: ");
    scanf("%d",&NewNode->month);
    printf("Enter the year: ");
    scanf("%d",&NewNode->year);
    printf("Enter the score: ");
    scanf("%d",&NewNode->score);

    if (length == 0){//To handle beginning the insertion at the end (list is empty)
        Head = Tail = NewNode;
        NewNode->next = NULL;
    }
    else if (Tail==NULL){ //To handle inserting multiple nodes at first then inserting at the end
        struct node *current = Head;
        while (current->next != NULL)
            current = current->next;
        Tail = NewNode;
        current->next = NewNode;
    }
    else{
        NewNode->next = NULL;
        Tail->next = NewNode;
        Tail=NewNode;
    }
    length ++;
}

void InsertAtPos (int pos){
    struct node *NewNode = (struct node *) malloc (sizeof(struct node));

    if (pos<0||pos>length)
            printf("Invalid Position");
    else if (pos == 0)
            InsertFirst();

    else if (pos==length)
            InsertEnd();

    else{
            struct node *current = Head;
            //Assigning the wanted data to the new node
            printf("Enter the name: ");
            fflush(stdin);
            gets(NewNode->name);
            printf("Enter the ID: ");
            scanf("%d",&NewNode->ID);
            printf("Enter the day: ");
            scanf("%d",&NewNode->day);
            printf("Enter the month: ");
            scanf("%d",&NewNode->month);
            printf("Enter the year: ");
            scanf("%d",&NewNode->year);
            printf("Enter the score: ");
            scanf("%d",&NewNode->score);
            //Searching for the wanted position
            for (int i=1;i<pos;i++)
                current = current->next;

            NewNode->next = current->next;
            current->next = NewNode;
    }
    length ++;
}

void PrintList (void) {
    struct node* current = Head;
    printf("\n----------------PRINTING-------------------\n");
    for (int i = 0;i<=length;i++){
        printf("Node %d:\nName: %s\nID: %d\nDate of birth: %d/%d/%d\nLast year score: %d\n",i+1,current->name,current->ID,current->day,current->month,current->year,current->score);
        printf("-------------------------------------------\n");
        current = current->next;
    }
}

int main()
{
    return 0;
}
