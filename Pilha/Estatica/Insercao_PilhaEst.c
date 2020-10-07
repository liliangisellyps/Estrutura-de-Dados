#include <stdio.h>
#include "PilhaEstatica.h"
#include "PilhaEstatica.c"

// inserção sempre no inicio
// n pde inserir em uma pilha cheia
// considerar qnd estiver vazia

int insere_pilha(Pilha* pi, struct aluno al){
    if(pi == NULL) return 0;
    if(pilha_cheia(pi)) return 0;
    pi->dados[pi->indice] = al;
    pi->indice++;
    return 1;
}

// int x = insere_pilha(pi, dados_aluno);