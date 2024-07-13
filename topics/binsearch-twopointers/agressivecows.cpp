#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int INF = 1e9+7;
int n,c;
int x[N];
bool check(int d)
{
    int ls = -INF;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(x[i]-ls>=d)
        {
            cnt++;
            ls = x[i];
        }
    }
    if(cnt>=c)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void solve()
{
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];

    }
    sort(x,x+n);
for(int i=1;i<INF;i++)
{
    if(check(i)==false)
    {
        cout<<i-1;
        return ;
    }
}
}
int main()
{


solve();
    return 0;
}