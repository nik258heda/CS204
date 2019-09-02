#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    pair<ll, ll> m;
    m = {-1, -1};
    ll q;
    ll n;
    cin >> n >> q;
    vector<pair<ll, ll>> a;
    int x = 0;
    while (q--)
    {
        cin >> x;
        if (x == 1)
        {
            ll b, c, i;
            cin >> b >> c;
            if (a.empty())
            {
                a.push_back({b, c});
            }
            else
            {
                for (i = 0; i < a.size(); i++)
                {
                    if (b == a[i].first)
                    {
                        a[i].second += c;
                        c=a[i].second;
                        break;
                    }
                }
                if (i == a.size())
                {
                    a.push_back({b,c});
                }
            }
            if (c > m.second)
            {
                m = {b,c};
            }
        }
        if (x == 2)
        {
            if (m.first == -1)
            {
                cout << "Data Not Found";
            }
            else
            {
                cout << m.first << "\n";
            }
        }
    }
}
