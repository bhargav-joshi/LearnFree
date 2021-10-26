#include <stdio.h>

// function to sort the array in ascending order
void Array_sort(int *array , int n)
{ 
    // declare some local variables
    int i=0 , j=0 , temp=0;

    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n-1 ; j++)
        {
            if(array[j]>array[j+1])
            {
                temp        = array[j];
                array[j]    = array[j+1];
                array[j+1]  = temp;
            }
        }
    }

    printf("\nThe array after sorting is..\n");
    for(i=0 ; i<n ; i++)
    {
        printf("\narray_1[%d] : %d",i,array[i]);
    }
}

// function to calculate the median of the array
float Find_median(int array[] , int n)
{
    float median=0;
    
    // if number of elements are even
    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    // if number of elements are odd
    else
        median = array[n/2];
    
    return median;
}

int main()
{
    // declare two int arrays
    int array_1[30] = {0};
    // declare some local variables
    int i=0 ,n=0;
    float median=0;

    printf("\nEnter the number of elements for the array : ");
    scanf("%d",&n);
   
    printf("\nEnter the elements for array_1..\n");
    for(i=0 ; i<n ; i++)
    {
        printf("array_1[%d] : ",i);
        scanf("%d",&array_1[i]);
    }
    
    // Sort the array in ascending order
    Array_sort(array_1 , n);
    
    // Now pass the sorted array to calculate
    // the median of your array.
    median = Find_median(array_1 , n);
    
    printf("\n\nThe median is : %f\n",median);
    return 0;
}
