// it find the target in array by adding three elements of array randomly
#include<stdio.h>
#include<stdlib.h>
#define SIZE 15
int** threeSum(int *a,int s,int*);
int main()
{
    int array[SIZE];
    printf("Enter %d Numbers: ",SIZE);
    for(int i=0;i<SIZE;i++)
    scanf("%d",&array[i]);
    int returnSize;
    int **result=threeSum(array,SIZE,&returnSize);
    for(int i=0;i<returnSize;i++)  
    printf("[%d, %d, %d] ",result[i][0],result[i][1],result[i][2]);
    for(int i=0;i<returnSize;i++)
    free(result[i]); 
    free(result);
    return 0;
}
int** threeSum(int *a,int s,int* re)
{
    int **result;
    result=(int**)calloc(s*s,sizeof(int*));
    if (s<3) return result;
    int m=0;
    for(int i=0;i<s-2;i++)
    {
        for(int j=i+1;j<s-1;j++)
        {
            for(int k=j+1;k<s;k++)
            {
                if(a[i]+a[j]+a[k]==0)
                {
                    result[m]=(int*)calloc(3,sizeof(int));
                    result[m][0]=i;
                    result[m][1]=j;
                    result[m++][2]=k;
                }
            }
        }
    }
    *re=m;
    return result;
}