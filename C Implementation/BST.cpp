#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* Newnode(int x)
{
    struct Node* newnode=(Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

Node* insert(Node* root,int x)
{
    struct Node* newnode=Newnode(x);
    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    else
    {   struct Node* temp=root;

        while(temp!=NULL)
        {
            if(x<=temp->data)
            {
                temp=temp->left;
            }
            else
                temp=temp->right;
        }
        temp=newnode;
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

void Selection(Node* root,int ch)
{
    int val,l,sc;
    switch(ch)
    {
//    case 1:
//        printf("enter a value to search: ");
//        scanf("%d",&val);
//        if(search(root,val)==true)
//        {
//            printf("Found\n\n");
//        }
//        else
//        {
//            printf("Not Found\n\n");
//        }
//        break;

    case 1:
        print(root);
        printf("\n");
        break;
//    case 3:
//        bfs(root);
//        printf("\n");
//        break;
    case 2:
        scanf("%d",&l);
        insert(root,l);
        break;
//    case 5:
//        preorder(root);
//        printf("\n");
//        break;
//    case 6:
//        inorder(root);
//        printf("\n");
//        break;
//    case 7:
//        postorder(root);
//        printf("\n");
//        break;
//    case 8:
//        printf("Insert a Value to Delete");
//        scanf("%d",&sc);
//        Delete(root,sc);
//        print(root);
//        break;
    default:
        printf("Please Choose between 1-8\n");
        break;
    }
}

int main()
{
    struct Node* root;
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
        printf("1: To Search A Value in The Tree\t2: To Print The tree\n3: Perform BFS\t\t4: Insert a value inside the tree\n5: Print Tree in Preorder\t 6: Print Tree in InOrder\n7: Print Tree in PostOrder\t8: Delete A  Node\n");
        scanf("%d",&ch);
        Selection(root,ch);
    }
    return 0;
}
