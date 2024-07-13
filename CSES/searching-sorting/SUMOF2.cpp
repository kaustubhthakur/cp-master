#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
   map<int,int>mp;
   for(int i=0;i<n;i++)
   {
    
    if(mp.count(m-a[i]))
    {
        cout<<i+1<<" "<<mp[m-a[i]]<<endl;
        return 0;
    }
    mp[a[i]] = i+1;
   }
        cout<<"IMPOSSIBLE"<<endl;
    
}