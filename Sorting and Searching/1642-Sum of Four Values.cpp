#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin>>n>>x;
    vector<pair<int,int>> vi;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        vi.push_back({a,i+1});
    }
    sort(vi.begin(),vi.end());
    for(int p=0;p<n-3;p++){
        for(int i=p+1;i<n-2;i++){
            int need=x-vi[i].first-vi[p].first;
            int j=i+1,k=n-1;
            while(j<k){
                if(vi[j].first+vi[k].first>need){
                    k--;
                }else if(vi[j].first+vi[k].first<need){
                    j++;
                }else{
                    cout<<vi[p].second<<" "<<vi[i].second<<" "<<vi[j].second<<" "<<vi[k].second;
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}