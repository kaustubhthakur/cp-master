#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX_N = 100000;
const int INF = 1000000000;
class FenwickTree
{
public:
    FenwickTree(int n) : n(n), bit(n, 0) {}

    FenwickTree(const vector<int> &a)
    {
        n = a.size();
        bit.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            add(i, a[i]);
        }
    }

    int sum(int r)
    {
        int ret = 0;
        while (r >= 0)
        {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }

    int range_sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        while (idx < n)
        {
            bit[idx] += delta;
            idx = idx | (idx + 1);
        }
    }

private:
    int n;
    vector<int> bit;
};
int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int mex(const vector<int> &A)
{
    set<int> b(A.begin(), A.end());
    int result = 0;
    while (b.count(result))
    {
        result++;
    }
    return result;
}

tuple<int, int, int> exgcd(int a, int b)
{
    if (b == 0)
    {
        return make_tuple(a, 1, 0);
    }
    int d, x1, y1;
    tie(d, x1, y1) = exgcd(b, a % b);
    int x = y1;
    int y = x1 - y1 * (a / b);
    return make_tuple(d, x, y);
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
   


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}