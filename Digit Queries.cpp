#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = true;

void solve() {
	int k;
	cin >> k;
	int length = 1;
	int first = 1;

	while (k > 9 * first * length) {
		k -= 9 * first * length;
		length++;
		first *= 10;
	}

	int group = (k - 1) / length;
	int remainder = (k - 1) % length;
	cout << to_string(first + group)[remainder] << endl;
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