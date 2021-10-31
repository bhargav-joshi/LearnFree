#include<stdio.h>
 
int main() {
   int a, b;
 
   printf("\nEnter two no: ");
   scanf("%d %d", &a, &b);
 
   printf("Difference is  : %d", (a + ~b + 1));
 
   return 0;
}
