#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int MOD=1e9+7;
vector<vector<int>> matrix_mul(vector<vector<int>> a,vector<vector<int>> b){
  int n=a.size();
  int m=b.size();
  int l=b[0].size();
  vector<vector<int>> res(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<l;j++){
      for(int k=0;k<m;k++){
        (res[i][j]+=(a[i][k]*b[k][j]))%=MOD;
      }
    }
  }
  return res;
}
vector<vector<int>> binmat(vector<vector<int>> a,int b){
  int n=a.size();
  vector<vector<int>> res(n,vector<int>(n,0));
  for(int i=0;i<n;i++)res[i][i]=1;
  while(b>0){
    if(b&1){
      res=matrix_mul(res,a);
      b--;
    }else{
      a=matrix_mul(a,a);
      b>>=1;
    }
  } 
  return res;
}
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n;
  vector<vector<int>> a={{0,0,0},{0,0,1},{0,1,1}};
  auto ans=binmat(a,n);
  cout<<ans[2][1];
  return 0;
}