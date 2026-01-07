#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;cin>>n;
    long long sum=0;
    for(int i=1;i<n;i++){
        int a;cin>>a;
        sum+=a;
    }   
    cout<<((n+1)*n)/2-sum;
    return 0;
}