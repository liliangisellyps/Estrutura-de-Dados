#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define DBG if(0)
typedef struct node* Tree;

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
int insertTree(Tree* root, int value){
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
int main(){
    int i = 0;
    Tree* root = createTree();
    char* tree = (char*) malloc(sizeof(char));

    scanf("%s", tree);
    // printf("arvore: %s\n", tree);
    while(i<strlen(tree)){
        printf("%c ", tree[i]);
        int j=0;
        char* number = (char*) malloc(sizeof(char));
        if(tree[i] == '(') {
            i++;
            while(tree[i] != '(' && tree[i] != ')') {
               number[j] = tree[i];
               i++;
               j++;
           }
        }
        printf("numero: %d ", atoi(number));
        insertTree(root, atoi(number));
    }
}