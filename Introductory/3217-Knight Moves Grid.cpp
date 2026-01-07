#include <bits/stdc++.h>
using namespace std;
int dx[8]={2,1,-2,-1,-1,-2,1,2};
int dy[8]={1,2,1,2,-2,-1,-2,-1};
int main(){
    int n;cin>>n;
    vector<vector<int>> grid(n,vector<int>(n,INT_MAX));
    auto dfs=[&](auto&& dfs,int c,int v,int dis)->void{
        grid[c][v]=dis;
        queue<pair<int,int>> q;
        q.push({c,v});
        while(!q.empty()){
            auto tp=q.front();
            int i=tp.first;
            int j=tp.second;
            q.pop();
            for(int k=0;k<8;k++){
                int x=dx[k]+i;
                int y=dy[k]+j;
                if(x>=0 && y>=0 && x<n && y<n && (grid[x][y]>grid[i][j]+1)){
                    q.push({x,y});
                    grid[x][y]=grid[i][j]+1;
                }
            }
        }
    };
    dfs(dfs,0,0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}