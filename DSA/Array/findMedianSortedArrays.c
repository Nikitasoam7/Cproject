// Program for finding median of two sorted array with Olog(m+n) time complexcity
#include<stdio.h>
#define SIZE1 6
#define SIZE2 5
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);
int main()
{
    int nums1[SIZE1],nums2[SIZE2];
    printf("Program for finding median of two sorted array\n");
    printf("Enter %d numbers:",SIZE1);
    int i;
    for(i=0;i<SIZE1;i++)
    scanf("%d",&nums1[i]);
    printf("Enter %d numbers:",SIZE2);
    for(i=0;i<SIZE2;i++)
    scanf("%d",&nums2[i]);
    double median=findMedianSortedArrays(nums1,SIZE1,nums2,SIZE2);
    printf("%lf",median);
    return 0;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int temp[nums1Size+nums2Size];
    int i=0,j=0,k=0;
    while(i<nums1Size && j<nums2Size)
    {
        if(nums2[j]<nums1[i])
        temp[k]=nums2[j++];
        else
        temp[k]=nums1[i++];
        k++;
    }
    while(i<nums1Size)
    temp[k++]=nums1[i++];
    while(j<nums2Size)
    temp[k++]=nums2[j++];
    double median;
    int n1=(nums1Size+nums2Size)/2;
    if((nums1Size+nums2Size)%2==0)
    median=(double)(temp[n1]+temp[n1-1])/2;
    else median=temp[n1];
    return median;
}