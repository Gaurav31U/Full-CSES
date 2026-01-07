#include <bits/stdc++.h>
using namespace std;
vector<int> digit(int n){
    vector<int> num;
    while(n>0){
        num.push_back(n%10);
        n/=10;
    }
    return num;
}
int main(){
    int n;cin>>n;
    vector<long long> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        auto vi=digit(i);
        for(auto it:vi){
            dp[i]=min(dp[i-it]+1,dp[i]);
        }
    }
    cout<<dp[n];
    return 0;
}