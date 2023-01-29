#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = false;

int n, m, h, t; 
multiset<int> tickets;

void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> h; 
        tickets.insert(h);
	}
	for (int i = 0; i < m; i++) {
		cin >> t;
		auto it = tickets.upper_bound(t);

		if (it == tickets.begin()) {
			cout << -1 << endl;
		}
		else {
			cout << *(--it) << endl;
			tickets.erase(it);
		}
	}
}

int32_t main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    if (LOOP_TEST_CASES) {
        cin >> t;
    }
    while (t--) solve();

    return 0;
}