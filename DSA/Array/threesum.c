// it find the target in array by adding three elements of array in continous
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int* threeSum(int *a,int s,int);
int main()
{
    int array[SIZE];
    printf("Enter %d Numbers: ",SIZE);
    for(int i=0;i<SIZE;i++)
    scanf("%d",&array[i]);
    printf("Enter target:");
    int target;
    scanf("%d",&target);
    int *result=threeSum(array,SIZE,target);
    printf("[%d, %d, %d]",result[0],result[1],result[2]);
    free(result);
    return 0;
}
int* threeSum(int *a,int s,int target)
{
    int *temp=(int*)calloc(3,sizeof(int));
    if(s<3) return temp;
    for(int i=0;i<s-3;i++)
    {
        int sum=a[i]+a[i+1]+a[i+2];
        if(sum==target)
        {
            temp[0]=i;
            temp[1]=i+1;
            temp[2]=i+2;
            return temp;
        }
    }
    return temp;
}