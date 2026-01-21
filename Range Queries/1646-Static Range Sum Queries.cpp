#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;cin>>n>>q;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i>0)arr[i]+=arr[i-1];
    }
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        long long temp=arr[b]-(a>0?arr[a-1]:0);
        cout<<temp<<"\n";
    }
}