#include <stdio.h>
#include "PilhaEstatica.h"

struct pilha {
    int indice; // indice de onde ele esta no array
    struct aluno dados[MAX];
};

// Pilha *pi;

Pilha* cria_pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL)
        pi->indice = 0;
    return pi;
}

// pi = cria_pilha();

void libera_pilha(Pilha* pi){
    free(pi);
}

// libera_pilha(pi);

int tamanho_pilha(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return pi->indice;
}
// int x = tamanho_pilha(pi);
// if(tamanho_pilha(pi));

int pilha_cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return (pi->indice == MAX);
}
// int x = pilha_cheia(pi);
// if(pilha_cheia(pi));

int pilha_cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return (pi->indice == 0);
}
// int x = pilha_vazia(pi);
// if(pilha_vazia(pi));