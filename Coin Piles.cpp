#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = true;

void solve() {
	int a, b;
	cin >> a >> b;

    if (max(a, b) > 2 * min(a, b)) {
        cout << "NO" << endl;
        return;
    }
 
    if ((a + b) % 3 == 0) {
        cout << "YES" << endl;
    }
    else {
    	cout << "NO" << endl;
    }
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