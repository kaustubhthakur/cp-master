#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;W
    cin >> n;
    vector<pair<int, int>> adj[n];
    int edges;
    cin >> edges;
    while (edges--)
    {
        int x, y, weight;
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(y, weight));
        adj[y].push_back(make_pair(x, weight));
    }
    int INF = 1000000;
    int s = 0;
    vector<int> d(n, INF);
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (auto edge : adj[v])
        {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u])
            {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << d[i] << " " << endl;
    return 0;
}
