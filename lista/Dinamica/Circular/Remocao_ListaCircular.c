#include <stdio.h>
#include "ListaCircular.h"
#include "ListaCircular.c"

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    if((*li) == (*li)->next){ // so um um nó: a lista fica vazia
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *atual = *li;
    while(atual->next != (*li)) // PROCURA O ULT ELEMENTO
        atual = atual->next;
    Elem *node = *li;
    atual->next = node->next;
    *li = node->next;
    free(node);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    if((*li) == (*li)->next){ // so um um nó: a lista fica vazia
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *ant, *node = *li;
    while(node->next != *li){// procura o ultimo
        ant = node;
        node = node->next;
    }
    ant->next = node->next;
    free(node);
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    Elem *node = *li;
    if(node->dados.matricula == mat){// remover no inicio
        if(node == node->next){
            free(node);
            *li = NULL;
            return 1;
        } else {
            Elem *ult = *li;
            while(ult->next != (*li))// procur ao ult
                ult = ult->next;
            ult->next = (*li)->next;
            *li = (*li)->next;
            free(node);
            return 1;
        }
    }
    Elem *ant = node;
    node = node->next;
    while(node != (*li) && node->dados.matricula != mat){
        ant = node;
        node = node->next;
    }
    if(node == *li)
        return 0;
    ant->next = node->next;
    free(node);
    return 1;
}