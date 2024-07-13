#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int wt[105], val[105];
int dp[105][100005];
int knapsack(int id, int w)
{
    if(w==0 || id<0) return 0;
    if(dp[id][w]!=-1) return dp[id][w];
    int ans = knapsack(id - 1, w);

    if (w - wt[id] >= 0)
    {
        ans = max(ans, knapsack(id - 1, w - wt[id]) + val[id]);
    }
    return dp[id][w]=ans;
}
int main()
{
    int n, w;
    cin >> n >> w;
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    cout << knapsack(n - 1, w) << endl;
}