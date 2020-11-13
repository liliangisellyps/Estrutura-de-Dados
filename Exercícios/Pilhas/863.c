#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)

struct elemento{
    int data;
    struct elemento *next;
};
typedef struct elemento Elem;
typedef struct elemento* Pilha;

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}
int tamanhoPilha(Pilha* pi){
    if(pi == NULL) return 0;
    int cont = 0;
    Elem* node = *pi;
    while(node != NULL){
        node = node->next;
        cont++;
    }
    return cont;
}
int pilhaVazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if((*pi) == NULL)
        return 1;
    return 0;
}
int push(Pilha* pi, int x){
    if(pi == NULL) return  0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) return 0;
    node->data = x;
    node->next = (*pi);
    *pi = node;
    return 1;
}
int pop(Pilha* pi){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;
    Elem *node = *pi;
    *pi = node->next;
    free(node);
    return 1;
}
void liberaPilha(Pilha* pi){
    if(pi != NULL){
        Elem* node;
        while((*pi) != NULL){
            node = *pi;
            *pi = (*pi)->next;
            free(node);
        }
    }
}
int main(){
    Pilha *piE;
    piE = cria_pilha();
    Pilha *piB;
    piB = cria_pilha();
    Pilha *piF;
    piF = cria_pilha();
    char action[8];
    while(gets(action)){
        if(strcmp(action, "ENTER") == 0){
            if(!pilhaVazia(piE)){
                push(piB, 1);
            } 
            push(piE, 1);
            liberaPilha(piF);
            // printf("pilha-> ");
            // imprimePilha(pi);
            // printf("\n");
        } else if (strcmp(action, "BACK") == 0){
            if(tamanhoPilha(piE) > 1) {
                push(piF, 1);
                pop(piB);
            }
        } else {
            if(strcmp(action, "FORWARD") == 0){
                if(!pilhaVazia(piB)) {
                push(piB, 1);
                pop(piF);
            }
            }
        }
    }
    printf("BACK: %d\n", tamanhoPilha(piB));
    printf("FORWARD: %d", tamanhoPilha(piF));
}