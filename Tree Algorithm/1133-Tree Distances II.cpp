#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
vector<int> adj[N];
int in[N],out[N],sub[N],val[N],dep[N];
int timer=1;
int dfs(int i=1,int par=0,int d=0){
  dep[i]=d;
  int ans=1;
  for(auto it:adj[i]){
    if(it==par)continue;
    ans+=dfs(it,i,d+1);
  }
  return sub[i]=ans;
}
int dfs1(int i=1,int par=0){
  int ans=dep[i];
  in[i]=timer++;
  for(auto it:adj[i]){
    if(it==par)continue;
    ans+=dfs1(it,i);
  }
  out[i]=timer++;
  return ans;
}
void dfs2(int i=1,int par=0,int t=val[1]){
  if(par!=0){
    val[i]=t+(n-sub[i])-sub[i];
  }
  for(auto it:adj[i]){
    if(it==par)continue;
    dfs2(it,i,val[i]);
  }
}
signed main(){
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a); 
  }
  dfs();
  val[1]=dfs1();
  dfs2();
  for(int i=1;i<=n;i++){
    cout<<val[i]<<" ";
  }
  return 0;
} 
