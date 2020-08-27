#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct elemento{
    char caracter;
    int freq;
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
int inserir_lista(Lista* li, char letra){
    if(li == NULL)
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    node->caracter = letra;

    if(lista_vazia(li)){
        node->next = (*li);
        *li = node;
        node->freq = 1;
        return 1;
    } else  {
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->caracter != letra){ // procurando se a letra ja apareceu
            ant = atual;
            atual = atual->next;
        }
        if (atual == NULL) { // nao achei que eu queria
            Elem *atual = *li;
            while(atual != NULL && (256+(atual->caracter))%256 > (256+(letra))%256){// o dado que eu eu tenho na lista seja menor que o que eu quero inserir
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
            node->freq = 1;
        } else { // achei quem eu quero
            atual->freq += 1;
        }
        return 1;
    }
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("%c %d %d\n", no->caracter, no->freq, no->caracter);
        no = no->next;
    }
}
int main(){
    Lista* li = cria_lista();
    char letra;
    // setlocale(LC_ALL, "");
    while(1){
        scanf(" %c", &letra);
        // printf("%c %d\n", letra, letra);
        //printf("%d ", letra);
        // printf("aq esta: %c ", letra);
        // printf("%d\n", letra);

        inserir_lista(li, letra);
        if(letra == 46) break;
    }
    imprime_lista(li);
    return 0;
}
// problemas: nao esta interpretando as letras com acento: talvez tenha que refazer
// e colocar como string 
// retirar essa consdição de break e colocar eof
// se colocar string talvez de pra tirar do while