#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 6

char arr[MAX];
int top=-1;

bool isEmpty();
void push(char paren[]);
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
void pop()
{
    top--;
    if(top==0)
    {
        top=-1;
    }
}
void push(char data)
{
    int i;
    if(isEmpty())
    {
        top=0;
    }
    arr[top]=data;
   // printf("%c",arr[top]);
    top=top+1;
}

char Pair()
{
    if(arr[top-1]=='(')
    {
        return ')';
    }
    else if(arr[top-1]=='{')
    {
        return '}';
    }
    else if(arr[top-1]=='[')
        return ']';
}

bool Check(char paren[])
{
    int i;
    int len=strlen(paren);
    for(i=0; i<len; i++)
    {
        if(paren[i]=='(' || paren[i]=='{' || paren[i]=='[')
        {
            char data=paren[i];
            push(data);
        }

        else if(paren[i]==')' || paren[i]=='}' || paren[i]==']')
        {
            char par=Pair();
            if(isEmpty() || paren[i]!=par)
            {
                return false;
            }
            else
                pop();
        }
    }

    if(isEmpty())
    {
        return true;
    }
    else
        return false;
}

int main()
{
    char paren[MAX];
    bool test;
    printf("Enter a String of Parenthesis to check:\n");
    for(int i=0; i<MAX; i++)
    {
        scanf("%c",&paren[i]);
    }
    test=Check(paren);
    if(test)
    {
        printf("Correct\n");
    }
    else
    {
        printf("Not Correct\n");
    }
}
