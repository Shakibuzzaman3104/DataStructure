#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int arr[MAX];
int Front=-1,Rear=-1;

bool IsEmpty();
bool IsFull();
void push(int val);
void pop();
void print();

bool IsEmpty()
{
    if(Front==-1 && Rear==-1)
    {
        return true;
    }
    else
        return false;
}

bool IsFull()
{
    if((Rear+1)%MAX == Front)
    {
        return true;
    }
    else
        return false;
}

void print()
{
    if(IsEmpty()==true)
    {
        printf("No value inside QUEUE\n");
        return;
    }
    else
    {
        printf("\nQueue is: ");
        for(int i=Front; i<=Rear; i++)
        {
            printf("%d ",arr[i]);
        }
    }
}

void push(int val)
{
    if(IsFull()==true)
    {
        printf("Queue is Full!!");
        return;
    }
    else if(IsEmpty())
    {
        Front=Rear=0;
    }
    else
    {
        Rear+=1;
    }
    arr[Rear]=val;
}

void pop()
{
    if(IsEmpty()==true)
    {
        printf("Queue is empty!!");
        return;
    }
    else if(Front==Rear)
    {
        Front=Rear=-1;
    }
    else
    {
      // Front = (Front+1)%MAX;
       Front +=1;
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
        push(val);
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
        printf("1: To Push a value inside Queue\n2: To pop a value from QUEUE\n");
        scanf("%d",&ch);
        Selection(ch);
        printf("\n");
    }

    return 0;
}

