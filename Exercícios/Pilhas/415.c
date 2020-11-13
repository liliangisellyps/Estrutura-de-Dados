#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)
struct elemento{
    char c;
    struct elemento *next;
};
typedef struct elemento Elem;
typedef struct elemento* Pilha;

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}
isInvalid(char c){
    if(c != ')' && c != '(' && c != ']' && c != '[' && c != ' '){
        DBG printf("inválido!\n", c);
        return 1;
    }
    else return 0;
}
void push(Pilha* pi, char c){
    if(pi == NULL) return;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) return;
    node->c = c;
    node->next = (*pi);
    *pi = node;
    DBG printf("\npush!\n");

}
int pop(Pilha* pi){
    if(pi == NULL) return -1;
    if((*pi) == NULL) return -1;
    Elem *node = *pi;
    *pi = node->next;
    DBG printf("\npop!\n");
    free(node);
    return 0;
}
int pilhaVazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if((*pi) == NULL)
        return 1;
    return 0;
}
void imprimir(Pilha* pi) {
    Elem *node = *pi;
    while (node) {
        printf("%c ", node->c);
        node = node->next;
    }
    printf("\n");
}
int tamanhoPilha(Pilha* pi){
    if(pi == NULL) return 0;
    int cont = 0;
    Elem* node = *pi;
    while(node != NULL){
        cont++;
        node = node->next;
    }
    return cont;
}
int main(){
    int n, i;
    scanf("%d", &n);
    char ch;
    ch = getchar();
    for(i=0; i<n; i++){
        int invalid=0;
        Pilha *piP;
        piP = cria_pilha();
        Pilha *piC;
        piC = cria_pilha();
        while(1){
            ch = getchar();
            if(!isInvalid(ch)){
                DBG printf("%c", ch);
                if(ch == '(') push(piP, ch);
                if(ch == ')') {
                   if(pop(piP) != 0) {
                        invalid = 1;
                   }
                }
                if(ch == '[') push(piC, ch);
                if(ch == ']'){
                    if(pop(piC) != 0) {
                        invalid = 1;
                   }
                }
            } else break;
        }
        DBG printf("\n%d %d\n", tamanhoPilha(piP), tamanhoPilha(piC));
        if(pilhaVazia(piP) && pilhaVazia(piC) && invalid == 0)
            printf("Yes\n");
        else 
            printf("No\n");
    }
}