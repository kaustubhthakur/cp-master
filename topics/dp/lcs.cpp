#include <bits/stdc++.h>
using namespace std;
const int N = 25e2 + 10;
vector<int> a(N);
int dp[3000][3000];
int choice[3000][3000];
int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    dp[0][0] = 0;
    if (s[0] == t[0])
    {
        dp[0][0] = 1;
        choice[0][0]=2;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                dp[i][j] = dp[i - 1][j];
                choice[i][j]=0;
            }
            if (j > 0)
            {
                if (dp[i][j - 1] > dp[i][j])
                {
                    dp[i][j] = dp[i][j - 1];
                    choice[i][j]=1;
                }
            }
            if (s[i] == t[j])
            {
                int ans = 1;
                if (i > 0 && j > 0)
                {
                    ans = i + dp[i - 1][j - 1];
                    choice[i][j] =2;
                }
                if (ans > dp[i][j])
                {
                    dp[i][j] = ans;
                }
            }
        }
        int i = n-1,ij=m-1;
        string str;
        while(i>=0 && j>=0)
        {
            if(choice[i][j]==0)
            {
                i--;
            }
            else if(choice[i][j]==1)
            {
                j--;
            }
            else 
            {
                str.push_back(s[i]);
                i--,j--;
            }
        }
        reverse(str.begin(),str.end());
        cout<<str<<endl;
         cout << dp[n - 1][m - 1] << endl;
    }
    return 0;
}