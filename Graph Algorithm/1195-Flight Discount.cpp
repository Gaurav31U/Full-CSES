#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int INF=1e15;
vector<pair<int,int>> adj[100001];
vector<pair<int,int>> rev[100001];
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  vector<vector<int>> edges;
  for(int i=0;i<m;i++){
    int a,b,c;cin>>a>>b>>c;
    adj[a].push_back({b,c});
    rev[b].push_back({a,c});
    edges.push_back({a,b,c});
  }
  vector<int> disa(n+1,INF);
  vector<int> disb(n+1,INF);
  disa[1]=0;
  disb[n]=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,1});
  while(!pq.empty()){
    auto tp=pq.top();
    pq.pop();
    int node=tp.second;
    if(disa[node]!=tp.first)continue;
    for(auto it:adj[node]){
      if(disa[it.first]>disa[node]+it.second){
        disa[it.first]=disa[node]+it.second;
        pq.push({disa[it.first],it.first});
      }
    }
  }
  pq.push({0,n});
  while(!pq.empty()){
    auto tp=pq.top();
    pq.pop();
    int node=tp.second;
    if(disb[node]!=tp.first)continue;
    for(auto it:rev[node]){
      if(disb[it.first]>disb[node]+it.second){
        disb[it.first]=disb[node]+it.second;
        pq.push({disb[it.first],it.first});
      }
    }
  }
  int ans=INF;
  for(auto it:edges){
    ans=min(ans,disa[it[0]]+disb[it[1]]+it[2]/2);
  }
  cout<<ans;
  return 0;
}