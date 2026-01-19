#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<string> grid;
int vis[1001][1001];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
void dfs(int i,int j){
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int x=dx[k]+i;
        int y=dy[k]+j;
        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]=='.' && vis[x][y]==0){
            dfs(x,y);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string a;cin>>a;
        grid.push_back(a);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && vis[i][j]==0){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}