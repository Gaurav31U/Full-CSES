#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
const int INF=1e12;
vector<int> adj[N];
int lca[N][22];
int level[N];
 
void dfs(int i=1,int par=-1,int d=1){
  lca[i][0]=par;
  level[i]=d;
  for(auto it:adj[i]){
    if(it==par)continue;
    dfs(it,i,d+1);
  }
}
 
void init(){
  dfs(); 
  for(int j=1;j<=20;j++){
    for(int i=1;i<=n;i++){
      if(lca[i][j-1]!=-1){
        int par=lca[i][j-1];
        lca[i][j]=lca[par][j-1];
      }
    }
  }
} 
 
int LCA(int b,int d){
  if(level[b]<d)return -1;
  while(d>0){
    int i=log2(d);
    b=lca[b][i];
    d-=(1<<i);
  }
  return b;
}
 
signed main(){
  cin>>n>>m;
  memset(lca,-1,sizeof(lca));
  for(int i=2;i<=n;i++){
    int a;cin>>a;
    adj[a].push_back(i);
  }
  init();
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    int t=LCA(a,b);
    cout<<t<<"\n";
  }
  return 0;
}