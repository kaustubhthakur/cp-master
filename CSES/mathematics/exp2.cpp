#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;


ll exp(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) {  
			res = res * x % m;
		}
		x = x * x % m;
		n /= 2; 
	}
	return res;
}


int main() {
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		ll a, b, c;
		cin >> a >> b >> c;

		ll pow_bc = exp(b, c, MOD - 1);
		ll ans = exp(a, pow_bc, MOD);

		cout << ans << '\n';
	}
    return 0;
}