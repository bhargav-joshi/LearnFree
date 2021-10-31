#include <stdio.h>


int main()
{
    int a,b;

    printf("Enter a number\n");

    scanf("%d",&a);

    for(b=1;b<=a;b++){

        if(a%b==0){printf("%d is the factor of %d\n",b,a);}


    }
    return 0;
}
