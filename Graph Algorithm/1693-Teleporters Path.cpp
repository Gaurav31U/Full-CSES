#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
int n,m,k;
int in[N],vis[N];
vector<int> route,adj[N];
void dfs(int u,int p=-1){
    vis[u]=1;
    for(auto v:adj[u])
        if(v!=p && !vis[v])
            dfs(v,u);
 
}
signed main(){
     cin>>n>>m;
     for(int i=0,a,b;i<m;i++){
         cin>>a>>b;
         adj[a].push_back(b);
         in[b]++;
     }
     dfs(1);
     bool exists=vis[n];
     exists &= (in[1]+1==(int)(adj[1].size()));
     exists &= (in[n]-1==(int)(adj[n].size()));
     for(int i=2;i<n;i++){
         exists &= (in[i]==(int)adj[i].size());
         if(!vis[i])exists &= (in[i]==0 && adj[i].size()==0);
     }
     if(!exists){
         cout<<"IMPOSSIBLE";
         return 0;
     }
     stack<int> st;
     st.push(1);
     while(!st.empty()){
         auto u=st.top();
         if(!adj[u].empty()){
             int v=adj[u].back();
             adj[u].pop_back();
             st.push(v);
         }else{    
             route.push_back(u);
             st.pop();
         }
     }
     reverse(route.begin(),route.end());
     for(int i=0;i<m+1;i++)cout<<route[i]<<" ";
    return 0;
}
