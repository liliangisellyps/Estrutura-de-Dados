#include <stdio.h>
#include "ListaDinEncadDesc.h"

struct elemento {
    struct aluno dados;
    struct elemento *next;
};
typedef struct elemento Elem;

struct descritor {
    struct elemento *inicio;
    struct elemento *final;
    int tam;
};
// Lista *li; no programa principal
Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->final = NULL;
        li->tam = 0;
    }
    return li;
}
// li = cria_lista(); no prog prin

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* node;
        while((li->inicio) != NULL){
            node = li->inicio;
            li->inicio = li->inicio->next;
            free(node);
        }
        free(li);
    }
}
// libera_lista(li);

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    return li->tam;
}
// int x = tamanho_lista(li);

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) return 0;
    node->dados = al;
    node->next = li->inicio;
    if(li->inicio == NULL)
        li->final = node;
    li->inicio = node;
    li->tam++;
    return 1;
}
// int x = insere_lista_inicio(li, dados_aluno);

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) return 0;
    node->dados = al;
    node->next = NULL;
    if(li->inicio == NULL) // lista vazia: insere inicio
        li->inicio = node;
    else 
        li->final->next = node;
    li->final = node;
    li->tam++;
    return 1; 
}
// int x = insere_lista_final(li, dados_aluno);

int remove_lista_inicio(Lista* li){
    if(li== NULL) return 0;
    if(li->inicio == NULL) // lista vazia, pd checar através da quantidade tb
        return 0;
    Elem *node = li->inicio;
    li->inicio = node->next;
    free(node);
    if(li->inicio == NULL) // lista so tinha um elemento
        li->final = NULL;
    li->tam--;
    return 1;
}
// no prog int x = remove_lista_inicio(li);

int remove_lista_final(Lista* li){
    if(li == NULL)  return 0;
    if(li->inicio == NULL) return 0;
    Elem *prev, *node = li->inicio;
    while(node->next != NULL){
        prev = node;
        node = node->next;
    }
    if(node == li->inicio) {// remover o primeiro
        li->inicio = NULL;
        li->final = NULL;
    } else {
        prev->next = node->next;
        li->final = prev;
    }
    free(node);
    li->tam--;
    return 1;
}

