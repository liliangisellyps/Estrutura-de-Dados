
void imprime_lista(Lista* li) {
    Elem* node = (Elem*) malloc(sizeof(Elem));
    node->value = li;
    node->next = NULL;
    while (node->next != NULL) {
        printf("%d\n", node->value);
        node = node-­>next;
    }
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-----------------------------\n");

        no = no->prox;
    }
}