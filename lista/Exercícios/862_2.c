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
int insere_lista_final(Lista* li, char number){
    if(li==NULL) // verifica se a lista existe
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) // verifica s o nó foi alocado certo
        return 0;
    node->number = number; // atribui os valores que eu quero inserir nesse novo nó
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
int maiorSequencia(Lista* li){
    int cont=0, maior=0, indiceFinal=0, indiceInicio=0, tamanho=0;
    if(li == NULL)
        return 0;
    Elem *node = *li;
    while(node != NULL){ // percorrendo ela todinha
        tamanho++;
        printf("oi");
        if (node->number == 49 || node->number == 48){
            if(node->number == 48){
                cont++;
                if(cont > maior){
                    maior = cont;
                    indiceFinal = tamanho - 1;
                }
            }
            else{
                cont = 0;
            } 
        }
        
        node = node->next;
    }
    indiceInicio = indiceFinal - maior;
    if(maior != 0) indiceInicio += 1;
    printf("%d %d %d %d", indiceInicio, indiceFinal, maior, tamanho);

}
int main(){
    Lista* li = cria_lista();
    char number;
    while(scanf("%c", &number) != EOF){
        printf("aq:: %c\n", number);
        insere_lista_final(li, number);
    }
    maiorSequencia(li);
    return 0;
}