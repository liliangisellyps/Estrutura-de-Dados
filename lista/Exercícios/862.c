#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char x[9999];
    while (1){
        scanf("%s", &x);
        if(strlen(x) == 1 && x[0] == 48)
            break;
        //printf("tam: %d %c\n", strlen(x), x[0]);
        int cont = 0, maior = 0, i, indiceFinal=0, indiceInicio=0;

        for(i=0;i<strlen(x);++i){
            //printf("%c ", x[i]);
            //printf("hm");
            if(x[i] == 48){
               // printf("entre aqui");
                cont++;
                if(cont > maior){
                    maior = cont;
                    indiceFinal = i;
                }
            }
            else{
                cont = 0;
            }
        }

        indiceInicio = indiceFinal - maior;
        if(maior != 0) indiceInicio += 1;
        printf("%d %d\n", indiceInicio, indiceFinal);
    }

}