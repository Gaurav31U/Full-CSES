#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int ans=0;
    long long k=5;
    while(n>=k){
        ans+=(n/k);
        k*=5;
    }
    cout<<ans;
    return 0;
}