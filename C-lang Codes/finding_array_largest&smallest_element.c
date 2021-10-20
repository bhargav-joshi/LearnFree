/* Write a program to store random numbers into an array of n integers and then find out the smallest and largest number stored in it. n is the user input.
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{   int n,i,large,small;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the %d elements of the array: ",n);
    for(i=0;i<n;i++)
    {   a[i]=rand()%100;
        printf("%d\n",a[i]);
    }
    large=a[0];
    for(i=1;i<n;i++)
    {   if(large<a[i])
            large=a[i];
    }
    printf("\nLargest element is: %d",large);
    small=a[0];
    for(i=1;i<n;i++)
    {   if(small>a[i])
            small=a[i];
    }
    printf("\nSmallest element is: %d",small);
    return 0;
}
