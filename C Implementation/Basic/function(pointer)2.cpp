#include<stdio.h>

using namespace std;

int* addition(int *a,int *b);

int main()
{
    int a,b;
    a=5,b=5;
    int *p;
    *p=&addition(&a,&b);
    printf("%d %d\n",*p);

}


int* addition(int *a,int *b)
{
    return *a+*b;
}
