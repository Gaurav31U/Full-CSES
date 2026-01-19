#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
  cin>>n>>m;
  vector<string> grid;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    grid.push_back(s);
  }
  queue<pair<int,int>> q;
  map<pair<int,int>,char> par;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(grid[i][j]=='A'){
        q.push({i,j});
        par[{i,j}]='E';
        break;
      }
    }
    if(!q.empty())break;
  }
  unordered_map<char,pair<int,int>> rev;
  rev['D']={-1,0};
  rev['U']={1,0};
  rev['L']={0,1};
  rev['R']={0,-1};
  vector<vector<int>> dxy={{0,-1,'L'},{1,0,'D'},{0,1,'R'},{-1,0,'U'}};
  vector<vector<int>> vis(n,vector<int>(m,0));
  while(!q.empty()){
    auto tp=q.front();
    q.pop();
    int x=tp.first;
    int y=tp.second;
    vis[x][y]=1;
    if(grid[x][y]=='B'){
      break;
    }
    for(int i=0;i<4;i++){
      int nx=x+dxy[i][0];
      int ny=y+dxy[i][1];
      if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0 && grid[nx][ny]!='#'){
        vis[nx][ny]=1;
        par[{nx,ny}]=char(dxy[i][2]);
        q.push({nx,ny});
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(grid[i][j]=='B'){
        if(par.count({i,j})){
            string path="";
            while(par[{i,j}]!='E'){
              path+=par[{i,j}];
              int p=i;
              i+=rev[par[{i,j}]].first;
              j+=rev[par[{p,j}]].second;
            }
            reverse(path.begin(),path.end());
            cout<<"YES\n";
            cout<<path.size()<<"\n";
            cout<<path;
            return 0;
        }else{
          cout<<"NO\n";
          return 0;
        }
      }
 
    }
  }
  return 0;

}