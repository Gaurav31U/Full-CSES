#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i>0)arr[i]^=arr[i-1];
    }
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        int temp=arr[b]^(a>0?arr[a-1]:0);
        cout<<temp<<"\n";
    }
    return 0;
}