#include <stdio.h>
#include<string.h>
#include <stdlib.h>
struct node
{
    char info[20];
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
char filename[20];

void frontelement();
char e[20];
void enq(char* filename);
void deq();
void display();
void create();
void queuesize();
 
int count = 0;
 
void main()
{
    int n,ch = 0;
    printf("\n 1 - Enter  filename to print");//TODO: enter to print
    printf("\n 2 - Enter filename to cancel print");//to cancel
    printf("\n 3 - Display the current printing file");//to view current printing
    printf("\n 5 - Exit");
    printf("\n 4 - Display the queued print jobs");//check current jobs
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter filename: ");
            scanf("%s",filename);
            enq(filename);
            break;
        case 2:
            deq();
            break;
        case 3:
            frontelement();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        case 7:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
void queuesize()
{
    printf("\n Queue size : %d", count);
}
 
/* Enqueing the queue */
void enq(char *filename)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        strncpy(rear->info,filename,20);
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        strncpy(temp->info,filename,20);
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
    
    //system(strcat("lp  ",filename));
}
 
/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%s ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%s", front1->info);
}
 
/* Dequeing the queue */
void deq()
{
    front1 = front;
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            strncpy(filename,front->info,20);
            printf("\n Dequed filename : %s",filename );
            free(front);
            front = front1;
        }
        else
        {
            strncpy(filename,front->info,20);
            printf("\n Dequed filename : %s", filename);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 
/* Returns the front element of queue */
void frontelement()
{
    if ((front != NULL) && (rear != NULL))
        printf("%s",front->info);
    else
        printf("Empty\n");
        return;
}
