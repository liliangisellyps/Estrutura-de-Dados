#include <stdio.h>
#include <stdlib.h>
struct node
{
	int value;
	struct node * next;
};
struct node *create_node(int x)
{
	struct node *new_node;
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->value = x;
	new_node->next = NULL;
	return new_node;
}
struct node * add(int x, struct node *head)
{
	if(head == NULL)
	{
		return create_node(x);
	}
	else 
	{
		struct node *aux = head;
		while(aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = create_node(x);
	}
	return head;
}
void printar(struct node *head)
{
	struct node *aux = head;
	if(head == NULL)
	{
		return;
	}
	else
	{
		while(aux != NULL)
		{
			printf("%d ", aux->value);
			aux = aux->next;
		}
		printf("\n");
	}
}
struct node* inverter(struct node * prev, struct node * current, struct node *head)
{
	if(current->next == NULL) head = current;
	else head = inverter(current, current->next, head);
	current->next = prev;
	return head;
}

int main()
{
	int i=0, x;
	struct node *list1 = NULL;
	while(scanf("%d", &x) != EOF)
	{
		list1 = add(x, list1);
	}
	list1 = inverter(NULL, list1, list1);
	printar(list1);
	return 0;
}