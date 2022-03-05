#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start=NULL;
struct node* creatNode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return(n);
}
void insertFirst()
{
    struct node *temp;
    temp=creatNode();
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    temp->link=start;
    start=temp;
}
void insertLast()
{
    struct node *temp,*t;
    temp=creatNode();
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        t=start;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }
}
void insertAfter()
{
    struct node *temp,*ptr,*post;
    int num;
    temp=creatNode();
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    printf("Enter the number after which insert a new node\n");
    scanf("%d",&num);
    ptr=start;
    while(ptr->data!=num)
    {
        ptr=ptr->link;
    }
    if(ptr==NULL) {
       printf("number not found \n");
    } else {
       post=ptr->link;
       ptr->link=temp;
       temp->link=post;
    }
}
void insertBefore()
{
    struct node *temp,*ptr,*pre;
    int num;
    temp=creatNode();
    printf("Enter a number\n");
    scanf("%d",&temp->data);
    printf("Enter the number before which insert a new node\n");
    scanf("%d",&num);
    ptr=start;
    while(ptr->data!=num)
    {
        pre=ptr;
        ptr=ptr->link;
    }
    if(ptr==NULL)
        printf("number not found \n");
    else
    {
        pre->link=temp;
        temp->link=ptr;
    }

}
void deletFirst()
{
    struct node *ptr;
    if(start==NULL)
        printf("List is empty\n");
    else
    {
        ptr=start;
        start=ptr->link;
        printf("Deleted data is %d\n",ptr->data);
        free(ptr);
    }
}
void deletLast()
{
    struct node *ptr,*pre;
    ptr=start;
    if(start==NULL)
        printf("List is empty\n");
    else if(ptr->link==NULL)
    {
        start=NULL;
        printf("Deleted data is %d\nList is Empty now\n",ptr->data);
        free(ptr);
    }
    else
    {
        while(ptr->link!=NULL)
        {
            pre=ptr;
            ptr=ptr->link;
        }
        printf("Deleted element is %d\n",ptr->data);
        pre->link=NULL;
        free(ptr);
    }

}
void deletAfter()
{
    struct node *ptr,*post;
    int val;
    printf("Enter the number after which node will be deleted\n");
    scanf("%d",&val);
    ptr=start;
    if(start==NULL)
        printf("List is empty\n");
    else
    {
        while(ptr->data!=val)
        {
            ptr=ptr->link;
        }
        post=ptr->link;
        ptr->link=post->link;
        printf("Deleted element is %d\n",post->data);
        free(post);
    }
}
void deletNode()
{
    struct node *pre,*ptr;
    int val;
    printf("Enter the data of the node\n");
    scanf("%d",&val);
    ptr=start;
    if(start==NULL)
        printf("List is Empty\n");
    else
    {
        while(ptr->data!=val)
        {
            pre=ptr;
            ptr=ptr->link;
        }
        pre->link=ptr->link;
        printf("Deleted element is %d\n",ptr->data);
        free(ptr);
    }
}
void deletList()
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
        printf("List is Empty\n");
    else
    {
        while(start!=NULL)
        {
            deletFirst();
        }

    }
}
static void reverse()
{
	struct node* prev = NULL;
	struct node* current = start;
	struct node* link = NULL;
	while (current != NULL)
    {
		// Store next
		link = current->link;

		// Reverse current node's pointer
		current->link = prev;

		// Move pointers one position ahead.
		prev = current;
		current = link;
	}
	start = prev;
}
void viewList()
{
    struct node *t;
    if(start==NULL)
        printf("List is empty\n");
    else
    {
        t=start;
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=t->link;
        }
        printf("\n");
    }
}
int menu()
{
    int ch;
    printf("1. insertFirst\n");
    printf("2. insertLast\n");
    printf("3. insertAfter\n");
    printf("4. insertBefore\n");
    printf("5. deleteFirst\n");
    printf("6. deleteLast\n");
    printf("7. deleteAfter\n");
    printf("8. deleteNode\n");
    printf("9. deleteNode\n");
    printf("10. reverseNode\n");
    printf("11. view\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    return (ch);
}
int main()
{
    int val;
    while(1)
    {
        switch(menu())
    {
    case 1:
        {
            insertFirst();
            break;
        }
    case 2:
        {
            insertLast();
            break;
        }
    case 3:
        {
            insertAfter();
            break;
        }
    case 4:
        {
            insertBefore();
            break;
        }
    case 5:
        {
            deletFirst();
            break;
        }
    case 6:
        {
            deletLast();
            break;
        }
    case 7:
        {
            deletAfter();
            break;
        }
    case 8:
        {
            deletNode();
            break;
        }
    case 9:
        {
            deletList();
            break;
        }
    case 10:
        {
            reverse();
            break;
        }
    case 11:
        {
            viewList();
            break;
        }
    }

    }
    return 0;

}