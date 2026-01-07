#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    vector<int> freq(26,0);
    for(int i=0;i<s.size();i++){
        freq[s[i]-'A']++;
    }
    string ans="";
    for(int i=0;i<s.size();i++){
        bool ansthing = false;
        for(int j=0;j<26;j++){
            if(freq[j]>0 && (ans.empty() || ans.back()!=('A'+j))){
                freq[j]--;
                ans+=('A'+j);
                int remSuffix = s.size()-ans.size();
                bool can_finnish = true;
                for(int k=0;k<26;k++){
                    if(k!=j){
                        if(freq[k]> (remSuffix+1)/2){
                            can_finnish = false;
                            break;
                        }
                    }else{
                        if(freq[k]> remSuffix/2){
                            can_finnish =false;
                            break;
                        }
                    }
                } 
                if(can_finnish){
                    ansthing = true;
                    break;
                }else{
                    freq[j]++;
                    ans.pop_back();
                }
            }
        }
        if(!ansthing){
            break;
        }
    }
    if(ans.size()!=s.size()){
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}