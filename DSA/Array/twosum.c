#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int* twoSum(int *a,int s,int);
int main()
{
    int array[SIZE];
    printf("Enter %d Numbers: ",SIZE);
    for(int i=0;i<SIZE;i++)
    scanf("%d",&array[i]);
    printf("Enter target:");
    int target;
    scanf("%d",&target);
    int *result=twoSum(array,SIZE,target);
    printf("[%d, %d]",result[0],result[1]);
}
int* twoSum(int *a,int s,int target)
{
    int *temp=(int*)calloc(2,sizeof(int));
    if(s<2) return temp;
    for(int i=0;i<s-1;i++)
    {
        for(int j=i+1;j<s;j++)
        {
            if((a[i]+a[j])==target)
            {
                temp[0]=i;
                temp[1]=j;
                return temp;
            }
        }
    }
    return temp;
}