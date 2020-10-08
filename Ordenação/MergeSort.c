#include <stdio.h>

void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                //comparando as duas metades e combinando de forma ordenada
                if(V[p1] < V[p2])
                    temp[i] = V[p1++];
                else 
                    temp[i] = V[p2++];
                
                // se o vetor acabar
                if(p1>meio) fim1 = 1;
                if(p2>fim) fim2 = 1;
            } else {
                // copia o que sobrar
                if(!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
            }
        }
        // copia do auxiliar pro original
        for(j=0, k=inicio; j<tamanho; j++, k++)
            V[k] = temp[j];
    }
    free(temp);
}


void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V, inicio, meio); // chama função para as 2 metades
        mergeSort(V, meio+1, fim);
        merge(V, inicio, meio, fim); // combina as duas metades de forma ordenada
    }
}