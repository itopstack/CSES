#include <bits/stdc++.h>
#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl
using namespace std;
const bool LOOP_TEST_CASES = false;

void solve() {
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	unordered_map<int, int> m;
	for (int i = 0; i < n; i ++) {
		int c = x - a[i];
		if (m.count(c)) {
			cout << i + 1 << " " << m[c] + 1 << endl;
			return;
		}
		m.insert({a[i], i});
	}
	
	cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

    int t = 1;
    if (LOOP_TEST_CASES) {
        cin >> t;
    }
    while (t--) solve();

    return 0;
}