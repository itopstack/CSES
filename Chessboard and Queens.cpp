#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = false;

bool board[9][9];
bool row[9];
bool downright[15];
bool upright[15];
int ans = 0;

void backtrack(int x) {
	if (x == 9) {
		ans++;
		return;
	}
	
	for (int i = 1; i <= 8; i++) {
		if (!board[i][x] && !row[i]) {
			if (!downright[x - i + 7] && !upright[x + i - 2]) {
				row[i] = downright[x - i + 7] = upright[x + i - 2] = 1;
				backtrack(x + 1);
				row[i] = downright[x - i + 7] = upright[x + i - 2] = 0;
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= 8; i++) {
		row[i] = 0;
		for (int j = 1; j <= 8; j++) {
			char x;
			cin >> x;
			if (x == '*') {
				board[i][j] = 1;
			} else {
				board[i][j] = 0;
			}
		}
	}

	backtrack(1);
 
	cout << ans << endl;
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