#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    Node* next;
};
Node* Front;
Node* Rear;

bool IsEmpty();
void Push(int val);
void pop();
void print();

struct Node* Newnode(int x)

{
    struct Node* newnode=(Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void Push(int val)
{
    struct Node* newnode=Newnode(val);

    if(Front==NULL && Rear==NULL)
    {
        Front=newnode;
        Rear=newnode;
        return;
    }

    else
    {
        struct Node* temp=Front;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        Rear=temp;
    }

}

void pop()
{
    struct Node* temp=Front;
    if(Front==NULL && Rear==NULL)
    {
        printf("Queue Is Empty\n");
        return;
    }
    else if(Front==Rear)
    {
        Front=NULL;
        Rear=NULL;
        return;
    }
    else
    {
        Front=temp->next;
        free(temp);
        return;
    }
}

void print()
{
    struct Node* temp=Front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void Selection(int ch)
{
    int i,val;
    switch(ch)
    {
    case 1:
        printf("\nPlease Enter a value:");
        scanf("%d",&val);
        Push(val);
        print();
        break;
    case 2:
        pop();
        print();
        break;
    default:
        printf("please Enter a correct  value");
        break;
    }

}

int main()
{
    Front=Rear=NULL;
    int ch;
    while(true)
    {
        printf("\t1: To Push a value inside Queue\t\t2: To pop a value from QUEUE\n");
        scanf("%d",&ch);
        Selection(ch);
        printf("\n");
    }

    return 0;
}




