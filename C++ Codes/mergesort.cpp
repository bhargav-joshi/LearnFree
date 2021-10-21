#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& array,int s,int e)
{
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    vector<int>temp;
    while(i<=m  and j<=e)
    {
        if(array[i]<array[j])
        {
            temp.push_back(array[i]);
            i++;
        }
        else
        {
            temp.push_back(array[j]);
            j++;
        }
    }
    while(i<=m)
    {
        temp.push_back(array[i++]);
    }
     while(j<=e)
    {
        temp.push_back(array[j++]);
    }
     int x,k=0;
    for(x=s;x<=e;x++)
    {
        array[x]=temp[k];
        k++;
    }
  
    return;
}
void mergesort(vector<int> &arr,int s,int e)
{
    if(s>=e)
    return;
    int mid=(s+e)/2;

    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    return merge(arr,s,e);
    
    
}
int main()
{
    vector<int>arr{21,4,32,2,78,66,9,90,1};
    int s=0,e=arr.size()-1;
    mergesort(arr,s,e);
    for(int x:arr)
    {
        cout<<x<<",";
    }
}
