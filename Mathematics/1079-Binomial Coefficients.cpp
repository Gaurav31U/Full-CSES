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
    vector<int> fac(1e6+1,1);
    for(int i=2;i<=1e6;i++){
        fac[i]=(i*fac[i-1])%mod;
    }
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        int ans=(fac[a]*binpow(fac[b],mod-2,mod))%mod;
        ans=(ans*binpow(fac[a-b],mod-2,mod))%mod;
        cout<<ans<<"\n";
    }
}