//implement binary tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

//insert function
void insert(struct node** root, int data)
{
    if(*root == NULL)
    {
        *root = (struct node*)malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
    {
        if(data < (*root)->data)
        {
            insert(&(*root)->left, data);
        }
        else if(data > (*root)->data)
        {
            insert(&(*root)->right, data);
        }
    }
}

void delete(struct node** root, int data)
{
    if(*root == NULL)
    {
        return;
    }
    else
    {
        if(data < (*root)->data)
        {
            delete(&(*root)->left, data);
        }
        else if(data > (*root)->data)
        {
            delete(&(*root)->right, data);
        }
        else
        {
            if((*root)->left == NULL && (*root)->right == NULL)
            {
                free(*root);
                *root = NULL;
            }
            else if((*root)->left == NULL)
            {
                struct node* temp = *root;
                *root = (*root)->right;
                free(temp);
            }
            else if((*root)->right == NULL)
            {
                struct node* temp = *root;
                *root = (*root)->left;
                free(temp);
            }
            else
            {
                struct node* temp = (*root)->right;
                while(temp->left != NULL)
                {
                    temp = temp->left;
                }
                (*root)->data = temp->data;
                delete(&(*root)->right, temp->data);
            }
        }
    }
}

void main()
{
    struct node* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);

    printf("preorder: ");
    preorder(root);
    printf("\n");
    printf("inorder: ");
    inorder(root);
    printf("\n");
    printf("postorder: ");
    postorder(root);
    printf("\n");

    delete(&root, 5);

    printf("preorder: ");
    preorder(root);
    printf("\n");
    printf("inorder: ");
    inorder(root);
    printf("\n");
    printf("postorder: ");
    postorder(root);
    printf("\n");

}