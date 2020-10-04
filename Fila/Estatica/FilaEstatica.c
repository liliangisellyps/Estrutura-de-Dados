#include <stdio.h>
#include "FilaEstatica.h"

struct fila{
    int inicio, final, tam;
    struct aluno dados[MAX];
};
// Fila *fi no pog principal

Fila* cria_fila(){
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->tam = 0;
    }
    return fi;
}
// Fila* cria_fila(); no prog principal 

void libera_fila(Fila* fi){
    free(fi);
}
// libera_fila(fi);

int tamanho_fila(Fila* fi){
    if(fi == NULL)
        return -1;
    return fi->tam;
}
// int x = tamanho_fila(fi);

int fila_cheia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->tam == MAX)
        return 1;
    else 
        return 0;
}
// int x = fila_cheia(fi);
// if(fila_cheia(fi))

int fila_vazia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->tam == 0)
        return 1;
    else 
        return 0;
}
// int x = fila_vazia(fi);
// if(fila_vazia(fi))

// inserção é sempre no seu final
// tb existe o caso em que se insere em uma lista vazia
// cuidado: nao se pode inserir numa fila cheia

int insere_fila(Fila* fi, struct aluno al){
    if(fi == NULL) return 0;
    if(fila_cheia(fi)) return 0;
    fi->dados[fi->final] = al; // final aponta pro espaço vago
    fi->final = (fi->final+1)%MAX;
    fi->tam++;
    return 1;
}
// int x = insere_fila(fi, dados_aluno);

// remoção eh sempre do inicio
// cuidado: nao se pode remover de uma lista vazia

int remove_fila(Fila* fi){
    if(fi == NULL || fila_vazia(fi)) 
        return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    // essa linha de cima eh a mesma coisa de:
    // inicio++;
    // if(inicio==MAX)
    //  inicio=0;
    fi->tam--;
    return 1;
}
// int x = remove_fila(fi)

// so da pra consultar os dados que estao no seu inicio
int consulta_fila(Fila* fi, struct aluno *al){
    if(fi == NULL || fila_vazia(fi))
        return 0;
    *al = fi->dados[fi->inicio];
    return 1;
}
// int x = consulta_fila(fi, &dados_aluno);
