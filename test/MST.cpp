#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};
vector<Edge> edges;
int main()
{
    int n;
    cin>>n;
    //Input for nodes would be here;
    int cost = 0;
    vector<int> tree_id(n);
    vector<Edge> result;
    for (int i = 0; i < n; i++)
        tree_id[i] = i;

    sort(edges.begin(), edges.end());

    for (Edge e : edges)
    {
        if (tree_id[e.u] != tree_id[e.v])
        {
            cost += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++)
            {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }
}