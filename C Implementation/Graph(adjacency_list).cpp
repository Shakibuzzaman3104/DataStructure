#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>

using namespace std;
vector<char>arra;

struct Node
{
  char data;
  Node* next;
};
//Node* arr[20];
vector<Node*> arr;

void Graph(char src,char dest);
void print(char src);

Node* Newnode(char dest)
{
    struct Node* newnode=(Node*)malloc(sizeof(struct Node));
    newnode->data=dest;
    newnode->next=NULL;

    return newnode;
}

void Graph(char src,char dest)
{
   int len=arra.size();
   int sr,des;
   //printf("%c %c",src,dest);
   for(int i=0;i<len;i++)
   {
        if(arra[i]==src)
        {
            sr=i;
            printf("%d ",sr);
        }

   }
   for(int i=0;i<len;i++)
   {
        if(arra[i]==dest)
        {
            des=i;
        }
   }
   struct Node* newnode=Newnode(dest);

   if ((sr > 0 && sr < arr.size()) && (arr[sr] != NULL))
   {
        Node* temp=arr[sr];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
   }
   else
   {
        arr[sr]=newnode;
   }
//   struct Node* newnode2=Newnode(src);
//   if(arr[des]==NULL)
//   {
//        arr[des]=newnode2;
//   }
//
//   else
//   {
//        Node* temp2=arr[des];
//        while(temp2->next!=NULL)
//        {
//            temp2=temp2->next;
//        }
//        temp2->next=newnode2;
//   }

}

void print(char src)
{
    int i,sr;
    int len=arra.size();
    for(i=0;i<len;i++)
    {
        if(src==arra[i])
        {
            sr=i;
            break;
        }
    }
    Node* temp=arr[sr];
    printf("%c --->",src);
    while(temp!=NULL)
    {
        printf("  %c ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    char src,dest;
    int v,i;
    printf("Please Enter Number of Verteces:");
    scanf("%d",&v);
    for(i=0;i<v;i++)
    {
        getchar();
        char val;
        scanf("%c",&val);
        arra.push_back(val);
    }

    printf("Please Enter Number of Edges:\n");
    scanf("%d",&v);
    for(i=0;i<v;i++)
    {
        getchar();
        scanf("%c %c",&src,&dest);
        Graph(src,dest);
    }



    while(true)
    {
         printf("\nplease Enter a Vertex to show its Adjacent Vertex:");
         getchar();
         scanf("%c",&src);
         print(src);
    }

}
/*
0 1
0 2
1 2
0 4
2 4
*/
