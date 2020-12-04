#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)
#define SIZE 200

typedef struct element_node ElementNode;
typedef struct linkedhashtable LinkedHashTable;
struct element_node{
    int key;
    int value;
    ElementNode *next;
};
struct linkedhashtable{
    ElementNode *table[SIZE];
};
ElementNode* createElementNode(int key,int value){
    ElementNode *element = (ElementNode*) malloc(sizeof(ElementNode));
    element->key = key;
    element->value = value;
    element->next = NULL;
    return element;
}
LinkedHashTable* createLinkedHashTable(int size){
    LinkedHashTable *hash = (LinkedHashTable*) malloc(sizeof(LinkedHashTable));
    int i;
    for(i=0;i<size;i++){
        hash->table[i] = NULL;
    }
    return hash;
}
void put(LinkedHashTable *ht, int key, int value, int h){
    ElementNode *new_element = createElementNode(key,value);
    if(ht->table[h] == NULL){ 
        ht->table[h] = new_element;
    } else {
        ElementNode* aux = ht->table[h];
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = new_element;
    }
}
void print(LinkedHashTable *ht,int key, int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d -> ", i);
        ElementNode *current = ht->table[i];
        while(current!=NULL){
            printf("%d -> ", current->value);
            current = current->next;
        }
        printf("\\\n");
    }
}
int main(){
    int n, i, m, c, j, x;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d", &m, &c);
        LinkedHashTable *hash = createLinkedHashTable(m);
        for(j=0; j<c; j++){
            scanf("%d", &x);
            // printf("%d\n", x);
            int h = x%m;
            put(hash, x, x, h);
        }
        print(hash, x, m);
        printf("\n");
        free(hash);
    }

}