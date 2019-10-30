#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=4e6+10;
vector<ll> adj[N];
vector<ll> color(N,-1);
bool c=true;
void dfs(ll x,ll a){
    if(!c) return;
    else if(color[x]!=-1){
        if(a^color[x]==0){
            return;
        }
        else{
            c=false;
            return;
        }
    }
    else{
        color[x]=a;
        for(auto i:adj[x]){
            dfs(i,a^1);
        }
        return;
    }
}
int main(){
    ll m,n,w;
    cin>>n>>m;
    ll k=n;
    for(ll i=0;i<m;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        if(w%2!=0){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        else{
            adj[x].push_back(k);
            adj[k].push_back(x);
            adj[y].push_back(k);
            adj[k].push_back(y);
            k++;    
        }
    }
    for(ll i=0;i<n;i++){
        if(!c) break;
        else if(color[i]!=-1) continue;
        else dfs(i,1);
    }
    if(!c) cout<<"YES";
    else cout<<"NO"; 
    return 0;
}