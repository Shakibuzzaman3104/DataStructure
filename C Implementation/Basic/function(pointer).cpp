#include<stdio.h>

using namespace std;

void addition(int *a,int *b);

int main()
{
    int a,b;
    a=5,b=5;
    addition(&a,&b);
    printf("%d %d\n",a,b);

}


void addition(int *a,int *b)
{
    *a=(*a)+100;
    *b=(*b)+100;
    //return c;
}
