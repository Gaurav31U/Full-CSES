#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<pair<int,int>> vi;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        vi.push_back({a,b});
    }
    sort(vi.begin(),vi.end(),[&](pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    });
    int cnt=0;
    int last=-1;
    for(int i=0;i<n;i++){
        if(last<=vi[i].first){
            cnt++;
            last=vi[i].second;
        }
    }
    cout<<cnt;
    return 0;
}