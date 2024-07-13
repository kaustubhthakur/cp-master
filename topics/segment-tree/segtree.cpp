#include <bits/stdc++.h>
using namespace std;
struct  segtree
{
    int sx;
    void init(int n)
    {
        sx = 1;
        vector<long long >s;
        while(sx<n) sx*=2;
        s.assign(n:2*sx,u:0LL);


    }
    void set(int i,int v,int x,int lx,int rx)
    {
if(rx-lx==1)
{
    s[x] = v;
    return ;
}
int m = (lx+rx)/2;
if(i<m)
{
    set(i,v,2*x+1,lx,m);
}
else 
{
    set(i,v,2*x+2,m,rx);
}

    }
void set(int i,int v)
{
set(i,v,0,0,sx);
}
    long long sum(int l,int r,int lx,int rx)
    {
if(lx>=r || l>=rx) return 0;
if(lx>=l && rx<=r) return s[x];
    }
    long long sum(int l,int r)
    {
        return sum(l,r,0,0,sx);
    }
};

int main()
{
 int n,m;
 cin>>n>>m;
 segtree seg;
 seg.init(n); 
 for(int i=0;i<n;i++)
 {
    int v;
    cin>>v;
    seg.set(i,v);
 }  
}