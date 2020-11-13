#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void descrip(char* mensagem, int j){
    if(strlen(mensagem) == 0) return;
    if(mensagem[0] == '*'){
        printf("(%d", j+1);
        descrip(&mensagem[1], j+1);
        printf(")");
    }
    else{
        printf("%d", j+1);
        descrip(&mensagem[1], j+1);
    }
}

int main() {
    int i = 0;
    char mensagem[100];
    char *str;
    scanf("%s", mensagem);
    descrip(mensagem, 0);
	return 0;
}