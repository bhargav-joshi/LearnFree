#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    int i=0;
    int n=intervals.size(),s=-1,e=-1;
    while(i<n){
        if(s==-1){
            s=intervals[i][0];
            e=intervals[i][1];
            i++;
        }
        else{
            if(intervals[i][0]<=e){
                e=max(e,intervals[i][1]);
                i++;
            }
            else{
                ans.push_back(vector<int>{s, e});
                s=intervals[i][0];
                e=intervals[i][1];
                i++;
            }
        }
    }
    if(s!=-1){
        ans.push_back(vector<int>{s, e});
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        intervals[i].push_back(a);
        intervals[i].push_back(b);
    }
    vector<vector<int>> ans = merge(intervals);
    cout<<"Intervals after merge operation are:\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }
}
