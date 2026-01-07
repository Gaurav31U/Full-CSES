#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        long long n=i*i;
        long long ans=(n*(n-1))/2;
        long long temp=0;
        temp+=(i-4)*(i-4)*8;
        temp+=(i-4)*4*6;
        temp+=(i-3)*4*4;
        temp+=(3*8);
        temp+=(2*4);
        temp/=2;
        cout<<ans-temp<<"\n";
    }
    return 0;
}