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
int insere_lista_inversa(Lista* li, int number){
    if(li == NULL) 
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) return 0;
    node->number = number;
    node->next = (*li);
    *li = node;
    return 1;
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
    Lista *li = cria_lista();
    int x;
    while(scanf("%d", &x) != EOF){
        insere_lista_inversa(li, x);
    }
    imprime_lista(li);
    return 0;
}