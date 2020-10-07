#include <stdio.h>
#include "PilhaEstatica.h"
#include "PilhaEstatica.c"

// consulta smp no inicio

int consulta_pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL || pi->indice == 0)
        return 0;
    *al = pi->dados[pi->indice-1]; // ultimo elemento inserido
}

// int x = conulta_pilha(pi, &dados_aluno);