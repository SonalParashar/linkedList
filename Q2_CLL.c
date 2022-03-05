#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
typedef struct node CLL; //alias name for struct node

CLL *create(CLL *);
void appendNode(CLL **, int );
void display(CLL *);
int deleteNode(CLL **);
void reverseCLL(CLL **);


CLL *create (CLL *beg)
{
    CLL *temp, *point;
    char yn;
    int n;
    do 
    {
        printf("\n\tEnter any number: ");
        scanf("%d", &n);
        temp = (CLL*)malloc(sizeof(CLL));
        temp->data = n;
        if(beg==NULL)
        {
            beg = temp;
            point = beg;
        }
        else
        {
            point->link =temp;
            point = point->link;
        }
        temp->link = beg;
        printf("\n\tWant to add more nodes (y/n): ");
        fflush(stdin);
        scanf("%c", &yn);
    }
    while(yn== 'y' || yn== 'Y');
    return(beg);
}
void appendNode(CLL **q, int num)
{
    CLL *temp, *point;
    printf("\n\tEnter number to insert at rear: ");
    scanf("%d", &num);
    temp = (CLL*)malloc(sizeof(CLL));
    temp->data= num;
    if(*q==NULL)
    {
        temp->link= temp;
        *q= temp;
    }
    else
    {
        point= *q;
        while(point->link!= *q)
            point= point->link;
            point->link = temp;
            temp->link = *q;
    }
    //q->link=temp;
    //q=temp;
    printf("\n\t%d is inserted at rear\n\n", num);
}

void display(CLL *q)
{
    CLL *temp;
    printf("\n\tDATA of CLL");

    printf("\n\t%10u",q->data);
    for(temp=q->link; temp!= q; temp=temp->link)
    {
        printf("\n\t%10u", temp->data);
    }
   // getch();
    //return 0;
}

int deleteNode(CLL **q)
{
    CLL *temp;
    temp = *q;
    while(temp->link!= *q)
    temp = temp->link;
    temp->link = (*q)->link;
    printf("\t%d is deleted", (*q)->data);
    free(*q);
    *q = temp->link;
    
    if(*q == NULL)
    {
        printf("Empty List");
        return(-1234);
    }
   

}

void reverseCLL(CLL **q)
{
    
    if(*q == NULL)
    {
        printf("Empty List");
        //return(-1234);
    }
    CLL *now = *q, *link, *prev = NULL;

    do
    {
        link = now->link;
        now->link = prev;
        prev = now;
        now = link;
    }

    while(now!=(*q));
       
        (*q)->link=prev;
        *q=prev;
     
}

int main()
{
    int i, op;
    CLL *start;
    start =NULL;
    //struct node *last=NULL;
    while(1)
    {
        printf("\n\n\tMENU\n");
        printf("\n\t1.Create");
        printf("\n\t2.Display");
        printf("\n\t3.Append node in REAR");
        printf("\n\t4.Delete node from FRONT");
        printf("\n\t5.Reverse CLL");
        printf("\n\t6.EXIT");

        printf("\n\tENTER CHOICE: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            start= create(start);
            
            break;

            case 2:
            display(start);
            break;

            case 3:
            appendNode(&start, i);
            break;

            case 4:
            deleteNode(&start);
            break;

            case 5:
            reverseCLL(&start);
            break;

            case 6:
            exit(0);
            break;

            default:
            printf("\n\tINVALID INPUT. Try Again\t\n");
        }
    } 
    
    return 0;
}
