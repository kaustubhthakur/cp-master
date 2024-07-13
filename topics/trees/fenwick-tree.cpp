#include <bits/stdc++.h>
typedef unsigned long long ull;
const int MAX = 1000001;
ull a[MAX], tree[MAX] = {0}, res;
int N, Q, k, p, q;
char M;
using namespace std;
void update(int p, int q) 
{
    while (p <= N)
    {
        tree[p] += q;
        p += p & (-p);
    }
}
ull getSum(int n) 
{
    ull r = 0;
    while (n > 0)
    {
        r += tree[n];
        n -= n & (-n);
    }
    return r;
}
int main()
{
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    while (Q--)
    {
        cin >> M;
        cin >> p >> q;
        p++;
        // q can be the value(while updating) q can be index p to q sum
        if (M == 'T')
        {
            update(p, -q);
        }
        else if (M == 'G')
        {
            update(p, q);
        }
        else
        {

            q++;
            if (p != 1)
                res = getSum(q) - getSum(p - 1);
            else
                res = getSum(q);
            cout << res << endl;
        }
    }
}