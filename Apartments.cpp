#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = false;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int a[n];
	int b[m];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);

	int cnt = 0;
	int i = 0;
	int j = 0;

	while (i < n && j < m) {
		if (abs(a[i] - b[j]) <= k) {
			cnt++;
			i++;
			j++;
		} else {
			if (a[i] - b[j] > k) {
				j++;
			} else {
				i++;
			}
		}
	}

	cout << cnt;
}

int32_t main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	clock_t z = clock();

	int t = 1;
	if (LOOP_TEST_CASES) {
		cin >> t;
	}
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;

	return 0;
}