#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)
typedef struct number Number;
typedef struct number *List;
int max(int a, int b) {return (a>b) ? a:b; }
int min(int a, int b) {return (a<b) ? a:b; }
void swap(int *a, int *b) {int c = *a; *a = *b; *b = c;}

struct number{
    int digit;
    Number *next;
};

List* criaLista(){
    List* li = (List*) malloc(sizeof(List));
    if(li != NULL)
        *li = NULL;
    return li;
}
int insertDigit(List* li, int num){
    if(li==NULL)
        return 0;
    Number* node = (Number*) malloc(sizeof(Number));
    if(node == NULL)
        return 0;
    node->digit = num;
    node->next = NULL;
    if(*li == NULL){ 
        *li = node;
    } else {
        Number* aux = *li;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = node;
    }
    return 1;
}
int insertSum(List* li, int num){
    if(li == NULL) 
        return 0;
    Number* node = (Number*) malloc(sizeof(Number));
    if(node == NULL) return 0;
    node->digit = num;
    node->next = (*li);
    *li = node;
    return 1;
}
void imprime_lista(List* li){
    Number* no = *li;
    while(no != NULL){
        printf("%d ", no->digit);
        no = no->next;
    }
}
int remove_lista_final(List* li){
    if(li==NULL)
        return 0;
    if(*li == NULL)
        return 0;
    Number *ant, *node = *li;
    while(node->next != NULL){
        ant = node;
        node = node->next;
    }
    if(node == *li)
        *li = node->next;
    else 
        ant->next = node->next;
    free(node);
    return 1;
}

int sum(List* n1, List* n2, List* soma, int vaium){
    DBG printf("oi\n");
    imprime_lista(soma);
    printf("\n");
    if(n1==NULL && n2==NULL){
        return 0;
    }
    if((*n1) == NULL){
        insertSum(soma,(((*n2)->digit)%9)+vaium);
        remove_lista_final(n2);
        return 1;
    }
    if((*n2) == NULL){
        while((*n1) != NULL){
            insertSum(soma, (((*n1)->digit)%9)+vaium);
            remove_lista_final(n1);
        }
        return 1;
    }
    DBG printf("ola\n");
    Number* aux1 = *n1;
    Number* aux2 = *n2;

    while(aux1->next != NULL)
        aux1 = aux1->next;
    while(aux2->next != NULL)
        aux2 = aux2->next;
    int somar = aux1->digit + aux2->digit + vaium;

    printf("1: %d 2: %d soma: %d vaium: %d\n", aux1->digit, aux2->digit, somar, vaium);
    if(somar > 9) {
        DBG printf("oi 1\n");
        vaium = 1;
        insertSum(soma, somar%10);
    } else {
        DBG printf("oi 2\n");
        vaium = 0;
        insertSum(soma, somar);
    }
    remove_lista_final(n1);
    remove_lista_final(n2);
    sum(n1, n2, soma, vaium);
}
int main(){
    int num, vaium=0;
    List *number1;
    number1 = criaLista();
    List *number2;
    number2 = criaLista();
    List *soma;
    soma = criaLista();
    while(1){
        scanf("%d", &num);
        if(num == 43) break;
        insertDigit(number1, num);
    }
    while(1){
        scanf("%d", &num);
        if(num == 61) break;
        insertDigit(number2, num);
    }
    if(*number1==NULL){
        if(*number2 == NULL){
            printf("Lista vazia!");
        } else {
            imprime_lista(number2);
        }
    } else if(*number2==NULL){
        if(*number1 == NULL){
            printf("Lista vazia!");
        } else {
            imprime_lista(number1);
        }
    } else {
        sum(number1, number2, soma, vaium);
        imprime_lista(soma);
    }
}