#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    long long mx=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        long long a;cin>>a;
        mx=max(a,mx);
        sum+=a;
    }
    cout<<max(sum,2*mx);
    return 0;
}