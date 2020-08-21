#include <stdio.h>
#include "ListaEstatica.h"
#include "ListaEstatica.c"
//no prog
// int x = insere_lista_ESPECIFICAÇÃO(li, dados_aluno);

int insere_lista_vazia(Lista* li, struct aluno al){
    if(lista_vazia(li)){
        li->dados[0] = al;
        li->qtd++;
    }

}
int insere_lista_final(Lista* li, struct aluno al){
    if(li==NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li==NULL)
        return 0;
    if(lista_cheia(li))
        return 0;

    int i;
    //andando uma casa do final para o inicio
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    
    //primeira posição esta livre
    li->dados[0] = al;
    li->qtd++;
    return 1;
}
int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li==NULL)
        return 0;
    if(lista_cheia(li))
        return 0;

    int k, i = 0;
    //varrendo a lista incrementando o i a medida que checo se 
    //matricula em que estou é menor que a matricula que quero inserir, 
    //caso nao seja (= seja maior) eu paro naquele lugar
    while(i<li->qtd && li->dados[i].matricula < al.matricula)
        i++;
    //pego todos os dados que estão daquele indice em diante
    //e movo uma casa para frente a fim de inserir a nova 
    //matricula ali (de forma ordenada)
    for(k=li->qtd-1; k>=i; k--)
        li->dados[k+1] = li->dados[k];
    // após a busca e a mudança, eu insiro e incremento a qntd
    li->dados[i] = al;
    li->qtd++;
    return 1;
}
