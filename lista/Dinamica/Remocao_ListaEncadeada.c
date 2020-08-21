// no prog
// int x = remove_lista_ESPECIFICO(li);

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL) // lista vazia, n tem oq remover
        return 0;

    Elem *node = *li;
    *li = node->next;
    free(node);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li==NULL)
        return 0;
    if(*li == NULL)
        return 0;
    Elemen *ant, *node = *li;
    while(node->next != NULL){
        ant = node;
        node = node->next;
    }
    if(no == *li)
        *li = node->next;
    else 
        ant->next = node->next;
    free(node);
    return 1;
}

int remove_lista(Lista* li, int valor){
    // remover um valor especifico da lista
    if(li == NULL) 
        return 0;
        Elem *ant, *node = *li;
        while(node != NULL && node->dados.matricula != valor){
            ant = node;
            node = node->next;
        }
        if(node == NULL) 
            return 0; // nao encontrado
        if(node == *li) // igual ao primeiro elemento da lista
            *li = node->next;
        else 
            nt->next = node->next;
        free(node);
        return 1;
}