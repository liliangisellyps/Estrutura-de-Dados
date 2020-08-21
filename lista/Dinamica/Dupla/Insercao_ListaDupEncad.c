#include <stdio.h>
#include "ListaDupEncad.h"
#include "ListaDupEncad.c"

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL)
        return 0;
    node->dados = al;
    node->next = (*li);
    node->prev = NULL;
    if(*li != NULL) // lista nao estava vazia
        (*li)->prev = node;
    *li = node;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL)
        return 0;
    node->dados = al;
    node->next = NULL;
    if((*li) == NULL){ // lista vazia: insere no inicio
        node->prev = NULL;
        *li = node;
    }else{
        Elem *aux = *li;
        while(aux->next != NULL) // procurando o ultimo elemento
            aux = aux->next;
        aux->next = node;
        node->prev = aux;
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL)
        return 0;
    node->dados = al;
    if(*li == NULL){ // LISTA VAZIA: INSERE NO INICIO
        node->next = NULL;
        node->prev = NULL;
        *li = node;
        return 1;
    } else{ // procura onde inserir
        Elem *ante, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ante = atual;
            atual = atual->next;
        } // achou o lugar certo = anteriores sao menores e posteriores sao maiores
        if(atual == *li){ // insere no inicio
            node->prev = NULL;
            (*li)->prev = node;
            node->next = NULL;
            *li = node;
        } else { // isnere no meio ou no final
            node->next = ante->next;
            node->prev = ante;
            ante->next = node;
            if(atual != NULL) // ou seja ele esta no meio da lista
                atual->prev = node;
        }
        return 1;

    }
}


