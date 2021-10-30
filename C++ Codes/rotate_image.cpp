#include <bits/stdc++.h>
using namespace std;

void rotateimage(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        reverse(a[i], a[i] + n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)//i<j because we swap only the upper part  of the triangle
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}
int main()
{

    int  n;
    cin >> n;
    int a[100][100];
    int val = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = val;
            val = val + 1;
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
    rotateimage(a,n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
            cout << a[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
