struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
struct aluno V[6];

void insertionSortMatricula(struct aluno *V, int size){
    int i, j;
    struct aluno aux;
    for(i = 1; i< size; i++){
        aux = V[i];
        for(j=i; (j>0) && (aux.matricula<V[j-1].matricula); j--)
            V[j] = V[j-1];
        V[j] = aux;
    }
}

// saida strcmp(str1, str2)
// == 0: str1 é igual a str2
// > 0: str1 vem depois de str2
// < 0: str1 vem antes de str2

void insertionSortNome(struct aluno *V, int size){
    int i, j;
    struct aluno aux;
    for(i = 1; i < size; i++){
        aux = V[i];
        for(j=1; (j>0) && (strcmp(aux.nome, V[j-1].nome)<0);j--)
            V[j] = V[j-1];
        V[j] = aux;
    }
}
