#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];

void dijkstra(int src)
{
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    set<pair<int, int>> s;
    s.insert({0, src});
    dist[src] = 0;
    while (s.size() > 0)
    {
        auto it = *s.begin();
        int d = it.second;
        int dx = it.first;
        if (vis[d])
            continue;
        vis[d] = 1;
        for (auto i : g[d])
        {
            int dd = i.first;

            int w = i.second;
            if (dist[d] + w < dist[dd])
            {
                dist[dd] = dist[d] + w;
                s.insert({dist[dd], dd});
            }
        }
    }
}
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }

    return 0;
}