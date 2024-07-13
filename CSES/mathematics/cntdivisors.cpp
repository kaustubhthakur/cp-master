#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int countDivisors(int n) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            
            if (n / i == i) 
                cnt++; 
  
            else 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        
      cout<<countDivisors(n)<<endl;
    }
}