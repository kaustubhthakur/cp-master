#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 1e9+10;
int dist[N][N];
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        dist[x][y]=w;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                dist[j][k]=min(dist[j][k],dist[j][i]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]==INF)
            {
    cout<<"0";
            }
            else 
            {
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}