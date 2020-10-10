#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTree.c"

int searchBinTreeSearch(Tree *root, int value){
    if(root == NULL)
        return 0;
    struct node* current = *root;
    while(current != NULL){
        if(value == current->data){
            return 1;
        }
        if(value > current->data)
            current = current->right;
        else
            current = current->left;
        return 0;
    }
}