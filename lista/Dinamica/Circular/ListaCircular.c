#include <stdio.h>
#include "ListaCircular.h"

struct elemento{
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
    if(li != NULL && (*li) != NULL){
        Elem *aux, *node = *li;
        while((*li) != node->next){ // enquanto o proximo for diferente do primeiro elemento
            aux = node;
            node = node->next;
            free(node);
        }
        free(node);
        free(li);
    }
}

// no prog
//libera_lista(li);

int tamanho_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return 0;
    int cont = 0;
    Elem* node = *li;
    do{
        cont++;
        node = node->next;
    } while (node != (*li)); // terminar uma volta completa
    return cont;
}

// no prog
// int x = tamanho_lista(li);

int lista_vazia(Lista* li){
    if(li == NULL && (*li) == NULL)
        return 1;
    else
        return 0;
}

// no prog
// int x = lista_vazia(li);