#include<stdio.h>
void TofH(int,char,char,char,int*);
int main()
{
        int n,m=0;
        printf("enter the number of discs\n");
        scanf("%d",&n);
        TofH(n,'s','t','d',&m);
        printf("number of moves=%d\n",m);
        return 0;
}
void TofH(int n,char s, char t,char d,int*m)
{
        if(n==1)
        {
                printf("move disc %d from peg %c to peg %c\n",n,s,d);
                (*m)++;
                return;
        }
        else
        {
                TofH(n-1,s,d,t,m);
                printf("move disc %d from peg %c to peg %c\n",n,s,d);
                (*m)++;
                TofH(n-1,t,s,d,m);
        }
}
