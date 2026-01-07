#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    vector<string> ans;
    sort(s.begin(),s.end());
    ans.push_back(s);
    while(next_permutation(s.begin(),s.end())){
        ans.push_back(s);
    }
    cout<<ans.size()<<"\n";
    for(auto it:ans){
        cout<<it<<"\n";
    }
    return 0;
}