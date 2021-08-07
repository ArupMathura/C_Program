#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *create(){
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d", &x);
    if(x == -1){
        return 0;
    }
    newnode->data = x;
    printf("\nEnter the left child of %d", x);
    newnode->left = create();
    printf("\nEnter the right child of %d", x);
    newnode->right = create();
    return newnode;
}

void *preorder(struct node *root)
{
    if(root == 0){
        return NULL;
    }
    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}

void *inorder(struct node *root)
{
    if(root == 0){
        return NULL;
    }
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}

void *postorder(struct node *root)
{
    if(root == 0){
        return NULL;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->data);
}

/*

void preorder(struct node *t) //address of root node is passed in t
{
    if(t!=NULL)
    {
        printf("\n%d",t->data); //visit the root
        preorder(t->left); //preorder traversal on left subtree
        preorder(t->right); //preorder traversal om right subtree
    }
}

void inorder(struct node *t) //address of root node is passed in t
{
    if(t!=NULL)
    {
        inorder(t->left); //preorder traversal on left subtree
        printf("\n%d",t->data); //visit the root
        inorder(t->right); //preorder traversal om right subtree
    }
}

void postorder(struct node *t) //address of root node is passed in t
{
    if(t!=NULL)
    {
        postorder(t->left); //preorder traversal on left subtree
        postorder(t->right); //preorder traversal om right subtree
        printf("\n%d",t->data); //visit the root
    }
}
*/

int  main(){
    struct node *root;
    root = 0;
    root = create();
 
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    printf("\nThe inorder traversal of tree is:\n");
    inorder(root);
    printf("\nThe inorder traversal of tree is:\n");
    postorder(root);
    return 0;
}