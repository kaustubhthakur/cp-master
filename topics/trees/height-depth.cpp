#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
int dep[N], lvl[N];
vector<int> g[N];
void dfs(int x, int pr = 0)
{
    for (auto it : g[x])
    {
        if (it == pr)
        {
            continue;
        }
        dep[it] = dep[x] + 1;
        dfs(it, x);
        lvl[x] = max(lvl[x], lvl[it] + 1);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"depth -> "<<dep[i]<<" height-> "<<lvl[i]<<endl;
    }
    cout<<endl;
    return 0;
}