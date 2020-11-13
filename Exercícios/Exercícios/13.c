#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main (){
    int i;
    char* linha = (char*) malloc(sizeof(char));

    while(gets(linha)){
        if(strcmp("the end!", linha) != 0){
           for(i=0; i<(strlen(linha)); i++){
            printf("%c", toupper(linha[i]));
           }
           printf("\n");
        } else break;
    }
    return 0;
}