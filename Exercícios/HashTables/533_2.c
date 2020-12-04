#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)
#define SIZE 100000
typedef struct element_node ElementNode;
typedef struct linkedhashtable LinkedHashTable;
struct element_node{
    int key;
    ElementNode *next;
};
struct linkedhashtable{
    int n;
    int m;
    ElementNode *table[SIZE];
};
ElementNode* createElementNode(int key){
    ElementNode *element = (ElementNode*) malloc(sizeof(ElementNode));
    element->key = key;
    element->next = NULL;
    return element;
}
LinkedHashTable* createLinkedHashTable(){
    LinkedHashTable *hash = (LinkedHashTable*) malloc(sizeof(LinkedHashTable));
    int i;
    for(i=0;i<SIZE;i++){
        hash->table[i] = NULL;
    }
    return hash;
}
int hash (int k, int m){
    return k%m;
}
void add(LinkedHashTable* ht, int key){
    int i=0;
    float a=0;
    if(ht == NULL){
        printf("0 0\n");
        return;
    }
    int h = hash(key, ht->m);
    ElementNode *new_element = createElementNode(key);
    if(new_element == NULL){
        printf("0 0\n");
        return;
    }
    if(ht->table[h] == NULL){ 
        ht->table[h] = new_element;
    } else {
        ElementNode* aux = ht->table[h];
        while(aux->next != NULL && aux->key != key){
            aux = aux->next;
            i++;
        }
        if(aux->key == key){
            printf("0 0\n");
            return;
        } else aux->next = new_element;
    }
    int n = ht->n;
    n++;
    ht->n = n;
    a = ht->n/ht->m;
    printf("a: %f n: %d m: %d\n", a, ht->n, ht->m);
    if(a >= 0.75) ht->m = 2*ht->m-1;
    printf("1 %d\n", i);
    return;
}
void print(LinkedHashTable *ht,int key, int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d -> ", i);
        ElementNode *current = ht->table[i];
        while(current!=NULL){
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("\\\n");
    }
}
int removeElement(ElementNode **head,int key){
    int i = 0;
    if((*head) ==NULL){
        printf("0 %d\n", i);
        return 0;
    }else{
        ElementNode *aux = *head, *prev = NULL,*nodeToRemove = NULL;
        while(aux!=NULL){
            if(aux->key == key){
                nodeToRemove = aux;
            }
            prev = aux;
            aux = aux->next;
            i++;
        }
        if(nodeToRemove==NULL){
            printf("0 %d\n", i);
            return 0;
        }else{
            if(prev==NULL){
                if((*head)->next==NULL){
                    *head = NULL;
                    printf("0 %d\n", i);
                    return 0;
                }
                if(nodeToRemove->next!=NULL){
                    *head = nodeToRemove->next;
                }
            }else {
                prev->next = nodeToRemove->next;
            }
            free(nodeToRemove);
            printf("1 %d\n", i);
            return 1;
        }
    }
}
void del(LinkedHashTable *ht,int key){
    int h = hash(key, ht->m);
    int r = removeElement(&(ht->table[h]),key);
    if(r) ht->n = ht->n--;
}
int has(LinkedHashTable *ht, int key){
    int i=0;
    if(ht == NULL){
        printf("0 0\n");
        return;
    }
    int h = hash(key, 7);
    if(ht->table[h] == NULL){
        printf("0 %d\n", i);
        return;
    }
    i++;
    if(ht->table[h]->key == key){
        printf("1 %d\n", i);
        return;
    }
    
    printf("0 %d\n", i);
}
void prt(LinkedHashTable *ht){
    int i, count=0, count2=0, max=0;
    printf("%d ", ht->m);
    for(i=0; i<ht->m; i++){
        printf("%d -> ", i);
        ElementNode *current = ht->table[i];
        while(current!=NULL){
            DBG printf("%d -> ", current->key);
            current = current->next;
            count++;
            count2++;
            if(count2 > max) max = count2;
        }
        count2 = 0;
        printf("\\\n");
    }
    printf("%d %d\n", count, max);
}
int main(){
    int key, i=0, a;
    char *line = (char*) malloc(sizeof(char));

    LinkedHashTable *ht = createLinkedHashTable();
    ht->n = 0;
    ht->m = 7;
    while(scanf("%s %d", line, &key) != EOF){   
        DBG printf("line: %s\n", line);
        DBG printf("key: %d\n", key);
        printf("%d ", i);
        if(strcmp(line, "ADD") == 0) add(ht, key);
        if(strcmp(line, "DEL") == 0) del(ht, key);
        if(strcmp(line, "HAS") == 0) has(ht, key);
        if(strcmp(line, "PRT") == 0) prt(ht);
        i++;
        prt(ht);
        // print(ht, key, ht->m);
    }
}