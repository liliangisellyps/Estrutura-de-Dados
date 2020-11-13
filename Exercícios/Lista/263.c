#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long int li;
typedef struct lista Lista;
int max(int a, int b) {return (a>b) ? a:b; }
int min(int a, int b) {return (a<b) ? a:b; }
void swap(int *a, int *b) {int c = *a; *a = *b; *b = c;}
struct lista {
    int num[20];
    int indice;
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*)malloc(sizeof(struct lista));
    if(li != NULL)
        li->indice = 0;
    return li;
}
int insereLista(Lista* li, int num){
    if(li==NULL)
        return 0;
    li->num[li->indice] = num;
    li->indice++;
    return 1;
}
int insere_lista_ordenada(Lista* li, int num){
    if(li==NULL)
        return 0;
    int k, i = 0;
    while(i<li->indice && li->num[i] < num)
        i++;
    if(li->num[i] == num){
        DBG printf("li-> %d e num-> %d sao iguais! i: %d\n", li->num[i], num, i);
        return 1;
    } 
    for(k=li->indice-1; k>=i; k--)
        li->num[k+1] = li->num[k];
    li->num[i] = num;
    li->indice++;
    return 1;
}

int imprimeLista(Lista* li){
    if(li->indice == 0)
        printf("VAZIO");
    int k = 0;
    for(k=0; k<li->indice; k++){
        printf("%d\n", li->num[k]);
    }
    return 1;
}
int intersec(Lista* li1, Lista* li2, Lista *intersec){
    if(li1==NULL || li2==NULL)
        return 0;
    int i, j;
    for (i = 0; i < 20; i++){
  	  for (j = 0; j < 20; j++){
            if(li1->num[i] == li2->num[j]){
               insere_lista_ordenada(intersec, li1->num[i]);
            }
        }
    }
    return 1;
}
int main(){
    int num, i;
    Lista *li1;
    li1 = cria_lista();
    Lista *li2;
    li2 = cria_lista();
    Lista *li3;
    li3 = cria_lista();
    for(i=0; i<20; i++){
        scanf("%d", &num);
        insereLista(li1, num);
    }
    for(i=0; i<20; i++){
        scanf("%d", &num);
        insereLista(li2, num);
    }
    intersec(li1, li2, li3);
    imprimeLista(li3);

}