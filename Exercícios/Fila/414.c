#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)
typedef struct fila Fila;

struct fila{
    int inicio, final, tam, x;
    long long int dados[1005];
};

Fila* criaFila(){
    Fila *fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->tam = 0;
    }
    return fi;
}

int insereFila(Fila* fi, long long int nota){
    if(fi == NULL) return 0;
    if(fi->tam == 1005) return 0;
    fi->dados[fi->final] = nota;
    fi->final = (fi->final+1)%1005;
    fi->tam++;
    return 1;
}
void printQueue(Fila* fi){
    int i;
    for (i = 0; i < fi->tam; i++) {
        printf( "item at position %d is %d\n", i, fi->dados[i]);
    }
}
int bubbleSort(Fila* fi){
    int i, continua, fim = fi->tam, notChanged=0, array[fi->tam];
    for(i=0; i<fi->tam; i++){
        array[i] = 0;
    }
    Fila* aux = (Fila*) malloc(sizeof(Fila));
    do {
        continua = 0;
        for(i=0; i<fim-1; i++){
            if(fi->dados[i] < fi->dados[i+1]){
                aux->dados[i] = fi->dados[i];
                fi->dados[i] = fi->dados[i+1];
                fi->dados[i+1] = aux->dados[i];
                continua = i;
                array[i]++;
                if(i != 997) array[i+1]++;
            }
        }
        fim--;
    }while(continua != 0);

    for(i=0; i<fi->tam; i++){
        if(array[i] == 0) notChanged++;
    }
    return notChanged;
}
int main(){
    long long n, i;
    scanf("%lli", &n);
    for(i=0; i<n; i++){
        long long int x, j, nota;
        scanf("%lli", &x);
        Fila *fi;
        fi = criaFila();
        for(j=0; j<x; j++){
            scanf("%lli", &nota);
            insereFila(fi, nota);
        }
        DBG printQueue(fi);
        int notChanged = bubbleSort(fi);
        DBG printQueue(fi);
        printf("%d\n", notChanged);
    }
}