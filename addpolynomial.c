#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int cf;
	int pw;
	struct Node* next;
};

void input(struct Node** pol)
{
	int cf, exp, cont;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	*pol = temp;
	do{
		printf("\n Coeffecient: ");
		scanf("%d", &cf);
		printf("\n Exponent: ");
		scanf("%d", &exp);
		temp->cf = cf;
		temp->pw = exp;
		temp-> next = NULL;
		printf("\nPress 1 to enter more terms else enter 0: ");
		scanf("%d", &cont);
		if(cont)
		{
			temp->next = (struct Node*)malloc(sizeof(struct Node));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont);	
}

void display(struct Node* pol)
{
	printf("\nThe polynomial expression is: ");
	while(pol != NULL)
	{
		printf("%dX^%d", pol->cf, pol->pw);
		pol = pol->next;
		if(pol != NULL)
			printf("+");
	}
}

void add(struct Node** result, struct Node* first, struct Node* second)
{
 	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->pw > second->pw)
 		{
 			temp->cf = first->cf;
 			temp->pw = first->pw;
 			first = first->next;
 		}
 		else if(first->pw < second->pw)
 		{
 			temp->cf = second->cf;
 			temp->pw = second->pw;
 			second = second->next;
 		}
 		else
 		{
 			temp->cf = first->cf + second->cf;
 			temp->pw = first->pw;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->next;
 		temp->next = NULL;
 			
 		if(first)
 		{
 			temp->cf = first->cf;
 			temp->pw = first->pw;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->cf = second->cf;
 			temp->pw = second->pw;
 			second = second->next;
 		}
 	}
}

int main()
{

	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* result = NULL;

	printf("\nEnter the data:\n");
	printf("\nFor the first polynomial:\n");
	input(&first);
	display(first);
	printf("\nFor the second polynomial:\n");
	input(&second);
	display(second);
	add(&result, first, second);
	display(result);
	return 0;
}
