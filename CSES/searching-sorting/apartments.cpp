#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5;

/*
 * Variables used for the current problem
 * n: number of applicants
 * m: number of apartments
 * k: max diff between desired and actual size
 * a and b: arrays for applicants and apartments respectively
 */
int n, m, k, a[MAX_N], b[MAX_N], ans;

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int i = 0, j = 0;
	while (i < n && j < m) {

		if (abs(a[i] - b[j]) <= k) {
			++i;
			++j;
			++ans;
		} else {
			
			if (a[i] - b[j] > k) {
				++j;
			}
			
			else {
				++i;
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}