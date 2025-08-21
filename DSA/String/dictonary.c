//dictionary ordered string
#include<stdio.h>
#include<string.h>
#include<conio.h>
int strgcmp(char [],char[]);
void strgcpy(char [],char[]);
int main()
{
char a[5][20],c[20];
int i,j;
printf("enter five words or names:");
for(i=0;i<5;i++)
{
    fgets(a[i],20,stdin);
    size_t len=strlen(a[i]);
    if(len>0&& a[i][len-1]=='\n')
    a[i][len-1]='\0';
}
for(i=0;i<4;i++)
{
    for (j=i+1;j<5;j++)
    {
        if(strgcmp(a[i],a[j])>0)
        {
            strgcpy(c,a[i]);
            strgcpy(a[i],a[j]);
            strgcpy(a[j],c);
        }
    }
}
for(i=0;i<5;i++)
printf(" \n%s",a[i]);
getch();
return 0;
}
int strgcmp(char a[],char b[])
{
    int i, j;
    for(i=0;a[i]!='\0'&&b[i]!='\0';i++)
    {
        if(a[i]>='A'&&a[i]<='Z'&&b[i]>='A'&&b[i]<='Z')
        {
            if(a[i]<b[i])
            return -1;
            else if(a[i]>b[i])
            return 1;
        }
        else if(a[i]>=97&&a[i]<=122&&b[i]>=97&&b[i]<=122)
        {
            if(a[i]<b[i])
            return -1;
            else if(a[i]>b[i])
            return 1;
        }
        else if(a[i]>=65&&a[i]<=90&&b[i]>=97&&b[i]<=122)
        {
            if(a[i]<(b[i]-32))
            return -1;
            else if(a[i]>(b[i]-32))
            return 1;
        }
        else if(a[i]>=97&&a[i]<=122&&b[i]>=65&&b[i]<=90)
        {
            if(a[i]<(b[i]+32))
            return -1;
            else if(a[i]>(b[i]+32))
            return 1;
        }
        else if(a[i]<b[i])
        return -1;
        else if(a[i]>b[i])
        return 1;
    }
    for(i=0;a[i]!='\0';i++);
    for(j=0;b[j]!='\0';j++);
    if(i>j)
    return 1;
    else if(i<j)
    return -1;
    else return 0;
}
void strgcpy(char dist[],char sour[])
{
    int i;
    for(i=0;sour[i]!='\0';i++)
    dist[i]=sour[i];
    dist[i]='\0';
}