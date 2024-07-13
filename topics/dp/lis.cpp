#include <bits/stdc++.h>
using namespace std;
const int N = 25e2 + 10;
vector<int> a(N);
int dp[N];
int lis(int id)
{
    if (dp[id] != -1)
        return dp[id];
    int ans = 1;
    for (int i = 0; i < id; i++)
    {
        if (a[id] > a[i])
        {
            ans = max(ans, lis(i) + 1);
        }
    }
    return dp[id] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lis(i));
    }
    cout << ans << endl;
}