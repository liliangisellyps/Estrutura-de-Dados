#include <stdio.h>
#include "ListaDupEncad.h"
#include "ListaDupEncad.c"

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *node = *li;
    int  i = 1;
    while(node != NULL && i<pos){
        node = node->next;
        i++;
    }
    if(node == NULL)
        return 0;
    else{
        *al = node->dados;
        return 1;
    }
}

int consulta_lista_valor(Lista* li, int valor, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *node = *li;
    while(node != NULL && node->dados.matricula != valor)
        node = node->next;
    if(node == NULL)
        return 0;
    else{
        *al = node->dados;
        return 1;
    }
}