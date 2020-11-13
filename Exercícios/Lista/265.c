#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int freq;
    char ch;
    struct elemento *next;
};
typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* createList(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

int insertList(Lista* li, int x, char ch){
    if(li==NULL)
        return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL)
        return 0;
    node->freq = x; 
    node->ch = ch; 
    node->next = NULL;
    if(*li == NULL){ 
        *li = node; 
    } else {
        Elem* aux = *li;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = node; 
    }
    return 1;
}
void printar(Lista* head){
	Lista aux = *head;
	if(head == NULL) return;
    while(aux != NULL){
        printf("%c %d\n", aux->ch, aux->freq);
        aux = aux->next;
    }
    printf("\n");
}
int main() {
    int i;
    char c;
    int array[256] = {0};
    while (scanf("%c", &c) != EOF) {
        array[c]++;
    }
    Lista* li;
    li = createList();
    for (i = 255; i > 0; --i) {
        if(array[i] != 0) insertList(li, array[i], i);
    }
    printar(li);
    return 0;
}