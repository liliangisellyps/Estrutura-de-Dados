// A cada passo, procura-se o menor valor do array e o coloca na primeira posição do array.
// Descarta-se a primeira posição do array e repete-se o processo para a segunda posição 
// Isso é feito para todas as posições do array
// ordenação por seleção: ele seleciona o menor número e coloca 
// posições do array

void selectionSort (int *V, int size){
    int i, j, menor, aux;
    for(i=0; i<size-1; i++){
        menor = i;
        for(j = i+1; j<size; j++){
            if(V[j] < V[menor])
                menor = j;
        }
        if(i != menor){
            aux = V[i];
            V[i] = V[menor];
            V[menor] = aux;
        }
    }
}