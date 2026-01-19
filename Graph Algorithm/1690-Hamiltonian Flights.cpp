#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
const int N=21;
const int maxN=(1<<21);
int n,m,k;
int inqueue[N][maxN];
int dp[N][maxN];
vector<int> adj[N];
signed main(){
     cin>>n>>m;
     for(int i=0;i<m;i++){
         int a,b;cin>>a>>b;
         adj[a-1].push_back(b-1);
     }
     queue<pair<int,int>> q;
     dp[0][1]=1;
     inqueue[0][1]=1;
     q.push({0,1});
     while(!q.empty()){
         int u=q.front().first;
         int mask=q.front().second;
         q.pop();
         
         if(u!=n-1){
             for(auto v:adj[u]){
                 int newmask=mask|(1<<v);
                 if((mask&(1<<v))==0){
                     dp[v][newmask]+=dp[u][mask];
                     dp[v][newmask]%=MOD;
                     if(!inqueue[v][newmask]){
                         q.push({v,newmask});
                         inqueue[v][newmask]=1;
                     }
                 }
             }
         }
         
     }
     cout<<dp[n-1][(1<<n)-1];
    return 0;
}