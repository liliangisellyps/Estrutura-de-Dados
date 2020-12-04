#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _deque deque_t;
typedef struct _node   node_t;

//Guarda um ponteiro pro node anterior, para o proximo node e o valor guardado
struct _node {
	node_t *prev;
  	node_t *next;
  	int    value;
};

//Guarda um ponteiro para o primeiro node, um ponteiro para o ultimo node, e o tamanho do deque
struct _deque {
  	node_t *front;
  	node_t  *rear;
  	int      size;
};

//Cria um node que guarda os valores que são enfileirados no deque
node_t*  node_new     (int value);

//Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t* construct    ();
//Libera a memória do conteúdo e do próprio deque
void     destruct     (deque_t *deque);

//Retorna o tamanho do deque
int      size         (deque_t *deque);
//Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool     empty        (deque_t *deque);

//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int      front        (deque_t *deque);
//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int      rear         (deque_t *deque);

//Cria um nó que guarda um valor e o adiciona ao fim do deque
void     enqueue_rear (deque_t *deque, int value);
//Cria um nó que guarda um valor e o adiciona ao inicio do deque
void     enqueue_front(deque_t *deque, int value);
//Retira o valor do final caso não esteja vazia
void     dequeue_rear (deque_t *deque);
//Retira o valor da frente caso não esteja vazia
void     dequeue_front(deque_t *deque);
//Limpa o conteudo do deque(deixa ele vazio)
void     erase        (deque_t *deque);

//Imprime o deque em uma unica linha, com os elementos separados por um espaço,
//terminando com um \n, lembrando de respeitar os conceitos de fila.
void     print        (deque_t *deque);

int main() {
 	int i, num;
  	scanf("%d", &num);
  
  	deque_t* deque = construct();
  
  	int vector[num];
  	for(i = 0; i < num; ++i)
      	scanf("%d", &vector[i]);
  
  	for(i = 0; i < num; ++i)
      	enqueue_rear(deque, vector[i]);
  
 	printf("%d\n", front(deque));
  	printf("%d\n", rear (deque));
  
  	if(!empty(deque))
  		printf("The size of the deque %d\n", size(deque));
  	else
       	printf("The deque is empty\n");
  	
    scanf("%d", &num);
    for(i = 0; i < num; ++i)
       enqueue_front(deque, i);
  	print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear (deque);
    print(deque);
    
  	erase(deque);
  	for(i = 0; i < 3; ++i)
  		enqueue_rear(deque, i);
  		
  	print(deque);
    destruct(deque);
       
	return 0;
}
//Cria um node que guarda os valores que são enfileirados no deque
node_t*  node_new     (int value){
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

//Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t* construct    (){
    deque_t *deque = (deque_t*)malloc(sizeof(deque_t));
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    return deque;
}
//Libera a memória do conteúdo e do próprio deque
void destruct (deque_t *deque){
    if (empty(deque)) {
        printf("Can't dequeue when there isn't a node!\n");
        return;
    } else {
        node_t* node;
        while(deque->front != NULL){
            node = deque->front;
            deque->front = deque->front->next;
            free(node);
        }
        free(deque);
    }
}

//Retorna o tamanho do deque
int      size         (deque_t *deque){
    return deque->size;
}
//Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool     empty        (deque_t *deque){
    return deque->size == 0;
}

//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int front (deque_t *deque){
    if(empty(deque)) return INT_MIN;
    return deque->front->value;
}
//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int      rear         (deque_t *deque){
    if(empty(deque)) return INT_MIN;
    else return deque->rear->value;
}

//Cria um nó que guarda um valor e o adiciona ao fim do deque
void     enqueue_rear (deque_t *deque, int value){
    (deque)->size++;
    node_t *aux = (deque)->rear;
    node_t *node = node_new(value);
    if(deque->rear == NULL) // fila vazia
        deque->front = node;
    else
        deque->rear->next = node;
    node->prev = aux;
    deque->rear = node;
    return;
}
//Cria um nó que guarda um valor e o adiciona ao inicio do deque
void enqueue_front(deque_t *deque, int value){
    (deque)->size++;
    node_t *aux = (deque)->front;
    node_t *node = node_new(value);
    if(deque->front == NULL) // fila vazia
        deque->rear = node;
    else
        deque->front->prev = node;
    deque->front = node;
    deque->front->next = aux;
    return;
}
//Retira o valor do final caso não esteja vazia
void     dequeue_rear (deque_t *deque){
    if (empty(deque)) {
        printf("Can't dequeue when there isn't a node!\n");
        return;
    } else {
        node_t *dequeued = (deque)->rear;
        (deque)->size--;

        while(dequeued->next != NULL)
            dequeued = dequeued->next;
        if(dequeued->prev == NULL) // remove o primeiro e unico
            deque->front = dequeued->next;
        else 
            dequeued->prev->next = NULL;
        free(dequeued);
    }
}
//Retira o valor da frente caso não esteja vazia
void     dequeue_front(deque_t *deque){
    if (empty(deque)) {
        printf("Can't dequeue when there isn't a node!\n");
        return;
    } else {
        node_t *dequeued = (deque)->front;
        (deque)->size--;
        (deque)->front = dequeued->next;
    }
}
//Limpa o conteudo do deque(deixa ele vazio)
void     erase        (deque_t *deque){
    if(deque != NULL){
        node_t* node;
        while(deque->front != NULL){
            node = deque->front;
            deque->front = deque->front->next;
            free(node);
            // print(deque);
        }
        deque->front = NULL;
        deque->rear = NULL;
        deque->size = 0;
    }
}

//Imprime o deque em uma unica linha, com os elementos separados por um espaço,
//terminando com um \n, lembrando de respeitar os conceitos de fila.
void print (deque_t *deque){
    if(empty(deque)){
        printf("Empty Stack!\n");
    }else{
        node_t *head = deque->front;
        while(head!=NULL){
            printf("%d",head->value);
            if(head->next != NULL) printf(" ");
            head = head->next;
        }
        printf("\n");
    }
}