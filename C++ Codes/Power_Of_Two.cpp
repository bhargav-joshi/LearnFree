#include <bits/stdc++.h>
using namespace std;

 bool isPowerOfTwo(int n) {
    int cnt = 0;
    while(n>0){
        cnt++;
        n = n & (n-1);
    }
    cout<<cnt<<endl;
    if(cnt==1) return true;
    else return false;
     
 } 



int main()   
{    
    int t;
    cin >> t;
    while (t--)
    {
        int n,cnt=0;
        cin >>n;
        cout<<isPowerOfTwo(n)<<endl;
        
    }
    return 0;
}    