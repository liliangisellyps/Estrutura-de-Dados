#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct elemento{
    int number;
    struct elemento *next;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}
int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}
int insere_lista_ordenada(Lista* li, int number){
    if(li == NULL)
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    node->number = number;
    if(lista_vazia(li)){
        node->next = (*li);
        *li = node;
        return 1;
    } else { // procura onde inserir
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->number < number){// o dado que eu eu tenho na lista seja menor que o que eu quero inserir
            ant = atual;
            atual = atual->next;
        }
        if(atual == *li){
            node->next = *li;
            *li = node;
        } else {
            node->next = ant->next;
            ant->next = node;
        }
        return 1;
    }
}
void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("%d ", no->number);
        no = no->next;
    }
}
int main(){
    Lista* li = cria_lista();
    int x;
    while(scanf("%d", &x) != EOF){
        insere_lista_ordenada(li, x);
    }
    imprime_lista(li);
    return 0;
}