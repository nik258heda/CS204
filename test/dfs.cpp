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
    ll m,n;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(ll i=0;i<n;i++){
        if(!c) break;
        else if(color[i]!=-1) continue;
        else dfs(i,1);
    }
    if(!c) cout<<"NOT";
    else cout<<"YES"; 
    return 0;
}
