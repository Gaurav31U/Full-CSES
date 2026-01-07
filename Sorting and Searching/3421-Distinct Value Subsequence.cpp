#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]++;
    }
    long long ans=1;
    int mod=1e9+7;
    for(auto it:mp)(ans*=(it.second+1))%=mod;
    ans=(ans-1+mod)%mod;
    cout<<ans;
    return 0;
}