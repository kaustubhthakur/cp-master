#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];

void dijkstra(int src)
{
    vector<int> dist(N, INF);
    vector<int> vis(N, 0);
    // priority_queue<int>pq;
    set<pair<int, int>> s;
    s.insert({0, src});
    dist[src] = 0;
    while (s.size() > 0)
    {
        auto it = *s.begin();
        int v = it.second;
        int di = it.first;
        s.erase(s.begin());
        if (vis[v] == 1)
            continue;
        vis[v] = 1;
        for (auto i : g[v])
        {
            int ch = i.first, ww = i.second;
            if (dist[v] + ww < dist[ch])
            {
                dist[ch] = dist[v] + ww;
                s.insert({dist[ch], ch});
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
}