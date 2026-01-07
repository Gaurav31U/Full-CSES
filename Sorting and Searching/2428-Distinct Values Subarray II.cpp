#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    vector<int> vi(n);
    for(int i=0;i<n;i++){
        cin>>vi[i];
    }
    set<int> st;
    map<int,int> mp;
    int j=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        st.insert(vi[i]);
        mp[vi[i]]++;
        while(st.size()>k){
            mp[vi[j]]--;
            if(mp[vi[j]]==0){
                st.erase(st.find(vi[j]));
            }
            j++;
        }
        ans+=(i-j+1);
    }
    cout<<ans;
    return 0;
}