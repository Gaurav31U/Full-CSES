#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;cin>>n>>m>>q;
    vector<vector<long>> dis(n+1,vector<long>(n+1,1e15));
    for(int i=0;i<m;i++){
        long a,b,w;cin>>a>>b>>w;
        dis[a][b]=min(dis[a][b],w);
        dis[b][a]=min(dis[b][a],w);
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        if(dis[a][b]>=1e15){
            cout<<-1<<"\n";
        }else{
            cout<<dis[a][b]<<"\n";
        }
    }
    return 0;
}