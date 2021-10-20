/*  Write a program to store random numbers into an array of n integers, where the array must contains some duplicates. Do the following:
a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.
*/

#include<stdio.h>
#include<stdlib.h>
int duplicate(int a[],int n)
{   int i,j,count;
    count=0;
    for(i=0;i<n;i++)
    {   for(j=i+1;j<n;j++)
        {   if(a[i]==a[j])
            {   count++;
                break;
            }
        }
    }
    return count;

}

int repeating(int a[],int n)
{   int i,j,maxElement,count;
    int maxCount=0;
    for(i=0;i<n;i++)
    {   count=1;
        for(j=i+1;j<n;j++)
        {   if(a[j]==a[i])
            {   count++;
                if(count>maxCount)
                    maxElement=a[j];
            }
        }
    }
    return maxElement;
}
int main()
{   int n,i,c1,c2,count,j;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the %d elements of the array: ",n);
    for(i=0;i<n;i++)
    {   scanf("%d",&a[i]);
    }

    c1=duplicate(a,n);
    c2=repeating(a,n);
    printf("\nDuplictes are : %d",c1);
    printf("\nMost repeating are : %d",c2);
    return 0;
}
