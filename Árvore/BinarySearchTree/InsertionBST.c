#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTree.c"

int insertBinTreeSearch(Tree* root, int value){
    if(root == NULL)
        return 0;
    struct node* newNode;
    newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == NULL)
        return 0;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    //procura onde inserir
    if(*root == NULL)
        *root = newNode;
    else {
        struct node* current = *root;
        struct node* prev = NULL;
        // navega nos nós da arvore até chegar em um nó folha
        while(current != NULL){
            prev = current;
            if(value == current->data){
                free(newNode);
                return 0; //elemento ja existe
            }
            if(value > current->data)
                current = current->right;
            else
                current = current->left;
        }
        // insere como filho desse nó folha
        if(value > prev->data)
            prev->right = newNode;
        else
        {
            prev->left = newNode;
        }
        

    }
    
}