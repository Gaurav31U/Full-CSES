#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    map<int,int> mp;
    for(auto it:s){
        mp[it]++;
    }
    int cnt=0;
    string p="";
    for(auto it:mp){
        if(it.second&1){
            cnt++;
            for(int i=0;i<it.second;i++)p+=it.first;
        }
    }
    if(cnt>1){
        cout<<"NO SOLUTION";
        return 0;
    }
    string ans="";
    for(auto it:mp){
        if(it.second&1)continue;
        for(int i=0;i<it.second/2;i++){
            ans+=it.first;
        }
    }
    string temp=ans;
    reverse(temp.begin(),temp.end());
    ans+=p;
    ans+=temp;
    cout<<ans;
    return 0;
}