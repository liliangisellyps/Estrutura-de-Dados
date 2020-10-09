#include <stdio.h>
#include "Grafo.h"

struct grafo{
    int eh_ponderado;
    int num_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};
// Grafo *gr 

Grafo *criaGrafo(int num_vertices, int grau_max, int eh_ponderado){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->num_vertices = num_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*)calloc(num_vertices, sizeof(int));
        // matriz arestas
        gr->arestas = (int**)malloc(num_vertices*sizeof(int*));
        for(i=0; i<num_vertices; i++)
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
            // mastriz de pesos
            if(gr->eh_ponderado){
                gr->pesos=(float**)malloc(num_vertices*sizeof(float*));

                for(i=0; i<num_vertices; i++)
                    gr->pesos[i] = (float*)malloc(grau_max* sizeof(float));
            }
    }
    return gr;
}
//gr = criaGrafo(10, 7, 0); por ex

void liberaGrafo(Grafo* gr){
    if(gr != NULL){
        int i;
        // libera matriz arestas
        for(i=0; i<gr->num_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas[i]);

        //libera matriz de pesos
        if(gr->eh_ponderado){
            for(i=0; i<gr->num_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}
//liberaGrafo(gr);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    // verifica se o vertice existe
    if(orig < 0 || orig >= gr->num_vertices)
        return 0;
    if(dest < 0 || dest >= gr->num_vertices)
        return 0;
    
    //insere no final da linha
    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    // insere outra aresta se nao for digrafo
    if(eh_digrafo == 0)
        insereAresta(gr, dest, orig, 1, peso);
    return 1;
}
// insereAresta(gr, 0, 1, 0, 0);
// insereAresta(gr, 1, 3, 0, 0);

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;

    //verifica se o vertice existe
    if(orig < 0 || orig >= gr->num_vertices)
        return 0;
    if(dest < 0 || dest >= gr->num_vertices)
        return 0;

    // procura aresta
    int i = 0;
    while(i < gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig]) // elemento nao encontrado
        return 0;
    // c
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] - gr->pesos[orig][gr->grau[orig]];
    
    // remove outra aresta se nao for digrafo
    if(eh_digrafo == 0)
        removeAresta(gr, dest, orig, 1);
    return 1;
}
