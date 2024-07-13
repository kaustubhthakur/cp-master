#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
   cout<<binpow(n,m)<<endl;
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