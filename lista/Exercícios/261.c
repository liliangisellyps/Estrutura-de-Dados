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
int insere_lista_final(Lista* li, int x){
    if(li==NULL) // verifica se a lista existe
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) // verifica s o nó foi alocado certo
        return 0;
    node->number = x; // atribui os valores que eu quero inserir nesse novo nó
    node->next = NULL;
    if(*li == NULL){ 
        *li = node; // saco a lista esteja vazia, ele atribui no primeiro lugar
    } else {
        Elem* aux = *li;
        while(aux->next != NULL)
            aux = aux->next; // procura através do auxiliar o ultimo elemento da lista
        aux->next = node; // por fim, insere
    }
    return 1;
}
void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("%d\n", no->number);
        no = no->next;
    }
}
int compara_listas(Lista* li, Lista* li2){
    if(li2 == NULL){
        return 1;
    }
    else if(li == NULL)
        return 0;
    else {
        Elem *node = *li;
        Elem *node2 = *li2;
        while(node != NULL){
            while(node2 != NULL){
                if(node2 != NULL && node->number != node2->number)
                    node2 = node2->next;
            }
            if(node2 == NULL) // chegou ao final da lista e nao encontrou
                return 0;
            else{
                node = node->next;
                Elem *node2 = *li2; 
            }
        }
    }
    
    return 1;
}
int main(){
    Lista *li = cria_lista();
    Lista *li2 = cria_lista();
    int n, m, i, x, y;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &x);
        insere_lista_final(li, x);
    }
    scanf("%d", &m);
    for(i=0; i<n; i++){
        scanf("%d", &y);
        insere_lista_final(li2, y);
    }
    // imprime_lista(li);
    // imprime_lista(li2);
    compara_listas(li, li2);
    return 0;
}