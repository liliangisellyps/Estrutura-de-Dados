void criaHeap(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1; // filho do pai
    while(j <= f){
        if(j<f){
            // pai tem 2 filhos? quem é o maior?
            if(vet[j] < vet[j+1]){
                j = j + 1;
            }
        }
        if(aux < vet[j]) {
            // filho maior que o pai?
            // filho se torna o pai.
            // repete o processo
            vet[i] = vet[j];
            i = j;
            j = i * 2 + 1;
        } else {
            j = f + 1;
        }
        // antigo pai ocupa o lugar do ultimo filho analisado
        vet[i] = aux;
    }
}

void heapSort(int *vet, int size){
    int i, aux;
    for(i=(size - 1)/2; i>=0; i--){
        criaHeap(vet, i, size-1); // criar heap a partir dos dados
    }
    for(i = size-1; i >= 1; i--){
        // pegar o maior elemento da heap e colocar na sua posição correspondente no array
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        // reconstruir a heap
        criaHeap(vet, 0, i-1);
    }
}