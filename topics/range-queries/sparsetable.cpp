#include <bits/stdc++.h>
using namespace std;
const int MAXI = 1e5 + 5;
const int LOG = 17;
int a[MAXI];
int m[MAXI][LOG];
int logg[MAXI];
int query(int l, int r)
{
    int len = r - l + 1;
    int k = logg[len];
    return min(m[l][k], m[r - (1 << k) + 1][k]);
}
int main()
{
    int n;
    cin >> n;
    logg[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        logg[i] = logg[i / 2] + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
    }
    for (int i = 1; i < LOG; i++)
    {
        for (int j = 0; j + (1 << i) - 1 < n; j++)
        {
            m[j][i] = min(m[j][i - 1], m[j + (1 << (i - 1))][i - 1]);
        }
    }
    long long q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        long long l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}