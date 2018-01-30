#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* Newnode(int x)
{
    struct Node* newnode=(Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct Node* insert(Node* root,int x)
{

    if(root==NULL)
    {
        root=Newnode(x);
        return root;
    }
    else if(x<=root->data)
    {
        root->left=insert(root->left,x);
    }
    else
    {
        root->right=insert(root->right,x);
    }

}

void print(Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        printf("\n\n");
        print(root->left);
        print(root->right);
    }
}

bool search(Node* root,int x)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }

    if(x<=root->data)
    {
        return search(root->left,x);
    }
    else
    {
        return search(root->right,x);
    }

}

void  bfs(Node* x)
{
    if(x==NULL)
    {
        return;
    }
    std::queue <Node* > Q;
    Q.push(x);
    while(!Q.empty())
    {
        Node* current=Q.front();
        printf("%d |",current->data);
        if(current->left!=NULL)
        {
            Q.push(current->left);
        }
        if(current->right!=NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}

int main()
{
    struct Node* root=NULL;

    int i,s,l,val;
    printf("Insert Size of the Tree: ");
    scanf("%d",&s);
    printf("Insert data in binary tree:\n");
    for(i=0; i<s; i++)
    {
        scanf("%d",&l);
        root=insert(root,l);
    }
    printf("enter a value to search: ");
    scanf("%d",&val);
    if(search(root,val)==true)
    {
        printf("Found\n\n");
    }
    else
    {
        printf("Not Found\n\n");
    }
    print(root);
    printf("\n");

    bfs(root);

    return 0;
}
/*
8                    26
26             21          30
21          18          28    33
30              20                45
18            19
20
28
33
19
*/

