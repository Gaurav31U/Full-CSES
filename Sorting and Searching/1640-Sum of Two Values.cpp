#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin>>n>>x;
    map<int,int> mp;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(mp.count(x-a[i])){
            cout<<mp[x-a[i]]<<" "<<i+1;
            return 0;
        }
        mp[a[i]]=i+1;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}