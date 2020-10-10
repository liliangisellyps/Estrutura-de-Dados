#include "Grafo.h"
#include "Grafo.c"

// Busca em largura

void buscaLargura(Grafo *gr, int ini, int *visitado){
    int i, vert, NV, cont=1, *fila, IF=0, FF=0; // nv= nao visitado, if= inicio da fila, ff=
    for(i=0; i<gr->num_vertices; i++)
        visitado[i] = 0;
    // cria fila, visita e insere "ini" nela
    NV = gr->num_vertices;
    fila = (int*) malloc(NV * sizeof(int)); // guardar a ordem q visitei os vértices
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;
    while(IF != FF){
        // pega o primeiro da fila"
        IF = (IF + 1) % NV;
        vert = fila[IF];
        cont++;
        // visita os vizinhos ainda nao visitados e coloca na fila
        for(i=0; i<gr->grau[vert]; i++){
            if(!visitado[gr->arestas[vert][i]]){
                FF = (FF + 1) % NV;
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
}