#include<stdio.h>
#define MAX 10
void mergeSort(int*,int ,int);
void merge(int*,int ,int ,int);
int main()
{
    int arr[MAX];
    printf("Enter %d nos:",MAX);
    for(int i=0;i<MAX;i++)
    scanf("%d",&arr[i]);
    mergeSort(arr,0,MAX-1);
    for(int i=0;i<MAX;i++)
    printf("%d, ",arr[i]);
    return 0;
}
void mergeSort(int* arr,int start,int end)
{
    if(start<end)
    {
        int mid=start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
void merge(int* arr,int start,int mid,int end)
{
    int temp[(end-start)+1];
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=end)
    {
        if(arr[j]<arr[i])
        temp[k]=arr[j++];
        else
        temp[k]=arr[i++];
        k++;
    }
    while(j<=end)
    temp[k++]=arr[j++];
    while(i<=mid)
    temp[k++]=arr[i++];
    for(k=0;k<(end-start)+1;k++)
    arr[k+start]=temp[k];
}