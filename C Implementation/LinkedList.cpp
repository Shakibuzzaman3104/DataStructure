#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void print();
void insert(int x);
void remove(int x);
void between(int p,int v);

void insert(int x)
{
    Node* temp=(Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
}

void print()
{
    printf("\n");
    struct Node *temp=head;
    while(temp->next!=NULL)
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

    struct Node* temp1=head;

    for(i=0;i<p-2;i++)
    {
        temp1=temp1->next;
    }
    struct Node* temp2=temp1->next;
    temp3->data=v;
    temp1->next=temp3;
    temp3->next=temp2;
    print();
}

void remove (int x)
{
    int i;
    struct Node* temp1=head;

    if(x==1)
    {
        temp1=temp1->next;
        free(temp1);
        print();
        return;
    }

    for(int i=0; i<x-2; i++)
    {
        temp1=temp1->next;
    }
    struct Node* temp2=temp1->next;
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
        insert(in);
        print();
    }

    printf("Enter a position to remove\n");
    int x;
    scanf("%d",&x);
    remove(x);

    printf("Enter a Position and value to insert\n");
    int p,v;
    scanf("%d %d",&p,&v);
    between(p,v);
    return 0;
}
