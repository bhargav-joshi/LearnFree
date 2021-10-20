Roman numbers prgm using cpp
#include <iostream>
#include <string>
using namespace std;

string roman(int n)
{
    string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int num[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string s="";
    for(int i=0;i<13;i++)
    {
        while(n-num[i]>=0)
        {
            s+=roman[i];
            n-=num[i];
        }
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    cout<<roman(n);
    return 0;
}
