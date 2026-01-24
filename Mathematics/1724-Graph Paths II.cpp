#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=101;
const int INF=2e18;
const int MOD=1e9+7;
int n,m,k;
int a[N][N],b[N][N];
void combine(int A[N][N],int B[N][N]){
    int C[N][N];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j]=INF;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(A[i][k]!=INF && B[k][j]!=INF)
                C[i][j]=min(C[i][j],A[i][k]+B[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=C[i][j];
        }
    }
}
signed main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=b[i][j]=INF;
        }
        b[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int x,y,z;cin>>x>>y>>z;
        a[x-1][y-1]=min(a[x-1][y-1],z);
    }
    while(k>0){
        if(k&1){
            combine(b,a);
            k--;
        }else{
            combine(a,a);
            k>>=1;
        }
    }
    if(b[0][n-1]==INF)cout<<-1;
    else cout<<b[0][n-1];
    return 0;
}