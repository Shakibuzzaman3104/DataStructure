#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 9

char arr[MAX];
int top=-1;

bool isEmpty();
void push(char paren[]);
int pop();
void print();
bool  IsOperand(char val);
bool IsOperator(char val);
int Action(int val1,char op,int val2);

bool isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else
        return false;
}
int pop()
{
    if(top==0)
    {
        top=-1;
    }
    top--;
    return arr[top];
}

bool  IsOperand(char val)
{
    if(val=='0' || val=='1' || val=='2' ||val=='3' || val=='4' || val=='5' || val=='6' ||val=='7' || val=='8' || val=='8' || val=='9')
        return true;
    else
        return false;
}

bool IsOperator(char val)
{
    if(val=='+' || val=='-' || val=='/' || val=='*')
        return true;
    else
        return false;
}

void push(int data)
{
    if(isEmpty())
    {
        top=0;
    }
    arr[top]=data;
    //printf("%d ",arr[top]);
    top=top+1;
}

int Action(int val1,char op,int val2)
{
    if(val1<val2)
    {
        int sw;
        sw=val1;
        val1=val2;
        val2=sw;
    }
    if(op=='+')
        return (val1+val2);
    else if(op=='-')
        return (val1-val2);
    else if(op=='*')
        return (val1*val2);
    else
        return (val1/val2);
}

int Check(char paren[])
{
    int i;
    int len=strlen(paren);
    for(i=0; i<len; i++)
    {
        if(IsOperand(paren[i]))
        {
            int data=paren[i]-'0';
            push(data);
        }
        else if(IsOperator(paren[i]))
        {
            int value1=pop();
            int value2=pop();
            //printf("value1=%d operator=%c value2=%d ",value1,val,value2);
            int result=Action(value1,paren[i],value2);
            //printf("%d ",result);
            push(result);
        }
    }
 return arr[top-1];
}

int main()
{
    char paren[MAX];
    int test;
    int integer[MAX];
    printf("Enter a String of operations to check:\n");
    for(int i=0; i<MAX; i++)
    {
        scanf("%c",&paren[i]);
    }

    test=Check(paren);
    printf("%d",test);
}

