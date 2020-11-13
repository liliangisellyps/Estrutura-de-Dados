#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)
typedef struct a A;
int max(int a, int b) {return (a>b) ? a:b; }
int min(int a, int b) {return (a<b) ? a:b; }
void swap(int *a, int *b) {int c = *a; *a = *b; *b = c;}

struct elementoLi{
    int num;
    struct elementoLi *next;
};
typedef struct elementoLi ElemLi;
typedef struct elementoLi* Lista;

struct elementoPi{
    Lista* li;
    struct elementoPi *next;
};
typedef struct elementoPi ElemPi;
typedef struct elementoPi* Pilha;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}
void insertList(Lista* li, int x){
    if(li==NULL) // verifica se a lista existe
        return;
    ElemLi* node = (ElemLi*) malloc(sizeof(ElemLi));
    if(node == NULL) // verifica s o nó foi alocado certo
        return;
    node->num = x; // atribui os valores que eu quero inserir nesse novo nó
    node->next = NULL;
    if(*li == NULL){ 
        *li = node; // saco a lista esteja vazia, ele atribui no primeiro lugar
    } else {
        ElemLi* aux = *li;
        while(aux->next != NULL)
            aux = aux->next; // procura através do auxiliar o ultimo elemento da lista
        aux->next = node; // por fim, insere
    }
    return;
}
void imprimeLista(Lista* li){
    if(li == NULL)
        return;
    ElemLi* no = *li;
    while(no != NULL){
        printf("%d",no->num);
        no = no->next;
        if(no != NULL) printf(" ");
    }
}
void imprimePilha(Pilha* pi) {
    ElemPi *no = *pi;
    imprimeLista(no->li);
    printf("\n");
}
int push(Pilha* pi, Lista* li){
    if(pi == NULL) return  0;
    ElemPi* node = (ElemPi*) malloc(sizeof(ElemPi));
    if(node == NULL) return 0;
    node->li = li;
    node->next = (*pi);
    *pi = node;
    return 1;
}
int pop(Pilha* pi){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;
    ElemPi *node = *pi;
    *pi = node->next;
    free(node);
    return 1;
}
int pilhaVazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if((*pi) == NULL)
        return 1;
    return 0;
}
int main(){
    Pilha *pi;
    pi = cria_pilha();
    char comando[5];
    while(gets(comando)){
        if(strcmp(comando, "PUSH") == 0){
            int num;
            char c;
            Lista *li;
            li = cria_lista();
            while(1){
                scanf("%d%c", &num, &c);
                insertList(li, num);
                if(c != 32) break;
            }
            // printf("lista-> ");
            // imprimeLista(li);
            // printf("\n");         
            push(pi, li);

            // printf("pilha-> ");
            // imprimePilha(pi);
            // printf("\n");
        } else if (strcmp(comando, "POP") == 0){
            if(pilhaVazia(pi)) printf("EMPTY STACK\n");
            else {
                imprimePilha(pi);
                pop(pi);
            }
        }
    }    
}