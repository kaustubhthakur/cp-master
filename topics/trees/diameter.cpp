#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
int dep[N], lvl[N];
vector<int> g[N];
int dia[N];
void dfs(int x, int pr = -1)
{
    for (auto it : g[x])
    {
        if (it == pr)
        {
            continue;
        }
        dep[it] = dep[x] + 1;
        dfs(it, x);
      
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
    int mx=-1;
    int mxd;
    for(int i=1;i<=n;i++)
    {
        if(mx<dep[i])
        {
            mx = dep[i];
            mxd=i;
        }
        dep[i]=0;
    }
    dfs(mxd);
    mx = -1;

    for(int i=1;i<=n;i++)
    {
        if(mx<dep[i])
        {
            mx= dep[i];
         
        }
     
    }
    cout<<mx<<endl;
    return 0;
}