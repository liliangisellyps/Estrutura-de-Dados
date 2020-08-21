#include <stdio.h>
#include "ListaEncadeada.h"

int consulta_lista_valor(Lista* li, int valor, struct aluno *al){
    if(li == NULL || valor <= 0)
        return 0;
    Elem *node = *li;
    int i = 1;
    while(node != NULL && i< pos){
        node = node->next;
        i++;
    }
    if(node == NULL) // chegou ao final da lista e nao encontrou
        return 0;
    else {
        *al = node->dados;
        return 1;
    }
}
int consulta_lista_valor(Lista* li, int valor, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *node = *li;
    while(node != NULL && no->dados.matricula != valor){
        node = node->next;
    }
    if(node == NULL) // chegou ao final da lista e nao encontrou
        return 0;
    else {
        *al = node->dados;
        return 1;
    }
}