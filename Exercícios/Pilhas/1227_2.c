#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
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
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
STACK* Create_stack(){
    STACK* stack = (STACK*) malloc(sizeof(STACK));
    stack->head = NULL;
}
NODE* create_node(int element){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->element = element;
    newNode->next = NULL;
    return newNode;
}
int IS_EMPTY(STACK* stack){
    if(stack->head == NULL)
        return 1;
    return 0;
}
int POP(STACK* stack){
    printf("oi");
    printf("aa");
    if(IS_EMPTY(stack)) {
        printf("can't pop\n");
        return -1;
    }
    printf("aa");
    NODE* node = stack->head;
    stack->head = node->next;
    printf("aa");

    printf("%d\n", node->element);
    
    return node->element;
}
void PUSH(STACK* stack, int element){
    printf("aa");
    NODE* node = create_node(element);
    printf("aa");
    node->next = stack->head;
    stack->head = node;
    printf("aa");

}
void result(STACK* stack, char operation){
    printf("op: %c\n", operation);
    NODE* node = stack->head;
    int element1 = node->element;
    int element2 = POP(stack);
    printf("el1: %d el2: %d\n", element1, element2);


    if(operation == '+') stack->head->element = element2 + element1;
    if(operation == '-') stack->head->element = element2 - element1;
    if(operation == '/') stack->head->element = element2/element1;
    if(operation == '*') stack->head->element = element2*element1;
}
void Calculadora(STACK* calculadora, int size){
    int ignore;
    scanf("%c", &ignore);
    calculadora = NULL;
    int i;
    char element;
    for(i=0; i<size; i++){
        scanf("%c ", &element);
        printf("%d i: %d\n", element-48, i);
        if(element != '+' && element != '-' && element != '/' && element != '*'){
            PUSH(calculadora, element-48);
        } else result(calculadora, element);
    }
}
