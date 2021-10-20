#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
int Sec_Max(int arr[],int arr_size);
int Sec_Min(int arr[],int arr_size);

int main()
{   int i,n;
    printf("Enter the number of an element \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements in an array \n");
    for(i=0;i<n;i++)
    {   arr[i]=rand();
        printf("%d\n",arr[i]);
    }

    int sec_max=Sec_Max(arr,n);
    int sec_min=Sec_Min(arr,n);
    printf("Second Largest element in an array is:- %d",sec_max);
    printf("\nSecond Smallest element in an array is:- %d",sec_min);
    return 0;
}
int Sec_Max(int arr[],int arr_size)
{   int i,first,second;
    first=second=INT_MIN;
    for(i=0;i<arr_size;i++)
    {   if(arr[i]>first)
        {   second=first;
            first=arr[i];
        }
        else if(arr[i]>second && arr[i]!=first)
            second=arr[i];
    }
    //printf("The second largest element is %d \n",second);
    return second;
}
int Sec_Min(int arr[],int arr_size)
{   int i,first,second;
    first=second=INT_MAX;
    for(i=0;i<arr_size;i++)
    {   if(arr[i]<first)
        {   second=first;
            first=arr[i];
        }
        else if(arr[i]<second && arr[i]!=first)
            second=arr[i];
    }
    //printf("The second smallest element is %d \n",second);
    return second;
}
