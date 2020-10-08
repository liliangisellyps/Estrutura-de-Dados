void insertionSort(int *V, int size){
    int i, j, aux;
    for(i=1; i<size; i++){
        aux = V[i];
        for(j=i; (j>0) && (aux < V[j-1]); j--)
            V[j] = V[j-1];
        V[j] = aux;
    }
}
// desloca todo mundo que for maior que o elemento 1 casa para frente
// e insere no lugar que ficou vazio