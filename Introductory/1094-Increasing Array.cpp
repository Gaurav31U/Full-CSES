#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    long long ans=0;
    int a;cin>>a;
    for(int i=1;i<n;i++){
        int b;cin>>b;
        ans+=(b<a?a-b:0);
        a=max(a,b);
    }
    cout<<ans;
    return 0;
}