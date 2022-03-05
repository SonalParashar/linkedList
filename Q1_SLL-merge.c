#include <stdio.h>
#include <stdlib.h>

struct node
{  int data;
   struct node *next;
};

void addNode(struct node **q, int num)
{
	struct node *new_node,*ptr;
	printf("\n Enter the Data or Enter -1 for End : ");
   	scanf("%d", &num);
   	while(num!=-1)
   	{ 
   		new_node=(struct node *)malloc(sizeof(struct node));
     	new_node->data=num;
     	if(*q==NULL)
     	{  
			new_node->next=NULL;
        	*q=new_node;
	 	}
	 	else
	 	{ 
			ptr=*q;
  			while(ptr->next!=NULL)
	   		{  
			   ptr= ptr->next;
	   		}
	   		ptr->next=new_node;
	   		new_node->next=NULL;
	 	}
	 	printf("\n Enter the Data or Enter -1 for End : ");
	 	scanf("%d", &num);
   	}
}
void display(struct node *q)
{  
	while (q != NULL)
  	{
     	printf("\t%d", q->data);
     	q = q->next;
  	}
  	printf("\n");
}

int getCount(struct node *q)
{
    int count = 0; 
    struct node* current = q;  
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    printf("%d \n",count);
    return 0;
}

struct node* copy(struct node* head)
{
    if (head == NULL) 
	{
        return NULL;
    }
    else 
	{
        struct node* newNode= (struct node*)malloc(sizeof(struct node));
        newNode->data = head->data;
        newNode->next = copy(head->next);
        return newNode;
    }
}

void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

struct node* mergeNode(struct node* a, struct node* b, struct node **dummy)
{
    int swapped, i;
	*dummy = copy(a);
    struct node *ptr;
    struct node *lptr = NULL;
    if(*dummy==NULL)
    {
        *dummy=b;
        return *dummy;
    }
    if(b==NULL)
        return *dummy;
    ptr=*dummy;
	while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=b;
    do
    {
        swapped = 0;
        ptr = *dummy;
        while (ptr->next != lptr)
        {
            if (ptr->data > ptr->next->data)
            { 
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    }
    while (swapped);
    ptr = *dummy;
    struct node* next_next;
    while (ptr->next != NULL)
    {
       if (ptr->data == ptr->next->data)
       {            
           next_next = ptr->next->next;
           free(ptr->next);
           ptr->next = next_next; 
       }
       else 
       {
          ptr = ptr->next;
       }
    }
	return *dummy;
}

int main()
{
	struct node *res = NULL;
	struct node *a = NULL;
	struct node *b = NULL;
	int num;
	//char ch;
	int option;
	do
	{
		printf("\n 1. Enter the data of 1st Linked List : ");
		printf("\n 2. Enter the data of 2nd Linked List : ");
		printf("\n 3. Display the 1st Linked list");
		printf("\n 4. Display the 2nd Linked list");
		printf("\n 5. Merge, Sort and Delete the Duplicate Elemrnts : ");
		printf("\n 6. Exit\n");
		printf("\n Enter the Option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				addNode(&a,num);
				printf("\n Number of nodes in this Linked List : ");
				getCount(a);
				break;
			case 2:
				addNode(&b,num);
				printf("\n Number of nodes in this Linked List : ");
				getCount(b);
				break;
			case 3:
				printf("\n The 1st Linked List is : ");
				display(a);
				break;
			case 4:
				printf("\n The 2nd Linked List is : ");
				display(b);
				break;
			case 5:
				res = mergeNode(a,b,&res);
				printf("\n 5. After Merge, Sort and deleting the Duplicate Elemrnts The Linked List is : \n\n");
				display(res);
				printf("\n Number of nodes in the new Linked List : ");
				getCount(res);
				break;
			case 6:
				exit(0);
			default:
   				printf("\n Please enter the correct option.\n");
   				break;
		}
	}
	while(option!=6);
	return 0;	
}
