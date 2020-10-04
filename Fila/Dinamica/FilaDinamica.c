#include <stdio.h>
#include "FilaDinamica.h"
// usando nó descritor, poderia adicionar qtd

struct fila {
    struct elemento *inicio;
    struct elemento *final;
};
struct elemento{
    struct aluno dados;
    struct elemento *next;
};
typedef struct elemento Elem;

// Fila *fi; no prog principal

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}
// fi = cria_fila();

void libera_fila(Fila* fi){
    if(fi != NULL){
        Elem* node;
        while(fi->inicio != NULL){
            node = fi->inicio;
            fi->inicio = fi->inicio->next;
            free(node);
        }
        free(fi);
    }
}
//libera_fila(fi);

int tamanho_fila(Fila* fi){ // poderia ter add um campo pra isso na struct e ai nao pecisaria fazer isso aq, apenas atualizar ao add ou remover
    if(fi == NULL) 
        return 0;
    int cont = 0;
    Elem* node = fi->inicio;
    while(node != NULL){
        cont++;
        node = node->next;
    }
    return cont;
}
// int x = tamanho_fila(fi);

int fila_cheia(Fila* fi){ // fila dinamica neh nunca ta cheia
    return 0;
}
// if(fila_cheia(fi))
// int x = fila_cheia(fi);

int fila_vazia(Fila* fi){
    if(fi == NULL) return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}
// if(fila_cheia(fi))
// int x = fila_cheia(fi);

int insere_fila(Fila *fi, struct aluno al){
    if(fi == NULL) return 0;
    Elem *node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) return 0;
    node->dados = al;
    node->next = NULL;
    if(fi->final == NULL) // fila vazia
        fi->inicio = node;
    else
        fi->final->next = node;
    fi->final = node;
    return 1;
}
// int x = insere_fila(fi, dados_aluno);

int remove_fila(Fila* fi){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL)
        return 0;
    Elem *node = fi->inicio;
    fi->inicio = fi->inicio->next;
    if(fi->inicio == NULL) // fila ficou vazia
        fi->final = NULL;
    free(node);
    return 1;
}
// int x = remove_fila(fi);

// consulta apenas do primeiro elemento
int consulta_fila(Fila* fi, struct aluno *al){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL) // fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}
// int x = consulta_fila(fi, &dados_aluno);
