#include <stdio.h>
#include "BinaryTree.h"

struct node {
    int data;
    struct node *left;
    struct node *right;
};
// Tree* root;

Tree* createTree(){
    Tree* root = (Tree*) malloc(sizeof(Tree));
    if(root != NULL)
        *root = NULL;
    return root;
}
// Tree* root = createTree();

void deleteNode(struct node* node){
    if(node == NULL)
        return 0;
    deleteNode(node->left);
    deleteNode(node->right);
    free(node);
    node = NULL;
}
void deleteTree(Tree* root){
    if(root == NULL)
        return 0;
    deleteNode(*root);
    free(root);
}
// deleteTree(root);

int isEmpty(Tree *root){
    if(root == NULL)
        return 1;
    if(*root == NULL)
        return 1;
    return 0;
}
// if(isEmpty(root))

int heightTree(Tree *root){
    if(root == NULL)
        return 0;
    if(*root == NULL)
        return 0;
    int heightLeft = heightTree(&((*root)->left));
    int heightRight = heightTree(&((*root)->right));
    if(heightLeft > heightRight)
        return (heightLeft + 1);
    else 
        return(heightRight + 1);
}
// int x = heightTree(root);

int countTreeNodes(Tree* root){
    if(root == NULL)
        return 0;
    if(*root == NULL)
        return 0;
    int heightLeft = countTreeNodes(&((*root)->left));
    int heightRight = countTreeNodes(&((*root)->right));
    return(heightLeft + heightRight + 1);
}
// int x = countTreeNodes(root);