#include<bits/stdc++.h>

using namespace std;

void bfs(list<int>* adj,int s){
    queue<int> q;
    vector<bool> visited(4,0);

    visited[s]=1;
    q.push(s);

    while(!q.empty()){
        int i=q.front();
        cout<<i<<" ";
        q.pop();
        for(auto j=adj[i].begin();j!=adj[i].end();j++){
            if(visited[*j]==0){
                q.push(*j);
                visited[*j]=1;
            }
        }
    }
}
int main(){
    list<int>* adj;
    adj= new list<int>[4];
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(0);
    adj[3].push_back(2);

    bfs(adj,2);
}
