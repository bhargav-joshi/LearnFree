#include <bits/stdc++.h>
using namespace std;

int bitonicstringmaxlength(int a[], int n)
{
    int inc[n];
    int dec[n];
    inc[0] = 1;
    dec[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] <= a[i])
        {
            inc[i]=inc[i-1]+1;
        }
        else if (a[i - 1] > a[i])
        {
            inc[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= a[i+1])
        {
            dec[i]=dec[i+1]+1;
        }
        else if (a[i] < a[i+1])
        {
            dec[i] = 1;
        }
    }

    int max = inc[0] + dec[0] - 1;
    for (int i = 0; i < n; i++)
    {
        if (inc[i] + dec[i] - 1 > max)
        {
            max = inc[i] + dec[i] - 1;
        }
    }
    return max;
}
int main()
{
    int a[1000], n;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout<<bitonicstringmaxlength(a, n);
    return 0;
}
