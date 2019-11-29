#include<stdio.h>
#define MAX 30
void create (int[],int);

void insert (int[],int*,int, int);

void delete (int[],int*,int);

void display (int[],int);

void main()
{
        int n=0,pos,e,choice,done=0;
        int a[MAX];
        while(!done)
        {       printf("1)create 2)insert 3)delete 4)display 5)exit\n");
                printf("Enter the choice\n");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:printf("Enter the number of elements\n");
                           scanf("%d",&n);
                           create(a,n);
                           break;
                case 2:printf("Enter the position\n");
                           scanf("%d",&pos);
                           printf("Enter the new element to be inserted\n");
                           scanf("%d",&e);
                           insert(a,&n,pos,e);
                           break;
                case 3:printf("Enter the position for deletion\n");
                           scanf("%d",&pos);
                           delete(a,&n,pos);
                           break;
                case 4:display(a,n);
                           break;
                case 5:done =1;
                       break;
            default:printf("Invalid choice\n");
            break;
                }
        }
}
void create (int a[],int n)
{
        int i;
        if(n!=0)
        printf("Enter the filename elements\n");
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void insert(int a[],int *n ,int pos, int elem)
{
        int i;
        if(*n==0)
        {printf("Array is empty\n");
        return;
        }
        if(pos<0||pos>*n-1)
        {
                printf("Invalid position");
                return ;
        }
        for(i=*n-1;i>=pos;i--)
                a[i+1]=a[i];
                a[pos]=elem;
                (*n)++;
}

void delete(int a[],int *n,int pos)
{
        int i;
        if(*n==0)
                {printf("Array is empty\n");
                return;
                }
        if(pos<0||pos>*n-1)
                {
                printf("Invalid position\n");
                return;
                }
        for(i=pos;i<*n;i++)
                {
                a[i]=a[i+1];
                }
        (*n)--;
}
void display (int a[],int n)
{
        int i;
        if(n==0)
        {
                printf("Array is empty\n");
                return;
        }
        printf("Array elements\n");
        for (i=0;i<n;i++)
                printf("%d\t",a[i]);
                printf("\n");
}