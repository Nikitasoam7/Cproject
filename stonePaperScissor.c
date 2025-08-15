// Stone, Paper, Sccissor
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main() 
{
    // Write C code here
    time_t t;
    printf("....Welcome to the game....\n");
    printf("   Stone, Paper, Scissor\n");
    srand(time(&t));
    int random=rand();
    printf("\npress any key to start \nPress e or E to exit game\n");
    char ch=getchar();
    while(ch!='E'&& ch!='e')
    {
        random=rand();
        random=(random%3)+1;
        printf("\nSelect any one option");
        printf("\n1.Stone\n2.Paper\n3.Scissor\n");
        int n;
        scanf("%d",&n);
        if(!(n>0&&n<4))
        {
           printf("\nwrong choice select again\n");
           continue;
        }
        switch(random)
        {
            case 1:
            printf("Stone");
            break;
            case 2:
            printf("Paper");
            break;
            case 3:
            printf("Scissor");
            break;
        }
        int result;
        if(random==n)
        result=1;
        else if(random==n-1||random==3&&n==1)
        result=2;
        else
        result=3;
        switch (result)
        {
            case 1:
            printf("\n\ttie!");
            break;
            case 2:
            printf("\n\tcongratulations you won!");
            break;
            case 3:
            printf("\n\tyou loss!");
        }
        printf("\nPress e or E to exit game");
    }

    return 0;
}