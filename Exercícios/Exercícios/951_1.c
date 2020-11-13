#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct matriz Matriz;
#define DBG if(0)
#define REP(i,n) for(int i=0;i<(n);i++)
struct matriz
{
  char mat[257][257];
  int path[8]; //8 Caminhos , sem o 0 do supeito (+1 posição caso queira)
  int cont;
};

void solve(Matriz m, int li, int lf, int ci, int cf)
{
  DBG printf("( %d %d %d %d )\n", li, lf, ci, cf);
  
  if(li==lf && ci == cf)
  {
    if(m.mat[li][ci]=='*'){
      int i;
      for(i=0; i<m.cont; i++){
        printf("%d", m.path[i]);
      }
      printf("0\n");
    }
    // IMPRIME CAMINHO E IMPRIME '0';
    // COLOCA 0 E IMPRIME CAMINHO;
    return;
  }
  else
  {
      
    DBG printf("1 ->\n");
    // ADICIONA 1 EM PATH[CONTADOR];
    // ADICIONA CONTADOR DO CAMINHO;
    m.path[m.cont] = 1;
    m.cont++;
    solve(m, li, (lf+li)/2, (cf+ci+1)/2, cf);
    m.cont--;
    // TIRA 1 EM PATH[CONTADOR];
    // ADICIONA 2 EM PATH[CONTADOR];
    m.path[m.cont] = 2;
    m.cont++;
    DBG printf("2 ->\n");
    solve(m,li, (lf+li)/2, ci, (ci+cf)/2);
    // TIRA 2 EM PATH[CONTADOR];
    // ADICIONA 3 EM PATH[CONTADOR];
    m.cont--;
    m.path[m.cont] = 3;
    m.cont++;
    DBG printf("3 ->\n");
    solve(m,(lf+li+1)/2, lf, ci, (ci+cf)/2);
    // TIRA 3 EM PATH[CONTADOR];
    // ADICIONA 4 EM PATH[CONTADOR];
    m.cont--;
    m.path[m.cont] = 4;
    m.cont++;
    DBG printf("4 ->\n");
    solve(m,(lf+li+1)/2, lf , (cf+ci+1)/2, cf);
    m.cont--;

    // REMOVER 4 EM PATH[CONTADOR];
  }
  
}
int main(){
  int n, i, j;
  scanf("%d", &n);
  Matriz m;
  m.cont = 0;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      scanf(" %c", &m.mat[i][j]);
    }
  }
  solve(m, 0, n-1, 0, n-1);
}
// lin inicial , lin final, col inicial, col final