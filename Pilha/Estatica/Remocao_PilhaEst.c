#include <stdio.h>
#include "PilhaEstatica.h"
#include "PilhaEstatica.c"

// remoção smp no inicio
//  nao se pode remover de uma pilha vazia

int remove_pilha(Pilha* pi){
    if(pi == NULL || pi->indice == 0)
        return 0;
    pi->indice--; // posso sobrescrever mas não acessar
    return 1;
}
// int x = remove_pilha(pi);