#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin>>n>>x;
    vector<int> vi(n+1,0);
    for(int i=0;i<n;i++)cin>>vi[i];
    vector<long long> dp(x+2,INT_MAX);
    dp[0]=0;
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=vi[j]){
                dp[i]=min(dp[i-vi[j]]+1,dp[i]);
            }
        }
    }
    if(dp[x]==INT_MAX)cout<<-1;
    else cout<<dp[x];
    return 0;
}