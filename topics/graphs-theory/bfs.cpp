#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>g[N];
int vis[N],lvl[N];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int dx = q.front();
        q.pop();
        cout<<dx<<" ";
        for(auto it:g[dx])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
                lvl[it] = lvl[dx]+1;
            }
        }
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<lvl[i]<<" ";
    }
    cout<<endl;
}