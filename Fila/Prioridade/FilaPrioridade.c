#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h"

struct data {
    char nome[30];
    int prio;
};

struct filaPrioridade {
    int tam;
    struct data dados[MAX];
};

// IMPLEMENTAÇÃO DAS SEGUINTES FUNÇÕES É 
//IGUAL A DE LISTA SEQUENCIAL ESTATICA:
// criação, liberação, tamaho, estacheia, estavazia


// fila de prioridade com array ordenado
insercaoFPAO(FilaPrio* fp, char *nome, int prio){
    if(fp == NULL) return 0;
    if(fp->qtd == MAX) return 0; // fila cheia 

    int i = fp->qtd-1;
    while(i >= 0 && fp->dados[i].prio >= prio){
        fp->dados[i+1] = fp->dados[i];
        i--;
    }
    strcpy(sp->dados[i+1].nome, nome);
    fp->dados[i+1].prio = prio;
    fp->qtd++;
    return 1;
}

remocaoFPAO(FilaPrio* fp){
    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;
    fp->qtd--;
    return 1;
}

consultaFPAO(FilaPrio* fp, char* nome){ // consulta do ultimo elemento
    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome, fp->dados[fp->qtd-1].nome);
    return 1;
}

// fila de prioridade com heap binaria

void priorizarElemento(ElementoFilaPrio* fp, int filho){
    int pai;
    struct data temp;
    pai = (filho - 1) / 2;
    while((filho > 0) &&
          (fp->dadps[pai].prio <= fp->dados[filho].prio)){
              
            temp = fp->dados[filho];
            fp->dados[filho] = fp->dados[pai];
            fp->dados[pai] = temp;
            filho = pai;
            pai = (pai - 1) / 2;
        }
    
}
int insereFPHB(FilaPrio* fp, char *nome, int prio){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)
        return 0;
    strcpy(fp->dados[fp->qtd].nome, nome);
    fp->dados[fp->qtd].prio = prio;
    priorizarElemento(fp, fp->qtd);
    fp->qtd++;
    return 1;
}

void rebaixarElemento(FilaPrio* fp, int pai){
    struct data temp;
    int filho = 2 * pai + 1;
    while(filho < fp->qtd){
        if(filho < fp->qtd)
            if(fp->dados[filho].prio < fp->dados[filho+1].prio)
                filho++;
        
        if(fp->dados[pai].prio >= fp->dados[filho].prio)
            break;

        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1;
    }
}
int remocaoFPHB(FilaPrio* fp){
    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;
    
    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    rebaixarElemento(fp, 0);
    return 1;
}

int consultaFPHB(FilaPrio* fp, char* nome){
    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome, fp->dados[0].nome);
    return 1;
}