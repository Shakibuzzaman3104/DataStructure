#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;

void insertHead(int x);
void insertTail(int x);
void removes(int x);
void insertBetween(int x,int v);
void print();
void printReverse();

struct Node* newNode(int x)
{
    struct Node* newnode=(Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->prev=NULL;
    newnode->next=NULL;

    return newnode;
}

void insertHead(int x)
{
    struct Node* newnode=newNode(x);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}
void insertTail(int x)
{
    struct Node* newnode=(Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head==NULL)
    {
        head=newnode;
        return;
    }
    else
    {
        struct Node* temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }

}

void print()
{
    struct Node* temp=head;
    printf("Print in normal Order\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void printReverse()
{

    struct Node* temp=head;
    printf("Print in reverse Order\n");
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n\n");
}

void removes(int x)
{
    int i=0;
    struct Node* temp=head;

    for(int i=0;i<x;i++)
    {
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

void insertBetween(int x,int v)
{
     struct Node* newnode=(Node*)malloc(sizeof(struct Node));
     newnode->data=v;
     newnode->next=NULL;
     newnode->prev=NULL;
     struct Node* temp=head;
     int i;
     for(i=0;i<x;i++)
     {
        temp=temp->next;
     }
     temp->prev=newnode;
     newnode->next=temp;
     temp->prev->next=newnode;
     newnode->prev=temp->prev;
}

int main()
{
    head=NULL;
    printf("Insert at the Head of the List:\n\n");
    printf("How many Numbers ? :");
    int n,i,in;
    scanf("%d",&n);
    int c=1;
    for(i=0; i<n; i++)
    {
        printf("Enter number at %d position: ",c);
        scanf("%d",&in);
        insertHead(in);
        c++;
    }
    c=1;

    printf("\n");
    print();
    printf("\n");
    printReverse();

    printf("Insert at the end of the List:\n\n");
    printf("How many Numbers ? :");
    int s,ss;
    scanf("%d",&s);
    for(i=0; i<s; i++)
    {
        printf("Enter number at %d position: ",c);
        scanf("%d",&ss);
        insertTail(ss);
        c++;

    }

    printf("\n");
    print();
    printf("\n");
    printReverse();

    printf("Enter a position to remove\n");
    int x;
    scanf("%d",&x);
    removes(x);
    print();

    printf("Enter a Position and value to insert\n");
    int p,v;
    scanf("%d %d",&p,&v);
    insertBetween(p,v);
    print();
    return 0;
}


