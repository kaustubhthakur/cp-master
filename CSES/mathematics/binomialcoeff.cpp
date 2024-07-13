#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long fact(int x)
{
    if(x<=1) return 1;
    return x*fact(x-1);
}
int main()
{
int t;
cin>>t;
while(t--)
{
long long x,y;
cin>>x>>y;
long long dx = fact(x);
long long dy = fact(abs(x-y));
cout<<dx/(fact(y)*dy)%mod<<endl;
}
}