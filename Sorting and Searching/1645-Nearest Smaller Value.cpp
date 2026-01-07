#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> vi(n);
    for(int i=0;i<n;i++)cin>>vi[i];
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(st.empty()){
            ans.push_back(0);
        }else{
            while(!st.empty() && vi[st.top()-1]>=vi[i]){
                st.pop();
            }
            if(st.empty())ans.push_back(0);
            else ans.push_back(st.top());
        }
        st.push(i+1);
    }
    for(auto it:ans)cout<<it<<" ";
    return 0;
}