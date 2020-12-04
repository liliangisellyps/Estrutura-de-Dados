#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

typedef struct stack Stack;
typedef struct node ListNode;
Stack *createStack();
void push(Stack *s,int data);
ListNode *pop(Stack *s);
ListNode *peek(Stack *s);
bool Empty(Stack *s);
void printStack(Stack *s);


struct node {
    ListNode *next;
    int data;
};

struct stack{
    ListNode *top;
    int size;
};


ListNode *createNode(int data) {
    ListNode newNode = (ListNode)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack *createStack(){
    Stack* s =(Stack*) malloc(sizeof(Stack));
    s->top=NULL;
    s->size=0;
    return s;
}

void push(Stack *s, int data){
    ListNode* newTop = (ListNode*) malloc(sizeof(ListNode));
    newTop->data = data;
    newTop->next = s->top;
    s->top = newTop;
    s->size++;
}

ListNode *pop(Stack *s){
    if(Empty(s)){
        printf("Can't pop when there isn't a node!\n");
        return NULL;
    }else{
        ListNode *peek = s->top;
        s->size--;
        s->top = peek->next;
        peek->next = NULL;
        return peek;
    }
}

ListNode *peek(Stack *s){
    if(!Empty(s)) return s->top;
    return NULL;
}

bool Empty(Stack *s){
    return s->size==0;
}

void printStack(Stack *s){
    if(Empty(s)){
        printf("Empty Stack!\n");
    }else{
        ListNode *head = s->top;
        while(head!=NULL){
            printf("%d -> ",head->data);
            head = head->next;
        }
        printf("\n");
    }
}

void insertEnd(ListNode **head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        ListNode *aux = *head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = createNode(data);
    }
}


int main(){
    Stack *s = createStack();
   
    char input[10];
    int valor;

    while(scanf("%s", input) != EOF){
        if(strcmp(input, "push") == 0){
            printf("PUSH\n");
            scanf("%d", &valor);
            push(s, valor);
        }
        if(strcmp(input, "pop") == 0){
            printf("POP\n");
            //printStack(s);
            //pop(s);
        }
    }
    printStack(s);

}