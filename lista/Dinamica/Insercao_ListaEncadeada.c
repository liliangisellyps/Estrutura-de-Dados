#include <stdio.h>
#include "ListaEncadeada.h"

// no prog
// int x = insere_lista_ESPECIFICO(li, dados_aluno);


int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) 
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) return 0;
    node->dados = al;
    node->next = (*li);
    *li = node;
    return 1;
}
// serve tanto para lista vazia quanto para inserir no inicio

int insere_lista_final(Lista* li, struct aluno al){
    if(li==NULL) // verifica se a lista existe
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) // verifica s o nó foi alocado certo
        return 0;
    node->dados = al; // atribui os valores que eu quero inserir nesse novo nó
    node->next = NULL;
    if(*li == NULL){ 
        *li = node; // saco a lista esteja vazia, ele atribui no primeiro lugar
    } else {
        Elem* aux = *li;
        while(aux->next != NULL)
            aux = aux->next; // procura através do auxiliar o ultimo elemento da lista
        aux->next = node; // por fim, insere
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    node->dados = al;
    if(lista_vazia(li)){
        node->next = (*li);
        *li = node;
        return 1;
    } else { // procura onde inserir
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){// o dado que eu eu tenho na lista seja menor que o que eu quero inserir
            ant = atual;
            atual = atual->next;
        }
        if(atual == *li){
            node->next = *li;
            *li = node;
        } else {
            node->next = ant->next;
            ant->next = node;
        }
        return 1;
    }
}

