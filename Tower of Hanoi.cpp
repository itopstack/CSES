#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = false;

void towerOfHanoi(int n, string from_rod, string to_rod, string aux_rod, vector<string>& v) {
    if (n == 0) {
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, v);
    v.push_back(from_rod + " " + to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, v);
}

void solve() {
	int n;
	cin >> n;
	vector<string> v;

	towerOfHanoi(n, "1", "3", "2", v);
	cout << v.size() << endl;
	for (auto& s: v) {
		cout << s << endl;
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