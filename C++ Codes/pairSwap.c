#include<stdio.h>

void main()
{
  int n, i, j;
  printf("Enter the number of elements in the array to be searched: ");
  scanf("%d", &n);
  int a, b= 0;
  int arr[n];
  printf("Enter the elements of the array: ");
  for(i=0; i<n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int m= n;
  if(m%2 ==1)
    m--;
  i=0; j=m-1;
  int temp;
  while(i<=j)
  {
    temp = arr[i];
    arr[i] = arr[j-1];
    arr[j-1] = temp;
    temp = arr[i+1];
    arr[i+1] = arr[j];
    arr[j] = temp;
    i+=2; j-=2;
  }
  printf("After swapping in pairs: ");
  for(i=0; i<n; i++)
  {
    printf("%d  ", arr[i]);
  }
}
