#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = false;

void solve() {
	int n;
	cin >> n;

	vector<string> v;
	v.push_back("0");
	v.push_back("1");

	for (int i = 1; i < n; i++) {
		vector<string> first;
		for (string& s: v) {
			first.push_back("0" + s);
		}

		vector<string> second;
		for (int i = v.size() - 1; i >= 0; i--) {
			second.push_back("1" + v[i]);
		}

		v.clear();
		for (string& s: first) {
			v.push_back(s);
		}
		for (string& s: second) {
			v.push_back(s);
		}
	}

	print(v);
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