#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++){
	    cin>>pre[i];
	    pre[i]+=pre[i-1];
    }
    multiset<int> ms;
    for(int i=a;i<=b;i++){
	    ms.insert(pre[i]);
    }
    int ans=*ms.rbegin();
    for(int i=1;i+a<=n;i++){
	    ms.erase(pre[i+a-1]);
	    ms.insert(pre[min(i+b,n)]);
	    ans=max(ans,*ms.rbegin()-pre[i]);
    }
    cout<<ans;
    return 0;
}