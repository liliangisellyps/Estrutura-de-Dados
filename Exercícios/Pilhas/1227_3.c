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

void printStack(STACK *s);

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
//Insira o código aqui
STACK* Create_stack(){
    STACK* s =(STACK*) malloc(sizeof(STACK));
    s->head=NULL;
    return s;
}

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->element = element;
    newNode->next = NULL;
    return newNode;
}

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack){
    if(stack->head == NULL)
        return 1;
    return 0;
}

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack){
    if(IS_EMPTY(stack)){
        printf("Can't pop when there isn't a node!\n");
        return -1;
    }else{
        NODE *peek = stack->head;
        stack->head = peek->next;
        peek->next = NULL;
        return peek->element;
    }
}

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element){
    NODE* node = create_node(element);
    node->next = stack->head;
    stack->head = node;
}

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation){
    int element1 = POP(stack);
    int element2 = POP(stack);
    // printf("el: %d el2: %d\n", element1, element2);
    // printf("res: %c %d\n", operation, operation-48);

    if(operation == '+') PUSH(stack, element2 + element1);
    if(operation == '-') PUSH(stack, element2 - element1);
    if(operation == '/') PUSH(stack, element2/element1);
    if(operation == '*') PUSH(stack, element2*element1);
}

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size){
    char e;
    scanf("%c ", &e);
    int i;
    char el;
    char element[99];
    for(i=0; i<size; ++i){
        scanf("%s", element);
        // printf("%s\n", element, atoi(element));
        if(atoi(element) != 0){
            PUSH(calculadora, atoi(element));
        } else {
            result(calculadora, element[0]);
        }
    }
}

// void printStack(STACK *s){
//     if(IS_EMPTY(s)){
//         printf("Empty Stack!\n");
//     }else{
//         NODE *head = s->head;
//         while(head!=NULL){
//             printf("%d -> ", (head->element));
//             head = head->next;
//         }
//         printf(" NULL\n");
//     }
// }