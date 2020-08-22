#include <stdio.h>
#include "ListaCircular.h"
#include "ListaCircular.c"


int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || (*li) == NULL || pos <= 0)
        return 0;
    Elem *node = *li;
    int i = 1;
    while(node->next != (*li) && i<pos){
        node = node->next;
        i++;
    }
    if(i != pos)
        return 0;
    else{
        *al = node->dados;
        return 1;
    }
}
    

    
int consulta_lista_valor(Lista* li, int mat, struct aluno *al){
    if(li == NULL || (*li) == NULL)
        return 0;
    Elem *node = *li;
    while(node->next != (*li) && node->dados.matricula != mat){
        node = node->next;
    }
    if(node->dados.matricula != mat)
        return 0;
    else{
        *al = node->dados;
        return 1;
    }
}