#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int binpow(int a,int b,int mod){
    int res=1;
    while(b>0){
        if(b&1){
            (res*=a)%=mod;
            b--;
        }else{
            (a*=a)%=mod;
            b>>=1;
        }
    }
    return res;
}
signed main(){
    vector<int> fac(2e6+1,1);
    for(int i=2;i<=2e6;i++){
        fac[i]=(i*fac[i-1])%mod;
    }
    int n,m;cin>>n>>m;
    int ans=fac[n+m-1];
    ans=(ans*(binpow(fac[n-1],mod-2,mod)))%mod;
    ans=(ans*(binpow(fac[m],mod-2,mod)))%mod;
    cout<<ans;
}