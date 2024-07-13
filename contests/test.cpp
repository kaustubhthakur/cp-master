#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    
    vector<pair<ll, ll>> pr(n);
    for (int i = 0; i < n; i++)
    {
        pr[i] = make_pair(a[i], b[i]);
    }
    map<int,vector<int>>mp;
    sort(pr.begin(), pr.end());
    int ans=0;
  map<int,int>mpp;
 for(int i=0;i<n;i++)
 {
    for(int j=i+1;j<n;j++)
    {
        if(pr[i].first==pr[j].first)
        {
            ans+=min(pr[i].second,pr[j].second);
        }
    }
 }

cout<<ans<<endl;
}
int main()
{
    solve();
}