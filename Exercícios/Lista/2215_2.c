#include <stdio.h> 
#include <stdlib.h> 
#define DBG if(0)
typedef struct node Node; 

struct node { 
	int value; 
	Node* next; 
}; 

void addBegOfList(Node** head, int num) {
	Node* newNode = (Node*) malloc(sizeof(Node)); 

	newNode->value = num; 

	newNode->next = (*head); 

	(*head) = newNode; 
} 
int addEndOfList(Node** li, int num){
    if(li==NULL)
        return 0;
    Node* node = (Node*) malloc(sizeof(Node));
    if(node == NULL)
        return 0;
    node->value = num;
    node->next = NULL;
    if(*li == NULL){ 
        *li = node;
    } else {
        Node* aux = *li;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = node;
    }
    return 1;
}
void printList(Node *node) { 
    Node* aux = node;
    while(aux->value == 0)
		aux = aux->next; 
	while (aux != NULL) 
	{ 
		printf("%d ", aux->value); 
		aux = aux->next; 
	} 
	printf("\n"); 
    return;
} 
int getSize(Node *node) { 
	int size = 0; 
	while (node != NULL) { 
		node = node->next; 
		size++; 
	} 
	return size; 
} 
Node* sumSameSize(Node* n1, Node* n2, int* vaium) { 
	if (n1 == NULL) 
		return NULL; 

	int sum=0; 

	Node* result = (Node*)malloc(sizeof(Node)); 

	result->next = sumSameSize(n1->next, n2->next, vaium); 

    DBG printf("sumsamesize1 1: %d 2: %d soma: %d vaium: %d\n", n1->value, n2->value, sum, *vaium);
	sum = n1->value + n2->value + *vaium; 
    DBG printf("sumsamesize2 1: %d 2: %d soma: %d vaium: %d\n", n1->value, n2->value, sum, *vaium);
	*vaium = sum / 10; 
	sum = sum % 10; 

	result->value = sum; 
    DBG printf("sumsamesize3 1: %d 2: %d soma: %d vaium: %d\n", n1->value, n2->value, sum, *vaium);

	return result; 
} 

void addRest(Node* list, Node* current, int* vaium, Node** result) { 
	int sum; 
    DBG printf("addrest 1: %d soma: %d vaium: %d\n", list->value, sum, vaium);

	if (list != current) { 
		addRest(list->next, current, vaium, result); 

		sum = list->value + *vaium; 
		*vaium = sum/10; 
		sum %= 10; 

		addBegOfList(result, sum); 
	} 
} 

void sumTwoLists(Node* n1, Node* n2, Node** result) 
{ 
	if (n1 == NULL) { 
		*result = n2; 
		return; 
	} else if (n2 == NULL) { 
		*result = n1; 
		return; 
	} 

	int size1 = getSize(n1); 
	int size2 = getSize(n2); 
	int vaium=0; 
	Node *current; 

	if (size1 == size2) 
		*result = sumSameSize(n1, n2, &vaium); 
	else { 
		if (size2 > size1){
            Node* aux = n1; 
            n1 = n2; 
            n2 = aux;
        }
		int d = abs(size1 - size2); 
        for (current = n1; d--; current = current->next); 
        printf("%d", d);

		*result = sumSameSize(current, n2, &vaium); 

        addRest(n1, current, &vaium, result); 
	} 
	if(vaium) addBegOfList(result, vaium); 
    DBG printf("1: %d 2: %d vaium: %d\n", n1->value, n2->value, &vaium);
} 

int main() 
{ 
	Node *number1 = NULL, *number2 = NULL, *result = NULL; 
    char num;
    while(1){
        scanf("%c ", &num);
        // printf("%d\n", num-48);
        if(num == 43) break;
        addEndOfList(&number1, num-48);
    }
    DBG printList(number1);
    while(1){
        scanf("%c ", &num);
        // printf("%d\n", num-48);
        if(num == 61) break;
        addEndOfList(&number2, num-48);
    }
    DBG printList(number2);
    if(number1 == NULL && number2 == NULL)
        printf("Lista vazia!");
	else {
        sumTwoLists(number1, number2, &result); 
	    printList(result);
    }
	return 0; 
} 
