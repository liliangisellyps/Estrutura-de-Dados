int buscaLinearMatricula(struct aluno *V, int size, int elem){
    int i;
    for(i=0; i<size; i++){
        if(elem == V[i].matricula)
            return i;// elemento encontrado
    }
    return -1; // elemento nao encontrado
}

int buscaLinearNome(struct aluno *V, int size, int elem){
    int i;
    for(i=0; i<N; i++){
        if(strcmp(elem, V[i].nome) == 0)
            return i;// elemento encontrado
    }
    return -1; // eSlemento nao encontrado
}