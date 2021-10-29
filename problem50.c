// Get two numbers of up to 50 digits and perform addition and
// print the result

#include <stdio.h>

int main()
{
    int rem, carry;
    int a[50], b[50], sum[51];

    printf("Enter first number : \n");
    for (int i = 0; i < 3; i++)
        scanf("%d", &a[i]);

    printf("Enter second number : \n");
    for (int i = 0; i < 3; i++)
        scanf("%d", &b[i]);

    for (int i = 0; i < 3; i++)
    {
        sum[i] = a[i] + b[i];
        // printf("%d ", sum[i]);
    }

    for (int i = 2; i >= 0; i--)
    {
        // printf("%d ", sum[i]);
        if (sum[i] > 9)
        {
            rem = sum[i] % 10;
            carry = sum[i] / 10;
            sum[i - 1] = sum[i - 1] + carry;
            sum[i] = rem;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        // sum[i] = a[i] + b[i];
        printf("%d", sum[i]);
    }
    return 0;
}