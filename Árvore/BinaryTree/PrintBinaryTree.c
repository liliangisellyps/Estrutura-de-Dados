#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTree.c"

void printPreOrder(Tree *root){
    if(root == NULL)
        return;
    if(*root != NULL){
        printf("%d\n", (*root)->data);
        printPreOrder(&((*root)->left));
        printPreOrder(&((*root)->right));
    }
}
// printPreOrder(root);

void printInOrder(Tree *root){
    if(root == NULL)
        return;
    if(*root != NULL){
        printInOrder(&((*root)->left));
        printf("%d\n", (*root)->data);
        printInOrder(&((*root)->right));
    }
}
// printPreOrder(root);

void printPostOrder(Tree *root){
    if(root == NULL)
        return;
    if(*root != NULL){
        printPostOrder(&((*root)->left));
        printPostOrder(&((*root)->right));
        printf("%d\n", (*root)->data);
    }
}
// printPreOrder(root);