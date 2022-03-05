#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* removeLastNodeAndAddAtTheBegining(struct Node* head)
{
	if (head == NULL)
		return NULL;

	if (head->next == NULL) {
		return head;
	}

	struct Node* second_last = head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;

	push(&head, second_last->next->data);
	
	second_last->next = NULL;

	return head;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main()
{
	struct Node* head = NULL;

	push(&head, 102);
	push(&head, 292);
	push(&head, 1301);
	push(&head, 3);
	push(&head, 88);

	printf("Print before any operation\n");
	for (struct Node* temp = head; temp != NULL; temp = temp->next)
		printf("%d ", temp->data);
		
	printf("\n");

	head = removeLastNodeAndAddAtTheBegining(head);
	
	printf("Print after operation\n");

	for (struct Node* temp = head; temp != NULL; temp = temp->next)
		printf("%d ", temp->data);
		
	printf("\n");

	return 0;
}