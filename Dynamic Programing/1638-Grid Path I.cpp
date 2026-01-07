#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int mod=1e9+7;
    vector<string> vi(n);
    for(int i=0;i<n;i++)cin>>vi[i];
    int m=vi[0].size();
    vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
    dp[n-1][m-1]=(vi[n-1][m-1]=='*'?0:1);
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(vi[i][j]=='*')continue;
            (dp[i][j]+=(dp[i+1][j] + dp[i][j+1]))%=mod;
        }
    }
    cout<<dp[0][0];
    return 0;
}