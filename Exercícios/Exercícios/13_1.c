#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char *text = (char *)malloc((75) * sizeof(char));
    fgets(text, 75, stdin);
    while(strcmp(text, "the end!\n") != 0){
        int i, pos=strlen(text);
        for(i = 0 ; i < pos ; i++){
            text[i] = toupper(text[i]);
        }
        printf("%s", text);
        fgets(text, 75, stdin);
    }
    free(text);
    return 0;
}