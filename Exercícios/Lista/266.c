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

Lista* createlist(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}
int emptyList(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}
void insertList(Lista* li, int number){
    if(li==NULL)
        return;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL)
        return;
    node->number = number;
    node->next = NULL;
    if(*li == NULL){ 
        *li = node;
    } else {
        Elem* aux = *li;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = node;
    }
    return;
}
void printList(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("%d ", no->number);
        no = no->next;
    }
}
int tamanho_lista(Lista* li){
    if(li == NULL) 
        return 0;
    int cont = 0;
    Elem* head = *li;
    while(head != NULL){
        cont++;
        head = head->next;
    }
    return cont;
}
void bubbleSort(Lista* li){
    int i, j, aux;
    Elem* current;
    Elem* prox;
    for (current = *li; current != NULL; current = current->next) {
        for (prox = current->next; prox != NULL; prox = prox->next) {
            if (prox->number < current->number) {
                aux = current->number;
                current->number = prox->number;
                prox->number = aux;
            }
        }
    }
}
int main(){
    Lista* li = createlist();
    int x;
    while(scanf("%d", &x) != EOF){
        insertList(li, x);
    }
    bubbleSort(li);
    printList(li);
    return 0;
}