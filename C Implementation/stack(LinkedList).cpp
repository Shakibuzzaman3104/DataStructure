#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   Node* next;
};
Node* Front;

bool isEmpty();
void Insert(int data);
void pop();
void print();

bool isEmpty()
{
    if(Front==NULL)
    {
        return true;
    }
    else
       return false;
}

Node* Newnode(int val)
{
    struct Node* newnode=(Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

void Insert(int data)
{
    struct Node* newnode=Newnode(data);
    newnode->next=Front;
    Front=newnode;
}
void pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty!!\n");
        return;
    }
    else
    {
        struct Node* temp=Front;
        Front=temp->next;
        free(temp);
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
        Insert(val);
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
    Front=NULL;
    int ch;
    while(true)
    {
        printf("1: To Push a value inside Stack\n2: To pop a value from Stack\n");
        scanf("%d",&ch);
        Selection(ch);
        printf("\n");
    }

    return 0;
}
