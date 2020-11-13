#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)
#define MAX_SIZE 256
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long int li;

typedef struct point {
    char matriz[MAX_SIZE][MAX_SIZE];
    char path[MAX_SIZE];
    int currentLin;
    int currentCol;
    int finalLin;
    int finalCol;
    int quadrante;
} Point;

int isSuspect (Point point){
    if (point.matriz[point.currentLin][point.currentCol] == '*') return 1;
    else return 0;
}
int isTheEnd (Point point){
    if (point.currentLin == point.finalLin && point.currentCol == point.finalCol) return 1;
    else return 0;
}
Point mudandoQuadrante(Point point, int t){
    if(point.quadrante == 1) point.currentCol -= (t/2);
    if(point.quadrante == 2) point.currentLin += (t/2);
    if(point.quadrante == 3) point.currentCol += (t/2);
    return point;
}
int focus(Point point, int t, int p){
    printf("point.quadrante: %d\nlinha: %d\ncoluna: %d\n\n", point.quadrante, point.currentLin, point.currentCol);
    if(isSuspect(point)){
        point.path[p] = point.quadrante;
        printf("penultimo: caminho: %d\np: %d\n", point.path[p], p);
        p += 1;
        point.path[p] = 0;
        printf("acabou: caminho: %d\np: %d\n", point.path[p], p);
        return;
    } else if (t == 2){
        point = mudandoQuadrante(point, t);
        printf("caminho: %d\np: %d\n\n", point.path[p], p);
        if(point.quadrante == 4) return;
        point.quadrante++;
        focus(point, t, p);
    } else {
        mudandoQuadrante(point, t);
        point.quadrante++;
        focus(point, t/2, p);
        int quadranteMaior;
        quadranteMaior = point.quadrante;
        if(quadranteMaior == 4) return;
        quadranteMaior++;
    }

}
int main(){
    int t, i, j;
    scanf("%d", &t);
    Point point;
    for(i=0; i<t; i++){
        for(j=0; j<t; j++){
            scanf(" %c", &point.matriz[i][j]);
        }
    }
    DBG for(i=0; i<t; i++){
        for(j=0; j<t; j++){
            printf("%c", point.matriz[i][j]);
        }
    }
    point.currentLin = 0; // inicializando no primeiro quadrante
    point.currentCol = t - 1;
    point.finalLin = t - 1;
    point.finalCol = t - 1; 
    point.quadrante = 1;
    int p = 0;
    focus(point, t, p);
}