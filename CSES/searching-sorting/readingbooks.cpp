#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long>a(n);
    long long mx =INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    long long s = accumulate(a.begin(),a.end(),0LL);
    long long dx = s-mx;
    if(dx>mx)
    {
        cout<<dx+mx<<endl;
    }
    else 
    {
        cout<<mx*2<<endl;
    }
}