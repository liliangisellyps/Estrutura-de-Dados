#include <stdio.h>
#include "ListaEstatica.h"

struct lista {
    int qtd;
    struct aluno dados[MAX];
};

// No programa principal
// Lista *li;

Lista* cria_lista(){
    Lista *li;
    li = (Lista*)malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

// No programa principal 
// li = cria_lista();

void libera_lista(Lista* li){
    free(li);
}

//No prog principal
// libera_lista(li);

int tamanho_lista(Lista* li){
    if(li==NULL)
        return -1;
    else
        return li->qtd;
}

//no prog
// int x = tamanho_lista(li);

int lista_cheia(Lista* li){
    if(li==NULL)
        return -1;
    return(li->qtd==MAX);
}

//no prog
// int x = lista_cheia(li);
//if(lista_cheia(li))

int lista_vazia(Lista* li){
    if(li==NULL)
        return -1;
    return(li->qtd==0);
}

//no prog
// int x = lista_vazia(li);
//if(lista_vazia(li))

