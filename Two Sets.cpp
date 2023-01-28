#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = false;

void solve() {
	int n;
	cin >> n;

	int sum = n * (n + 1) / 2;
	if (sum % 2 != 0) {
		cout << "NO";
	} else {
		int target = sum / 2;
		int t = n;

		unordered_set<int> s1;
		unordered_set<int> s2;

		for (int i = 1; i <= n; i++) {
			s1.insert(i);
		}
		while (s1.count(target) == 0) {
			s1.erase(t);
			s2.insert(t);
			target -= t;
			t--;
		}
		s1.erase(target);
		s2.insert(target);

		cout << "YES" << endl;
		cout << s1.size() << endl;
		print(s1);
		cout << s2.size() << endl;
		print(s2);
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