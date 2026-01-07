#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<array<int,3>> vi;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        vi.push_back({a,-1,i});
        vi.push_back({b,1,i});
    }
    vector<int> ans(n);
    sort(vi.begin(),vi.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;i++)pq.push(i);
    int rm=0;
    for(auto it:vi){
        if(it[1]==-1){
            auto tp=pq.top();
            pq.pop();
            rm=max(rm,tp);
            ans[it[2]]=tp;
        }else{
            pq.push(ans[it[2]]);
        }
    }
    cout<<rm<<"\n";
    for(auto it:ans)cout<<it<<" ";
    return 0;
}