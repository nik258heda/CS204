#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
#define mod 1e9 + 7
using namespace std;
const int N = 1023;
const int INF = mod;
vector<vector<int>> hash_list(N, vector<int>(1, INF));
int hash_func(int val)
{
    return val % N;
}
void insert(int key)
{
    int hk = hash_func(key);
    if (hash_list[hk].size() == 1 && hash_list[hk][0] == INF)
    {
        hash_list[hk][0] = key;
    }
    else
    {
        hash_list[hk].push_back(key);
    }
}
bool search(int key)
{
    int hk = hash_func(key);
    if (hash_list[hk].size() == 1 && hash_list[hk][0] == INF)
        return false;

    for (int i = 0; i < hash_list[hk].size(); i++)
    {

        if (hash_list[hk][i] == key)
        {

            return true;
        }
    }
    return false;
}
bool delete_key(int key)
{
    if (!search(key))
        return false;
    int hk = hash_func(key);

    int i = 0;
    for (; i < hash_list[hk].size(); i++)
    {
        if (hash_list[hk][i] == key)
            break;
    }
    if (i == hash_list[hk].size())
        return false;
    hash_list[hk].erase(hash_list[hk].begin() + i);
    return true;
}

int main()
{
    insert(9214);
    insert(9041274);
    insert(4000);
    insert(1000);
    delete_key(1000);
    cout << search(4000);

    return 0;
}
