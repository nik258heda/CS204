#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int orient(pair<ll, ll> p, pair<ll, ll> q, pair<ll, ll> r)
{
    int v = p.first * (q.second - r.second) + q.first * (r.second - p.second) + q.first * (p.second - q.second);
    if (v < 0)
        return -1;
    if (v > 0)
        return 1;
    if (v = 0)
        return 0;
}
void convex_hull(vector<pair<ll, ll>> v)
{
    if (v.size() == 1 || v.size() == 2 || v.size() == 3)
        return;
    sort(v.begin(), v.end());
    pair<ll, ll> p1 = v[0], p2 = v.back();
    vector<pair<ll, ll>> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 0; i < v.size(); i++)
    {
        if (i == v.size() - 1 || orient(p1, v[i], p2) < 0)
        {
            while (up.size() > 1 && orient(up[up.size() - 2], up[up.size() - 1], v[i]) = 0)
                up.pop_back();
            up.push_back(v[i]);
        }
        if (i == v.size() - 1 || orient(p1, v[i], p2) > 0)
        {
            while (down.size() > 1 && orient(down[down.size() - 2], down[down.size() - 1], v[i]) = 0)
                down.pop_back();
            down.push_back(v[i]);
        }
    }
    v.clear();
    for (int i = 0; i < up.size(); i++)
        v.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        v.push_back(down[i]);
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> v(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            v[i].first = x;
            v[i].second = y;
        }
        convex_hull(v);
    }
    return 0;
}