#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            set<int> st;
            for(int p=0;p<i;p++)st.insert(grid[p][j]);
            for(int p=0;p<j;p++)st.insert(grid[i][p]);
            int x=0;
            while(st.count(x))x++;
            grid[i][j]=x;
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;
}