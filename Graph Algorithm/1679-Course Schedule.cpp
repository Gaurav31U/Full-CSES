#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=2e5+1;
vector<int> adj[N];
int ind[N]; 
signed main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    ind[b]++;
    adj[a].push_back(b);
  }
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(ind[i]==0)q.push(i);
  }
  if(q.empty()){
    cout<<"IMPOSSIBLE";
    return 0;
  }
  vector<int> ans;
  while(!q.empty()){
    auto tp=q.front();
    q.pop();
    ans.push_back(tp);
    for(auto it:adj[tp]){
      if(--ind[it]==0){
        q.push(it);
      }
    }
  }   
  if(ans.size()!=n){
    cout<<"IMPOSSIBLE";
    return 0;
  }
  for(auto it:ans)cout<<it<<" ";
  return 0;
}
