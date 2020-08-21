#include <stdio.h>
#include "ListaEncadeada.h"

struct elemento{
    struct aluno dados;
    struct elemento *next;
};
typedef struct elemento Elem;

// no prog
//Lista *li; // ponteiro pra ponteiro 

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
        Elem* head;
        while((*li) != NULL){
            head = *li;
            *li - (*li)->next;
        }
        free(li);
    }
}

// no prog 
//libera_lista(li);

int tamanho_lista(Lista* li){
    if(li == NULL) 
        return 0;
    int cont = 0;
    Elem* head = *li;
    while(head != NULL){
        cont++;
        head = head->next;
    }
    return cont;
}

//no prog
// int x = tamanho_lista(li);

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

//no prog
// int x = lista_vazia(li);
// if(lista_vazia(li));