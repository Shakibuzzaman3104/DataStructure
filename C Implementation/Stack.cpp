#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int arr[MAX];
int top=-1;

bool isEmpty();
bool isFull();
void Insert(int data);
void pop();
void print();

bool isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else
       return false;
}

bool isFull()
{
    if(top==MAX)
    {
        return true;
    }
    else
       return false;
}

void Insert(int data)
{
    if(isFull())
    {
        printf("Stack  Overflow!!\n");
        return;
    }
    else if(isEmpty())
    {
        top=0;
    }
    arr[top]=data;
    top+=1;
}

void pop()
{
    if(isEmpty())
    {
        printf("Stack is  Empty!!\n");
        return;
    }
    else
    {
        top--;
    }

}

void print()
{
    int i;
    for(i=0;i<top;i++)
    {
        printf("%d ",arr[i]);
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
