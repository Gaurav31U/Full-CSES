#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int ans=1,cnt=1;
    int ch=s[0];
    for(int i=1;i<s.size();i++){
        if(s[i]==ch){
            cnt++;
        }else{
            cnt=1;
            ch=s[i];
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}