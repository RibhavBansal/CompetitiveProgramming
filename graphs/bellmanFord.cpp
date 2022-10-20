#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll Q = 10e9 + 7;

void bellmanFord /*Shortest Distance with Negative Edge*/ (ll src, ll v, vector<node> &edges)
{
    /*RELAX ALL THE EDGES N-1 TIMES*/
    vector<ll> dist(v, 10000000);
    dist[src] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    /*RELAX ONE MORE TIME FOR CHECKING NEGATIVE CYCLE OR NOT*/
    ll flag = 0;
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << -1;
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        for (int i = 0; i < v; i++)
        {
            cout << dist[i] << " ";
        }
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
    bellmanFord(0,6,edges);
    return 0;
}
