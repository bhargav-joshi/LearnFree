#include <stdio.h>


int main()

{
    int base,exponent;
    long long power=1;
    int i;

    printf("Enter the base number\n");
    scanf("%d",&base);
    printf("Enter the exponent\n");
    scanf("%d",&exponent);
    for(i=1;i<=exponent;i++){

        power=power*base;

    }
    printf("%d^%d=%ld",base,exponent,power);

    return 0;
}
