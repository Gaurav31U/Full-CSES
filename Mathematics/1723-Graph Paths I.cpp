#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=101;
const int MOD=1e9+7;
int n,m,k;
int a[N][N],b[N][N];
void mul(int A[N][N],int B[N][N]){
    int C[N][N];
    memset(C,0,sizeof(C));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                (C[i][j]+=(A[i][k]*B[k][j]))%=MOD;
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
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        a[x-1][y-1]++;
    }
    for(int i=0;i<n;i++)b[i][i]=1;
    while(k>0){
        if(k&1){
            mul(b,a);
            k--;
        }else{
            mul(a,a);
            k>>=1;
        }
    }
    cout<<b[0][n-1];
    return 0;
}