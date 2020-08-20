#include <stdio.h>
#include "ListaEstatica.h"

//no prog
// int x = remove_lista_ESPECIFICO(li);

int remove_lista_final(Lista* li){
    if(li==NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li==NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k=0; k<li->qtd-1; k++){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li==NULL)
        return 0;
    if(li->qtd == 0)
        return 0;

    int k, i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat) // buscando o indice da matricula que quero remover
        i++;
    if(i == li->qtd) // elemento nao encontrado
        return 0;
    for(k=i; k<li->qtd-1; k++) // achei entao tenho que remover cada elemento 
    // q esta na frente dele para trás
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;

}