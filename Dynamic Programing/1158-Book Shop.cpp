#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin>>n>>x;
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    vector<int> price(n),page(n);
    for(int i=0;i<n;i++)cin>>price[i];
    for(int i=0;i<n;i++)cin>>page[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(price[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-price[i-1]]+page[i-1]);
            }else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][x];
    return 0;
}