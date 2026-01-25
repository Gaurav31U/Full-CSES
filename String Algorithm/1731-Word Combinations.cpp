#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5001;
const int INF=1e12;
const int MOD=1e9+7;
int n,m,k;
int dp[N];
class node{
    public:
    int end;
    node* next[26];
    node(){
        end=0;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
};
class Trie{
    public:
    node* trie;
    Trie(){
        trie=new node;
    }
    void insert(string s){
        node* temp=trie;
        for(int i=0;i<s.size();i++){
            if(temp->next[s[i]-'a']==NULL){
                temp->next[s[i]-'a']=new node;
            }    
            temp=temp->next[s[i]-'a'];
        }
        temp->end=1;
    }
};
signed main(){
     Trie trie;
     string s;cin>>s;
     cin>>n;
     for(int i=0;i<n;i++){
         string a;cin>>a;
         trie.insert(a);
     }
     m=s.size();
     dp[m]=1;
     for(int i=m-1;i>=0;i--){
             node* temp=trie.trie;
             for(int j=i;j<m;j++){
                 int c=s[j]-'a';
                 if(temp->next[c]==NULL)break;
                 temp=temp->next[c];
                 if(temp->end)
                     dp[i]=(dp[i]+dp[j+1])%MOD;
             }
     }
     cout<<dp[0];
    return 0;
}