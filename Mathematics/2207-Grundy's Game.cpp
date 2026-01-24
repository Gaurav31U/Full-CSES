#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=101;
int n,m;
set<int> losing;
struct Game{
    map<int,int> grundy;
    int mex(set<int> x){
        int ans=0;
        for(auto v:x)
            if(v==ans)ans++;
        return ans;
    }
    vector<int> f(int x){
        vector<int> temp;
        for(int i=1;i<=(x-1)/2;i++){
            temp.emplace_back(grundy[i]^grundy[x-i]);
        }
        return temp;
    }
    void init(int nn){
        for(int i=0;i<=nn;i++){
            vector<int> temp=f(i);
            set<int> x;
            for(auto it:temp)
                x.insert(it);
            grundy[i]=mex(x);
        }
        for(int i=0;i<=nn;i++)
            if(grundy[i]==0)
                losing.insert(i);
    }
};
signed main(){
    cin>>n;
    Game temp;
    temp.init(1500);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(losing.find(a)!=losing.end())
            cout<<"second\n";
        else cout<<"first\n";
    }
    return 0;
}