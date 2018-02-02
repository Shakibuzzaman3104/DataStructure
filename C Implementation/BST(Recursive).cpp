#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
using namespace std;
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

    }
    else if(x<=root->data)
    {
        root->left=insert(root->left,x);
    }
    else
    {
        root->right=insert(root->right,x);
    }
    return root;
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


void preorder(Node* root)
{
    if(root==NULL)
       return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root==NULL)
       return;
    preorder(root->left);
    printf("%d ",root->data);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
       return;
    preorder(root->left);
    preorder(root->right);
    printf("%d ",root->data);
}

void Selection(Node* root,int ch)
{
    int val,l;
    switch(ch)
    {
    case 1:
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
        break;

    case 2:
        print(root);
        printf("\n");
        break;
    case 3:
        bfs(root);
        printf("\n");
        break;
    case 4:
        scanf("%d",&l);
        root=insert(root,l);
        break;
    case 5:
        preorder(root);
        printf("\n");
        break;
    case 6:
        inorder(root);
        printf("\n");
        break;
    case 7:
        postorder(root);
        printf("\n");
        break;
    default:
        printf("Please Choose between 1-3\n");
        break;
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

    int ch;
    while(true)
    {
        printf("1: To Search A Value in The Tree\t2: To Print The tree\n3: Perform BFS\t\t4: Insert a value inside the tree\n5: Print Tree in Preorder\t 6: Print Tree in InOrder\t7: Print Tree in PostOrder\n");
        scanf("%d",&ch);
        Selection(root,ch);
    }
    return 0;
}
/*
8
26
21
30
18
20
28
33
19
*/

