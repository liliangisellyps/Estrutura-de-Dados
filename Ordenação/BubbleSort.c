#include <stdio.h>
#include <stdlib.h>

// Compara pares de elementos adjacentes e os troca de lugar
// se estiverem na ordem errada

// Esse processo se repete até que mais nenhuma
// troca seja necessária (elementos já ordenados)

// Performance:
//     - Melhor Caso: O(N) - elementos já ordenados só precisou percorrer 1 vez e nao fazer nenhuma troca
//     - Pior Caso: O(N^2) 
//     - Não recomendado para grandes conjuntos de dados

void bubbleSort(int *V, int size){
    int i, continua, aux, fim = size;
    // continua é uma flag
    do {
        continua = 0;
        for(i=0; i<fim-1; i++){
            if(V[i] > V[i+1]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}

void bubbleSort (int *V, int size) {
    int i, j, aux;

    for (j = 0; j < size - 1; j++) {
        printf("\n[%d] ", j);
        
        for (i = 0; i < (size - 1) - j; i++) {
            printf("%d, ", i);

            if (V[i] > V[i + 1]) {
                aux = V[i];
                V[i] = V[i + 1];
                V[i + 1] = aux;
            }
        }
    }
}