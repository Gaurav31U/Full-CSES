#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    multiset<int> ms;
    ms.insert(0);
    ms.insert(n);
    vector<int> temp;
    vector<int> vi;
    for(int i=0;i<k;i++){
        int a;cin>>a;
        vi.push_back(a);
        ms.insert(a);
    }
    reverse(vi.begin(),vi.end());
    int ans=0;
    auto it=ms.begin();
    while(it!=ms.end()){
        int v1=*it;
        it++;
        if(it==ms.end())
            break;
        int v2=*it;
        ans=max(v2-v1,ans);
    }
    temp.push_back(ans);
    for(auto itr:vi){
        auto p=ms.find(itr);
        auto q=p;
        auto rm=p;
        p--,q++;
        ans=max(*q-*p,ans);
        ms.erase(rm);
        temp.push_back(ans);
    }
    temp.pop_back();
    reverse(temp.begin(),temp.end());
    for(auto it:temp)cout<<it<<" ";
    return 0;
}