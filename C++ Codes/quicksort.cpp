#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& a,int s,int e)
{
    int i=s-1;
    int pivot=a[e];
    int j;
    for(j=s;j<e;j++)
    {
        if(a[j]<pivot)
        {
            i++;
        swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}
void quicksort(vector<int>& a,int s,int e)
{
    //base case
    if(s>=e)
    return;
    int p=partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}
int main()
{
    vector<int>arr{21,4,32,2,78,66,9,90,1};
    int s=0,e=arr.size()-1;
    quicksort(arr,s,e);
    for(int x:arr)
    {
        cout<<x<<",";
    }
}
