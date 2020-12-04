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
    float n;
    float m;
    ElementNode *table[SIZE];
};
ElementNode* createElementNode(int key){
    ElementNode *element = (ElementNode*) malloc(sizeof(ElementNode));
    element->key = key;
    element->next = NULL;
    return element;
}
LinkedHashTable* createLinkedHashTable(float size){
    LinkedHashTable *hash = (LinkedHashTable*) malloc(sizeof(LinkedHashTable));
    int i;
    for(i=0;i<size;i++){
        hash->table[i] = NULL;
    }
    return hash;
}
int hash (int k, int m){
    return k%m;
}
// void add(LinkedHashTable *ht, int key){
//     ElementNode *new_element = createElementNode(key);
//     int h = hash(key, 7);
//     new_element->next = ht->table[h];
//     ht->table[h] = new_element;
// }
void freeHash(LinkedHashTable* ha){
    if(ha != NULL){
        if(ha != NULL){
            int i;
            for(i=0; i < ha->m; i++){
                if(ha->table[i] != NULL)
                    free(ha->table[i]);
            }
            free(ha->table);
        }
    }
}
LinkedHashTable* add(LinkedHashTable* ht, int key){
    int i=0;
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
        }
        i++;
        if(aux->key == key){
            printf("0 %d\n", i);
            return;
        } else aux->next = new_element;
    }
    float n = ht->n;
    n++;
    ht->n = n;
    float a = ht->n/ht->m;
    printf("a: %f n: %f m: %f\n", a, ht->n, ht->m);
    if(a >= 0.75){
        int j;
        float n;
        n = ht->m;
        n = 2*n-1;
        ht->m = n;
        LinkedHashTable *new_hs = createLinkedHashTable(ht->m);
        for(j=0; j<ht->m; j++){
            printf("%d: ", i);
            ElementNode *current = ht->table[i];
            while(current!=NULL){
                printf("%d -> ", current->key);
                add(new_hs, current->key);
                current = current->next;
            }
            printf("\n");
        }
        printf("1 %d\n", i);
        return new_hs;
    }
    printf("1 %d\n", i);
    return ht;
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
    int h = hash(key, 7);
    int r = removeElement(&(ht->table[h]),key);
    if(r){
        float n = ht->n;
        n--;
        ht->n = n;
    }
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
    ElementNode *current = ht->table[h];
    while(current!=NULL){
        if(current->key == key){
            printf("1 %d\n", i);
            return;
        }
        current = current->next;
    }
    
    printf("0 %d\n", i);
}
void prt(LinkedHashTable *ht){
    int i, count2=0, max=0;
    printf("%0.0f ", ht->m);
    for(i=0; i<ht->m; i++){
        printf("%d -> ", i);
        ElementNode *current = ht->table[i];
        while(current!=NULL){
            printf("%d -> ", current->key);
            current = current->next;
            count2++;
        }
        if(count2 > max) max = count2;
        count2 = 0;
    }
    printf("%0.0f %d\n", ht->n, max);
}
int main(){
    int m = 7, key, i=0, a;
    char *line = (char*) malloc(sizeof(char));

    LinkedHashTable *ht = createLinkedHashTable(m);
    ht->m = 7;
    ht->n = 0;
    while(scanf("%s", line, &key) != EOF){   
        DBG printf("line: %s\n", line);
        DBG printf("key: %d\n", key);
        printf("%d ", i);
        if(strcmp(line, "PRT") == 0) prt(ht);
        else {
            scanf("%d", &key);
            if(strcmp(line, "ADD") == 0) ht = add(ht, key);
            if(strcmp(line, "DEL") == 0) del(ht, key);
            if(strcmp(line, "HAS") == 0) has(ht, key);
        }
        i++;
    }
    DBG print(ht, key, 7);
}