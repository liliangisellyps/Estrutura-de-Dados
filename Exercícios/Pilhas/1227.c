#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _node* STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _node
{
    int element;
    NODE* next;
};
//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k, e;
    scanf("%d%c", &k, &e);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d%c", &k, &e);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
STACK* Create_stack(){
    STACK* pi = (STACK*) malloc(sizeof(STACK));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}
int IS_EMPTY(STACK* stack){
    if(stack == NULL)
        return 1;
    if((*stack) == NULL)
        return 1;
    return 0;
}
int POP(STACK* stack){
    if(stack == NULL) return -1;
    if((*stack) == NULL) return -1;
    NODE *node = *stack;
    return node->element;
}
void PUSH(STACK* stack, int element){
    if(stack == NULL) return;
    NODE* node = (NODE*) malloc(sizeof(NODE));
    if(node == NULL) return;
    node->element = element;
    node->next = (*stack);
    *stack = node;
}
void result(STACK* stack, char operation){
    int element1 = POP(stack);
    NODE *node = *stack;
    *stack = node->next;
    free(node);
    int element2 = POP(stack);

    if(operation == '+') (*stack)->element = element2 + element1;
    if(operation == '-') (*stack)->element = element2 - element1;
    if(operation == '/') (*stack)->element = element2/element1;
    if(operation == '*') (*stack)->element = element2*element1;
}
void Calculadora(STACK* calculadora, int size){
    *calculadora = NULL;
    int i;
    char element;
    for(i=0; i<size; i++){
        scanf("%c ", &element);
        if(element != '+' && element != '-' && element != '/' && element != '*'){
            PUSH(calculadora, element-48);
        } else result(calculadora, element);
    }
}