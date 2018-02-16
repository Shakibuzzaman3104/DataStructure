#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *next=NULL;
};
  struct Node *head=NULL;
  struct Node *array;

void print();
void inserts(int x);
void removes(int x);
void between(int p,int v);
void insertEnd(int v);

void inserts(int x)
{
   printf("Inserted : ");
    Node* temp=new Node();
    temp->data=x;
    temp->next=head;
    head=temp;

}

void insertEnd(int v)
{

    Node* newnode=new Node();

    newnode->data=v;
    newnode->next=NULL;


    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct Node* temp2=head;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=newnode;
    }

}

void print()
{
    printf("\n");
    Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void between(int p,int v)
{
    int i;

    Node* temp3=(Node*)malloc(sizeof(struct Node));
    temp3->data=v;
    struct Node* temp1=head;
    for(i=0;i<p-2;i++)
    {
        temp1=temp1->next;
    }
    struct Node* temp2=temp1->next;
    temp1->next=temp3;
    temp3->next=temp2;
    print();
}

void removes (int x)
{
    int i;
     Node* temp1=head;

    if(x==1)
    {
        head=temp1->next;
        free(temp1);
        print();
        return;
    }

    for(int i=0; i<x-2; i++)
    {
        temp1=temp1->next;
    }
    Node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);

    print();
}

int main()
{
    head=NULL;

    printf("How many Numbers ? :\n");
    int n,i,in;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("Enter a number: \n");
        scanf("%d",&in);
        inserts(in);
        print();
    }

    printf("Insert at the end of the List:\n");
    printf("Please Enter list size: ");
    int s,ss;
    scanf("%d",&s);
    for(i=0; i<s; i++)
    {
        printf("Enter a number: \n");
        scanf("%d",&ss);
        insertEnd(ss);
        print();
    }

    printf("Enter a position to remove\n");
    int x;
    scanf("%d",&x);
    removes(x);

    printf("Enter a Position and value to insert\n");
    int p,v;
    scanf("%d %d",&p,&v);
    between(p,v);
    return 0;
}
