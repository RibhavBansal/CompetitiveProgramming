#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll Q = 10e9 + 7;


struct node /*KRUSKAL*/
{
    ll u;
    ll v;
    ll wt;
    node(ll first, ll second, ll weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp /*KRUSKAL*/ (node a, node b)
{
    return a.wt < b.wt;
}

ll findPar /*KRUSKAL*/ (ll u, vector<ll> &parent)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = findPar(parent[u], parent);
}

void unionn /*KRUSKAL*/ (ll u, ll v, vector<ll> &parent, vector<ll> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskal(ll n, vector<node> edges)
{
    sort(edges.begin(), edges.end(), comp);
    vector<ll> parent;
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
    }
    vector<ll> rank(n, 0);
    ll cost = 0;

    vector<pair<ll, ll>> mst;
    for (auto it : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.v, it.u});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << cost << endl;
    for (auto it : mst)
    {
        cout << it.first << " - " << it.second << endl;
    }
}

int main()
{
    // For example
    int N = 6;
    vector<node> edges;
    edges.push_back(node(0, 1, 5));
    edges.push_back(node(1, 5, -3));
    edges.push_back(node(1, 2, -2));
    edges.push_back(node(2, 4, 3));
    edges.push_back(node(3, 2, 6));
    edges.push_back(node(3, 4, -2));
    edges.push_back(node(5, 3, 1));
    kruskal(6,edges);
    return 0;
}
