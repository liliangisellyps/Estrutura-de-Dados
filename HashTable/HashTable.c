#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

struct hash{
    int qtd, tableSize;
    struct aluno **itens;
};

Hash* createHash(int tableSize){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
        ha->tableSize = tableSize;
        ha->itens = (struct aluno**) malloc(tableSize * sizeof(struct aluno*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i < ha->tableSize; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}
// Hash* ha = createHash(1427);

void deleteHash(Hash* ha){
    if(ha != NULL){
        if(ha != NULL){
            int i;
            for(i=0; i < ha->tableSize; i++){
                if(ha->itens[i] != NULL)
                    free(ha->itens[i]);
            }
            free(ha->itens);
            free(ha);
        }
    }
}

// deleteHash(ha);

int insertHashWOColision(Hash* ha, struct aluno* al){
    if(ha == NULL || ha->qtd == ha->tableSize)
        return 0;

    int chave = (*al).matricula;
    //int chave = valorString(al.nome);

    int pos = chaveDivisao(chave, ha->tableSize);
    struct aluno* novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL)
        return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int searchHashWOColision(Hash* ha, int mat, struct aluno* al){
    if(ha == NULL)
        return 0;

    int pos = chaveDivisao(mat,ha->tableSize);
    if(ha->itens[pos] == NULL)
        return 0;
    *al = *(ha->itens[pos]);
    return 1;
}