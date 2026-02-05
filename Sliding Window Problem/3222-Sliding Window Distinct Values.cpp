#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    
    map<int,int> mp;
    set<int> st;

    
    vector<int> ans,vi(n);

    for(int i=0;i<n;i++)cin>>vi[i];

    for(int i=0;i<k;i++){
        mp[vi[i]]++;
        st.insert(vi[i]);
    }
    if(n==k){
        cout<<st.size();
        return 0;
    }
    ans.push_back(st.size());
    for(int i=k;i<n;i++){
        mp[vi[i-k]]--;
        if(mp[vi[i-k]]==0){
            st.erase(vi[i-k]);
        }
        mp[vi[i]]++;
        st.insert(vi[i]);
        ans.push_back(st.size());
    }
    for(auto it:ans)cout<<it<<" ";
    return 0;
}