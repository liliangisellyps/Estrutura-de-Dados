#include <stdio.h>
#include "ListaCircular.h"
#include "ListaCircular.c"

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *node = (Elem*) malloc(sizeof(Elem));
    if(node = NULL)
        return 0;
    node->dados = al;
    if((*li) == NULL){ // lista vazia: insere no inciio da lista
        *li = node;
        node->next = node; // o proximo aponta pra ele mesmo pois so tem ele
    } else {
        Elem *aux = *li;
        while(aux->next != (*li))
            aux = aux->next; // achar o "ultimo elemento"
        aux->next = node; // coloco no next do ultimo
        node->next = *li; // e o next do novo aponta pra cabeça
        *li = node; // a nova cabeça aponta pro novo nó
    }
}

// isnerir no final eh quase igual a no inicio exceto a ultima linha pois nao mudo a cabeça
int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *node = (Elem*) malloc(sizeof(Elem));
    if(node = NULL)
        return 0;
    node->dados = al;
    if((*li) == NULL){
        *li = node;
        node->next = node;
    } else {
        Elem *aux = *li;
        while(aux->next != (*li))
            aux = aux->next;
        aux->next = node;
        node->next = *li;
    }
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *node = (Elem*) malloc(sizeof(Elem));
    if(node = NULL)
        return 0;
    node->dados = al;
    if((*li) == NULL){ // lista avzia: insere inicio
        *li = node;
        node->next = node;
        return 1;
    } else {
        if((*li)->dados.matricula > al.matricula){ // isnere no inicio
            Elem *atual = *li;
            while(atual->next != (*li)) // procura o ultimo
                atual = atual->next;
            node->next = *li;
            atual->next = node;
            *li = node;
            return 1;
        }
        Elem *ant = *li, *atual = (*li)->next;
        while(atual != (*li) && atual->dados.matricula < al.matricula){ // dar uma volta completa na lista
            ant = atual;
            atual = atual->next;
        }
        ant->next = node;
        node->next = atual;
    }