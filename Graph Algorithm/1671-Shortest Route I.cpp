#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[100001];
int vis[1000001];
long long dis[1000001];
void dikstra(){
    dis[1]=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto tp=pq.top();
        pq.pop();
        if(dis[tp.second]!=tp.first)continue;
        for(auto it:adj[tp.second]){
            if(dis[it.first]>dis[tp.second]+it.second){
                dis[it.first]=dis[tp.second]+it.second;
                pq.push({dis[it.first],it.first});
            }
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
    for(int i=1;i<=n;i++){
        dis[i]=1e15;
    }
    dikstra();
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}