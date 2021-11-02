#include <bits/stdc++.h>
using namespace std;
int matrixsearch(int arr[][100], int m, int n, int key)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == key)
            {
                cout << "1";
                return 0;
            }
            
        }
    }
    cout<<0;
    return 0;
}

int main()
{
    int m, n, key;
    cin >> m >> n;
    int a[100][100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "enter the key";
    cin >> key;
    matrixsearch(a, m, n, key);
}
