#include<stdio.h>
#include<stdlib.h>
struct dnode
{
	int data;
	struct dnode *next;
	struct dnode *prev;
};
struct dnode *d_append( struct dnode **q,int num)
{ 
	struct dnode *new_node, *ptr;
  	printf("\n Enter the Data or Enter -1 for End : ");
  	scanf("%d", &num);
  	while(num!=-1)
	{
  		new_node=(struct dnode *)malloc(sizeof(struct dnode));
  		new_node->data=num;
  		if(*q==NULL)
  		{  
		  	*q=new_node;
     		new_node->prev=*q;
     		new_node->next=NULL;
  		}
  		else
  		{  ptr=*q;
     		while(ptr->next!=NULL)
      		{ 
			  	ptr=ptr->next;
	  		}
	 		ptr->next=new_node;                           
	 		new_node->prev=ptr;  
	 		new_node->next=NULL;                                                                                                                                  
  		}
  		printf("\n Enter the Data or Enter -1 for End : ");
  		scanf("%d", &num);
	}
	return *q;
}
struct dnode *d_display( struct dnode *q)
{   struct dnode *ptr;
	printf("\n The doubly Linked List is : ");
    ptr=q;
	while(ptr!=NULL)
    {  printf("\t%d", ptr->data);
       ptr=ptr->next;
	}
	printf("\n");
  return q;
}
struct dnode *d_addatbeg(struct dnode **q, int num)
{
	struct dnode *new_node;
	printf("\n Enter the Data : ");
  	scanf("%d", &num);
  	new_node=(struct dnode *)malloc(sizeof(struct dnode));
  	new_node->data=num;
  	(*q)->prev = new_node;
  	new_node->next = *q;
  	new_node->prev = NULL;
  	*q = new_node;	
  	printf("\n %d is inserted in the beginning of the doubly Linked List.\n ",num);
	return *q;
}
struct dnode *d_addafter(struct dnode *q, int loc, int num)
{
	int i;
	struct dnode *new_node, *ptr;
	printf("\n Enter the Data : ");
  	scanf("%d", &num);
  	printf("\n Enter the value after how many number of node the data has to be inserted : ");
  	scanf("%d",&loc);
  	printf("\n %d is inserted after %d node. \n",num,loc);
  	new_node=(struct dnode *)malloc(sizeof(struct dnode));
  	new_node->data = num;
  	ptr  = q;
  	for(i=1;i<loc;i++)
  		ptr = ptr->next;
  	if(ptr->next==NULL)
  	{
  		ptr->next = new_node;
  		new_node->prev = ptr;
  		new_node->next = NULL;
	}
	else
	{
		new_node->prev=ptr;
  		new_node->next = ptr->next;
  		ptr->next->prev=new_node;
  		ptr->next = new_node;
	}
  	return q;
}
int d_count(struct dnode *q)
{
    int count = 0; 
    struct dnode* current = q;  
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    printf("\n Number of Nodes in the doubly Linked List is : %d \n",count);
    return 0;
}
struct dnode *d_delete(struct dnode **q, int num)
{
	struct dnode *ptr;
	printf("\n Enter the Data which have to delete : ");
	scanf("%d",&num);
	ptr = *q;
	while(ptr->data!=num)
	{
		ptr = ptr->next;
	}
	if(ptr->next == NULL)
	{
		ptr->prev->next = NULL;
	}
	else if(ptr->prev == NULL)
	{
		ptr = *q;
		*q = (*q)->next;
		(*q)->prev = NULL;
	}
	else
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
	}
	printf("\n %d is Deleted from the Doubly Linked List.\n",ptr->data);
	free(ptr);
	return *q;
}
int main()
{
	int num,loc,option;
	struct dnode *a = NULL;
	do
	{
		printf("\n 1. Create a Doubly Linked List entering the Data at End.");
		printf("\n 2. Adds a new Node at the Beginning of the Doubly Linked List.");
		printf("\n 3. Adds a new Node after specified number of Nodes.");
		printf("\n 4. Display.");
		printf("\n 5. Counts the number of nodes present in the Doubly Linked List.");
		printf("\n 6. Deletes the specified node from the Doubly Linked List with the value num.");
		printf("\n 7. Exit.\n");
		printf("\n Enter the Option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				a=d_append(&a,num);
				break;
			case 2:
				a = d_addatbeg(&a,num);
				break;
			case 3:
				a= d_addafter(a, loc, num);
				break;
			case 4:
				d_display (a);
				break;
			case 5:
				d_count(a);
				break;
			case 6:
				a=d_delete(&a,num);
				break;
			case 7:
				exit(0);
			default:
				printf("\n Please enter the correct option.\n");
   				break;
		}
	}
	while(option!=7);
	printf("\n");
	return 0;
}