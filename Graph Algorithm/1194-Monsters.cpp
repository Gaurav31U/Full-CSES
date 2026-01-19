#include <bits/stdc++.h>
using namespace std;
int n,m;
int dis[1001][1001];
int vis[1001][1001];
int par[1001][1001];
int main(){
  cin>>n>>m;
  int a,b;
  vector<string> grid;
  vector<pair<int,int>> escape;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    grid.push_back(s);
  }
  unordered_map<char,pair<int,int>> rev;
  rev['U']={1,0};
  rev['R']={0,-1};
  rev['D']={-1,0};
  rev['L']={0,1};
  int mx=1e7;
  queue<array<int,3>> q;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      dis[i][j]=mx;
      if(grid[i][j]=='M'){
        q.push({i,j,0});
      }
      if(grid[i][j]=='A'){
        a=i;
        b=j;
      }
      if((i==0 || i==n-1 || j==0 || j==m-1)){
        if(grid[i][j]=='A'){
          cout<<"YES\n";
          cout<<0;
          return 0;
        }
        if(grid[i][j]=='.')
        escape.push_back({i,j});
      }
    }
  }
  vector<vector<int>> dxy={{0,1,'R'},{0,-1,'L'},{1,0,'D'},{-1,0,'U'}};
  while(!q.empty()){
    auto tp=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int x=dxy[i][0]+tp[0];
      int y=dxy[i][1]+tp[1];
      if(x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#' && dis[x][y]>tp[2]+1){
        dis[x][y]=tp[2]+1;
        q.push({x,y,tp[2]+1});
      }
    }
  }
  vis[a][b]=1;
  q.push({a,b,0});
  while(!q.empty()){
    auto tp=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int x=dxy[i][0]+tp[0];
      int y=dxy[i][1]+tp[1];
      if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0 && grid[x][y]!='#' && (tp[2]+1)<dis[x][y] ){
        vis[x][y]=1;
        par[x][y]=dxy[i][2];
        q.push({x,y,tp[2]+1});
      }
    }
  }
  par[a][b]='E';
  for(auto it:escape){
    auto x=it.first;
    auto y=it.second;
    if(par[x][y]!=0){
      string ans = "";
      while((x!=a || y!=b)){
        char p=par[x][y];
        ans+=p;
        x+=rev[p].first;
        y+=rev[p].second;
      }
      reverse(ans.begin(),ans.end());
      cout<<"YES\n";
      cout<<ans.size()<<"\n";
      cout<<ans;
      return 0;
    }
  }
  cout<<"NO\n";
  return 0;
}