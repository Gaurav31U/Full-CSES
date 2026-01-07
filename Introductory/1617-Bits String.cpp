#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
long long binpow(long long a,long long b){
    long long res=1;
    while(b>0){
        if(b%2==0){
            (a*=a)%=mod;
            b>>=1;
        }else{
            (res*=a)%=mod;
            b--;
        }
    }
    return res;
}
int main(){
    int n;cin>>n;
    cout<<binpow(2,n);
    return 0;
}