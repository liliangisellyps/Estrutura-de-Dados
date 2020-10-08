// busca linear compara um por um ate encontrar um que seja igual ou alcançar o tamanho do array
int buscaLinear(int *V, int size, int elem){
    int i;
    for(i=0; i<size; i++){
        if(elem == V[i])
            return i;// elemento encontrado
    }
    return -1; // elemento nao encontrado
}

// burca ordenada compara ate que o elemento seja menor que o atual, afinal esta ordenado
int buscaOrdenada(int *V, int size, int elem){
    int i;
    for(i=0; i<size; i++){
        if(elem == V[i])
            return i;// elemento encontrado
        else
            if(elem < V[i])
                return -1; // para a busca
    }
    return -1; // elemento nao encontrado
}
// busca binaria compara achando o meio, sempre dividindo a quantidade de elementos a serem comparados pela metade
int buscaBinaria(int *V, int size, int elem){
    int i, inicio, meio, final;
    inicio = 0;
    final = size - 1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if(elem < V[meio])
            final = meio-1; // busca a metade da esquerda
        else
            if(elem > V[meio])
                inicio = meio+1; // busca a metade da direita
            else 
                return meio;      
    }
    return -1; // elemento nao encontrado
}


