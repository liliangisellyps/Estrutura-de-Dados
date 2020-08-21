#include <stdio.h>
#include "ListaDupEncad.h"

struct elemento{
    struct elemento *prev;
    struct aluno dados;
    struct elemento *next;
};
typedef struct elemento Elem;

//no prog
// Lista *li;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

// no prog
// li = cria_lista();

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* node;
        while(*li != NULL){
            node = *li;
            *li = (*li)->next;
            free(node);
        }
        free(li);
    }   
}

// no prog 
// libera_lista(li);

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* node = *li;
    while(node != NULL){
        cont++;
        node = node->next;
    }
    return cont;
}
// no prog
// int x = tamanho_lista(li);

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

// no prog
// int x = lista_vazia(li);
// if(lista_vazia(li));