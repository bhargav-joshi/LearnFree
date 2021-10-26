#include<stdio.h>
#include<conio.h>
void merge(int [],int,int,int);
void mergesort(int [],int,int);

main()
{
   int i,j,n, a[10];
   //clrscr();
   printf("\nEnter the length of the Array:");
   scanf("%d", &n);
   printf("\nEnter the unsorted Array\n");
   for (i=0;i<n;i++)
    {
     printf("A[%d]=",i+1);
     scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);

    for (i=0;i<n;i++)
     printf("%d ",a[i]);
}

void mergesort(int a[],int beg,int end)
{
    int mid;

    if(beg<end)
    {
        mid = (beg+end)/2;


        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);

        merge(a,beg,mid,end);

    }

}

void merge(int a[],int beg,int mid,int end)
{
    int i=beg ,j=mid+1 ,k=beg ,temp[10],z;


    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            i=i+1;
        }
        else
        {
            temp[k]=a[j];
            j=j+1;
        }
        k=k+1;
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        temp[k]=a[j];
        j++;
        k++;
    }


    for(z=beg;z<k;z++)          // this is to copy the sorted array temp back into array "a"
    {
        a[z]=temp[z];
    }
}




