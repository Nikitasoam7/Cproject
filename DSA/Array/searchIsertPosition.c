#include<stdio.h>
#define MAX 10
int seachInsertPosition(int *,int, int);
int main()
{
    int nums[MAX];
    printf("Enter %d elements:",MAX);
    for(int i=0;i<10;i++)
    scanf("%d",&nums[i]);
    int target;
    printf("Enter the target to seacrh:");
    scanf("%d",&target);
    int s=seachInsertPosition(nums,MAX,target);
    printf("position %d",s);
    return 0;
}
int seachInsertPosition(int *nums,int numsSize, int target)
{
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>target||nums[i]==target)
            return i;
    }
    return -1;
}
