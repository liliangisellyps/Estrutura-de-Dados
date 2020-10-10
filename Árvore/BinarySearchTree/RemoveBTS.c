#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTree.c"

// remoção em nó filho, nó com 1 filho e nó com 2 filhos

struct node* removeCurrent(struct node* current){
    struct node *node1, *node2;
    if(current->left == NULL){
        node2 = current->right;
        free(current);
        return node2;
    }
    node1 = current;
    node2 = current->left;
    while(node2->right != NULL){
        node1 = node2;
        node2 = node2->right;
    }
    if(node1 != current){
        node1->right = node2->left;
        node2->left = current->left;
    }
    node2->right = current->right;
    free(current);
    return node2;
}

int removeBinTreeSearch(Tree *root, int value){
    if(root == NULL) return 0;
    struct node* prev = NULL;
    struct node* current = *root;
    while(current != NULL){
        // achou o nó a ser removido
        if(value == current->data){
            if(current == *root)
                *root = removeCurrent(current);
            else{
                if(prev->right == current)
                    prev->right = removeCurrent(current);
                else 
                    prev->left = removeCurrent(current);
            }
            return 1;
        }
        // continua andando na arvore a procura do nó a ser removido
        prev = current;
        if(value > current->data)
            current = current->right;
        else
            current = current->left;
    }   
}
