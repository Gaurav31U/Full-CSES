#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=1e5+1;
const int MOD=1e9+7;
const int INF=0x3f;
vector<pair<int,int>> adj[N];
int dis[N],minR[N],maxR[N],dp[N];
struct comparator{
  bool operator()(int a,int b)const {
    return (dis[a]==dis[b]?a<b:dis[a]<dis[b]);
  }
};
signed main(){
  cin>>n>>m;
  memset(dis,0x3f,sizeof(dis));
  for(int i=0;i<m;i++){
    int a,b,c;cin>>a>>b>>c;
    adj[a].push_back({b,c});
  }
  dis[1]=0;
  dp[1]=1;
  set<int,comparator> pq;
  pq.insert(1);
  while(!pq.empty()){
    auto u=*pq.begin();
    pq.erase(pq.begin());
    for(auto v:adj[u]){
      if(dis[u]+v.second<=dis[v.first]){
        if(dis[v.first]!=INF)pq.erase(v.first);
        if(dis[u]+v.second==dis[v.first]){
          (dp[v.first]+=dp[u])%=MOD;
          minR[v.first]=min(minR[v.first],minR[u]+1);
          maxR[v.first]=max(maxR[v.first],maxR[u]+1);
        }
        if(dis[u]+v.second<dis[v.first]){
          dis[v.first]=dis[u]+v.second;
          dp[v.first]=dp[u];
          minR[v.first]=minR[u]+1;
          maxR[v.first]=maxR[u]+1;
        }
        pq.insert(v.first);
      }
    }
  }
  cout<<dis[n]<<" "<<dp[n]<<" "<<minR[n]<<" "<<maxR[n];
  return 0;
}