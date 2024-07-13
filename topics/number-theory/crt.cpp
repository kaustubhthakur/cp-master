#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int sz = 1e6+1;
int pw(ll x,ll y,ll p)
{
    ll res =1;
    x%=p;
    if(x==0) return 0;
    while(y>0)
    {
        if(y&1)
        {
            res=(res*x)%p;
        }
        y=y>>1;
        x=(x*x)%p;
    }
    return res;
}
ll crt(vector<ll>a,vector<ll>rem)
{
    vector<ll>prod;
    prod.clear();
    ll p = 1LL;
    for(int i=0;i<a.size();i++)
    {
        p*=a[i];
    }
    for(int i=0;i<a.size();i++)
    {
        prod.push_back(p/a[i]);
    }

vector<ll>inv;
inv.clear();
for(int i=0;i<prod.size();i++)
{
    inv.push_back(pw(prod[i],a[i]-2,a[i]));
}
ll ans=0LL;
for(int i=0;i<prod.size();i++)
{
    ans = ans%p+(((rem[i]*prod[i])%p)*(inv[i])%p)%p;
    ans%=p;
}
return ans;
}
void solve()
{
    vector<ll>a={2,3,7};
    vector<ll>rem={1,2,5};
    cout<<crt(a,rem)<<endl;
}
int main()
{
    solve();
}