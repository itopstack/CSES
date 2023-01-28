#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = false;

bool cmp(pair<char, int>& p1, pair<char, int>& p2) {
	if (p1.second % 2 == 0 && p2.second % 2 == 0) {
		return p1.first < p2.first;
	}
	if (p1.second % 2 == 0) {
		return true;
	}
	return false;
}

void solve() {
	string s;
	cin >> s;
	unordered_map<char, int> m;
	vector<pair<char, int>> v;
	string ans = "";

	for (char c: s) {
		m[c] += 1;
		ans += "#";
	}

	int cntOdd = 0;
	for (auto& p: m) {
		if (p.second % 2 == 1) {
			cntOdd++;
			if (cntOdd > 1) {
				cout << "NO SOLUTION";
				return;
			}
		}
		v.push_back(p);
	}

	sort(v.begin(), v.end(), cmp);

	int i = 0;
	int j = ans.size() - 1;

	for (auto& p: v) {
		while (p.second > 0) {
			ans[i++] = p.first;
			p.second--;

			if (i < j) {
				ans[j--] = p.first;
				p.second--;
			}
		}
	}

	cout << ans;
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