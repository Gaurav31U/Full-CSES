#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int t;cin>>t;
    while(t){
        int a,b;cin>>a>>b;
        cout<<binpow(a,b,1e9+7)<<"\n";
        t--;
    }
    return 0;
}