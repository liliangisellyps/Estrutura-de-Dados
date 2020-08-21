#include <stdio.h>
#include "ListaDupEncad.h"
#include "ListaDupEncad.c"


int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(*li == NULL)
        return 0;
    Elem *node = *li;
    *li = node->next;
    if(node->next != NULL) //  lista n eh vazia
        node->next->prev = NULL;
    free(node);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(*li == NULL)
        return 0;
    Elem *node = *li;
    while(node->next != NULL)
        node = node->next;
    if(node->prev == NULL) // remove o primeiro e unico
        *li = node->next;
    else 
        node->prev->next = NULL;
    free(node);
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    Elem *node = *li;
    while(node != NULL && node->dados.matricula != mat)
        node = node->next;
    
    if(node == NULL)
        return 0; // nao encontrado
    
    if(node->prev == NULL) // remover o primeiro
        *li = node->next;
    else 
        node->prev->next = node->next;
    
    if(node->next != NULL) // se nao for o ultimo, ou seja estiver no meio da lista
        node->next->prev = node->prev;
    
    free(node);

    return 1;
}


