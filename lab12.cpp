#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007;
using namespace std;
vector<ll> parent;
vector<ll> siz;
void make_set(ll v) {
    parent[v] = v;
    siz[v] = 0;
}
ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        if (siz[a] == siz[b])
            siz[a]++;
    }
}

struct Edge {
    ll u, v, weight;
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
};
vector<Edge> edges;
int main(){ 
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        Edge temp;
        ll x,y,w;
        cin>>x>>y>>w;
        temp.u=x;temp.v=y;temp.weight=w;
        edges.push_back(temp);
    }
    vector<Edge> result;
    parent.resize(n);
    siz.resize(n);
    for (ll i = 0; i < n; i++)
        make_set(i);
    ll cost=1;
    sort(edges.begin(), edges.end());

     for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
           cost=(cost*e.weight)%mod;
           result.push_back(e);
           union_sets(e.u, e.v);
        }
    }
    cout<<cost;
    return 0;
}