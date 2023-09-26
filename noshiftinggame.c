#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
const int m=4;
const int n=4;
void display();
void randommtrx(int a[m][n]);
void displaymtx(int a[m][n]);
void uparrow(int a[m][n],int *mv);
void leftarrow(int a[m][n],int *mv);
void rightarrow(int a[m][n],int *mv);
void downarrow(int a[m][n],int *mv);
void findp(int a[m][n],int *i,int *j);
int check(int a[m][n]);
int main()
{
    int move,x,c,ar[m][n],d;
    char name[20],p='y';
    printf("Player name:");
    gets(name);
    display();
    while(p=='y')
    {
    d=0;
    move=10;
    printf("\n\nEnter any key to start.....");
    getch();
    while(move!=-1)
    {
        system("cls");
        printf("\n   Hello %s, Moves remaining : %d\n",name,move);
        if(d==0)
        {
        randommtrx(ar);
        d++;
        }
        displaymtx(ar);
        x=getch();
        switch(x)
        {
            case 72:
            uparrow(ar,&move);
            c=check(ar);
            break;
            case 75:
            leftarrow(ar,&move);
            c=check(ar);
            break;
            case 77:
            rightarrow(ar,&move);
            c=check(ar);
            break;
            case 80:
            downarrow(ar,&move);
            c=check(ar);
            break;
            case 'e':
            exit(0);
            case 'E':
            exit(0);
        }
        if(c==1)
        {
        system("cls");
        printf("\n   Hello %s, Moves remaining : %d\n",name,move);
        displaymtx(ar);
        printf("\n\tYOU WON...");
        break;
        }
    }
    if(move==-1)
    printf("\n\n\tYOU LOSE !");
    getch();
    printf("\n\nwant to play again?");
    printf("\nEnter 'y' to play again:");
    p=getch();
    }
    return 0;
}
void display()
{
    int i,j,k,l;
    printf("\t\t\t\tMATRIX PUZZLE\n\n");
    printf("\t\t\t\tRULE OF THIS GAME\n\n");
    printf("1.You can move only 1 step at a time by arrow key\n");
    printf("\t\tMove Up   : by Up arrow key\n");
    printf("\t\tMove Down : by Down arrow key\n");
    printf("\t\tMove Left : by Left arrow key\n");
    printf("\t\tMove Right: by Right arrow key\n");
    printf("2.You can move number at empty postion only\n");
    printf("3.For each valid move:Your total number of move will decreased by 1\n");
    printf("4.winning situation : Number in a 4*4 matrix should be in order from 1 to 15\n\n");
    printf("\t\t\tWinning Situation:\n");
    for(i=0;i<=20;i++)
    printf("-");
    printf("\n");
    for(i=0,k=1;i<4;i++)
    {
        printf("|");
        for(j=0;j<4;j++,k++)
        {
            if(k/10==0)
            printf(" %d  |",k);
            else if(k%10==6)
                printf("    |");
            else printf(" %d |",k);
        }
        printf("\n");
    }
    for(i=0;i<=20;i++)
    printf("-");
    printf("\n");
    printf("5.You can exit the game at any time by pressing 'E' or 'e'\nso try to win in minimum no of move\n");
    printf("\n\t\t  Happy gaming , Good Luck");
}
void randommtrx(int ar[m][n])
{
    time_t t1;
    int i,j,k,t,a[16];
    srand(time(&t1));
    for(i=0;i<15;i++)
    {
        t=rand()%15+1;
        for(j=0;j<i;j++)
        {
            if(t==a[j])
            break;
        }
        if(i==j)
        a[i]=t;
        else i--;
    }
    a[15]=32;
    for(i=0,k=0;i<4;i++)
    {
        for(j=0;j<4;j++,k++)
        ar[i][j]=a[k];
    }
}
void displaymtx(int a[m][n])
{
    int i,j;
for(i=0;i<=20;i++)
    printf("-");
    printf("\n");
    for(i=0;i<4;i++)
    {
        printf("|");
        for(j=0;j<4;j++)
        {
            if(a[i][j]/10==0)
            printf(" %d  |",a[i][j]);
            else if(a[i][j]/10==3)
                printf("%c   |",a[i][j]);
            else printf(" %d |",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<=20;i++)
    printf("-");
    printf("\n");
}
void findp(int a[m][n],int *i,int *j)
{
    int b,c;
    for(b=0;b<4;b++)
    {
        for(c=0;c<4;c++)
        {
            if(a[b][c]==32)
            {
                *i=b;
                *j=c;
                return;
            }
        }
    }
}
void uparrow(int a[m][n],int *mv)
{
    int i,j;
    findp(a,&i,&j);
    if(i!=0)
    {
        a[i][j]=a[i-1][j]+a[i][j]-(a[i-1][j]=a[i][j]);
        *mv-=1;
    }
}
void leftarrow(int a[m][n],int *mv)
{
    int i,j;
    findp(a,&i,&j);
    if(j!=0)
    {
        a[i][j]=a[i][j-1]+a[i][j]-(a[i][j-1]=a[i][j]);
        *mv-=1;
    }
}
void rightarrow(int a[m][n],int *mv)
{
    int i,j;
    findp(a,&i,&j);
    if(j!=3)
    {
        a[i][j]=a[i][j+1]+a[i][j]-(a[i][j+1]=a[i][j]);
        *mv-=1;
    }
}
void downarrow(int a[m][n],int *mv)
{
    int i,j;
    findp(a,&i,&j);
    if(i!=3)
    {
        a[i][j]=a[i+1][j]+a[i][j]-(a[i+1][j]=a[i][j]);
        *mv-=1;
    }
}
int check(int a[m][n])
{
    int i,j,k;
    for(i=0,k=1;i<m;i++)
    {
        for(j=0;j<n&&k<16;j++,k++)
        {
            if(a[i][j]!=k)
            return 0;
        }
    }
    return 1;
}
