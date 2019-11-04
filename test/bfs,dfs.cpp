#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
const ll N=1e6+5;
vector<vector<ll>> adj(N);  

queue<ll> q;
vector<bool> used(N);
vector<ll> d(N), p(N);

void bfs(ll s){
	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
    	ll v = q.front();
    	cout<<v<<" ";
    	q.pop();
    	for (ll u : adj[v]) {
        	if (!used[u]) {
            	used[u] = true;
            	q.push(u);
            	d[u] = d[v] + 1;
            	p[u] = v;
        	}
    	}
	}
	fill(used.begin(),used.end(),false);
  //This is so it clears previous history, it will not be their for particular questions.
}

void dfs(ll v) {
    used[v] = true;
    cout<<v<<" ";
    for(ll u : adj[v]){
        if(!used[u])
           dfs(u);
    }
}

int main(){
	int n;
  cin>>n;
  //Input Here
  bfs(x);
  dfs(y);
	return 0;
}
