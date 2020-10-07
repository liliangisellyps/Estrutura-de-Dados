#include <stdio.h>
#include "PilhaDinamica.h"

struct elemento{
    struct aluno dados;
    struct elemento *next;
};
typedef struct elemento Elem;

// Pilha *pi

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

//pi = cria_pilha();

void libera_pilha(Pilha* pi){
    if(pi != NULL){
        Elem* node;
        while((*pi) != NULL){
            node = *pi;
            *pi = (*pi)->next;
            free(node);
        }
        free(pi);
    }
}
//libera_pilha(pi);

int tamanho_pilha(Pilha* pi){
    if(pi == NULL) return 0;
    int cont = 0;
    Elem* node = *pi;
    while(node != NULL){
        node = node->next;
        cont++;
    }
    return cont;
}
// int x = tamanho_pilha(pi);

int pilha_cheia(Pilha* pi){
    return 0;
}
// int x = pilha_cheia(pi);
// if(pilha_cheia(pi));

int pilha_vazia(Pilha* pi){
    if(pi == NULL) // representação d apilha em si
        return 1;
    if((*pi) == NULL) // topo
        return 1;
    return 0;
}
// int x = pilha_vazia(pi);
// if(pilha_vazia(pi));

//a inserção é sempre no inicio, a pilha pode estar vazia, nao se pode inserir em uma pilha cheia

int insere_pilha(Pilha* pi, struct aluno al){
    if(pi == NULL) return  0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) return 0;
    node->dados = al;
    node->next = (*pi);
    *pi = node;
    return 1;
}
// int x = insere_pilha(pi, dados_aluno);

int remove_pilha(Pilha* pi){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;
    Elem *node = *pi;
    *pi = node->next;
    free(node);
    return 1;
}
// int x = remove_pilha(pi, dados_aluno);

void consulta_pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;
    *al = (*pi)->dados;
}
// int x = consulta_pilha(pi, &dados_aluno);
