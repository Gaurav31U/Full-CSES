#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin>>n>>x;
    vector<int> vi(n);
    for(int i=0;i<n;i++)cin>>vi[i];
    int mod=1e9+7;
    sort(vi.begin(),vi.end());
    vector<long long> dp(x+1,0);
    dp[0]=1;
    for(int j=0;j<n;j++){
        for(int i=0;i<=x;i++){
            if(i>=vi[j]){
                (dp[i]+=dp[i-vi[j]])%=mod;
            }
        }
    }
    cout<<dp[x];
    return 0;
}