#include <stdio.h>
#include "ListaEstatica.h"

// no prog
// int x = consulta_lista_ESPECIFICO(li, ESPECIFICO(pos ou mat), &dados_aluno);

int consulta_lista_pos (Lista*li, int pos, struct aluno *al){
    if(li==NULL || pos <=0 || pos> li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}


// consultando por comparacao de algum dado especifico na struct
int consulta_lista_mat (Lista* li, int mat, struct aluno *al){
    if(li==NULL)
        return 0;
    int k, i =0;
    while(i<li->qtd-1 && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd) // elemento nao encontrado
        return 0;
    *al = li->dados[i];
    return 1;
}