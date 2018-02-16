#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

int top;
int Front;

char arr[MAX];
char arr2[MAX];

bool  isEmpty();
void  push(char data);
void  push_Result(char data);
int   pop();
void  print();
bool  IsOperator(char val);
int   getPriority(char val);
void  ToPostFix(char data[]);
bool  isLeftParen(char data);


bool  isLeftParen(char data)
{
    if(data=='(' || data=='{' || data=='[')
        return true;
    else
        return false;
}

bool  isRightParen(char data)
{
    if(data==')' || data=='}' || data==']')
        return true;
    else
        return false;
}

bool isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else
        return false;
}

bool isEmpty_Result()
{
    if(Front==-1)
    {
        return true;
    }
    else
        return false;
}

int pop()
{
    top--;
}

bool IsOperator(char val)
{
    if(val=='+' || val=='-' || val=='/' || val=='*' || val=='^')
        return true;
    else
        return false;
}


void push(char data)
{
    if(isEmpty())
    {
        top=0;
    }
    arr[top]=data;

    top=top+1;
}

int getPriority(char val)
{
    if(val=='+' || val=='-')
        return 1;
    else if(val=='*' || val=='/')
        return 2;
    else
        return 3;
}

void push_Result(char data)
{
    if(isEmpty_Result())
    {
        Front=0;
    }
    arr2[Front]=data;
    Front=Front+1;
}

void print()
{
    for(int i=0; i<Front-1; i++)
    {
        printf("%c",arr2[i]);
    }
}

void ToPostFix(char data[])
{
    int i,len;
    len=strlen(data);
    for(i=0; i<len; i++)
    {

        if(!IsOperator(data[i]) && !isLeftParen(data[i]) && !isRightParen(data[i]))
        {
            push_Result(data[i]);
        }
        else if(IsOperator(data[i]) && !isLeftParen(arr[top-1]))
        {
            if(isEmpty() || getPriority(data[i])>getPriority(arr[top-1]))
            {
                push(data[i]);
            }
            else if(getPriority(data[i])<=getPriority(arr[top-1]))
            {
                while(!isEmpty())
                {
                    push_Result(arr[top-1]);

                    pop();
                }
                push(data[i]);
            }
        }
        else if(IsOperator(data[i]) && isLeftParen(arr[top-1]))
        {
            push(data[i]);
        }
        else if(isLeftParen(data[i]))
        {
            push(data[i]);
            //printf("%c ",data[i]);
        }
        else if(isRightParen(data[i]))
        {
            //printf("%c ",data[i]);
            while(!isEmpty() && !isLeftParen(arr[top-1]))
            {
                //printf("%c ",arr[top-1]);
                push_Result(arr[top-1]);
                pop();
            }
            pop();
        }

    }

    while(!isEmpty())
    {
        push_Result(arr[top-1]);
        pop();
    }
}
int main()
{
    int i,S;
    char val[MAX];
    for(i=0; i<MAX; i++)
    {
        scanf("%c",&val[i]);
    }
    ToPostFix(val);
    print();
}
// 4*8+9*2-3*4

