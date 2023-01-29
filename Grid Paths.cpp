#include <bits/stdc++.h>

#define int long long int
#define double long double
#define print(a) for (auto x: a) cout << x << " "; cout << endl

using namespace std;

const bool LOOP_TEST_CASES = false;

string q;
bool visited[7][7] = {false};
int cnt = 0;

bool valid(int i, int j) {
	return i >= 0 && i < 7 && j >= 0 && j < 7;
}

bool hitWall(int r, int c) {
	return (
			((c >= 1 && c <= 5 && !visited[r][c + 1] && !visited[r][c - 1]) &&
			((r == 0 && visited[r + 1][c]) || (r == 6 && visited[r - 1][c]))) 
		||
			((r >= 1 && r <= 5 && !visited[r + 1][c] && !visited[r - 1][c]) &&
				((c == 0 && visited[r][c + 1]) || (c == 6 && visited[r][c - 1]))) 
		
		|| (r >= 1 && r <= 5 && c >= 1 && c <= 5 && visited[r + 1][c] 
			&& visited[r - 1][c] && !visited[r][c + 1] && !visited[r][c - 1])
 
		|| (r >= 1 && r <= 5 && c >= 1 && c <= 5 && visited[r][c + 1] && visited[r][c - 1] 
			&& !visited[r + 1][c] && !visited[r - 1][c]));
}

void dfs(int i, int j, int walk) {
	if (i == 6 && j == 0) {
		if (walk == 48) {
			cnt++;
		}
		return;
	}
	if (hitWall(i, j)) {
		return;
	}

	visited[i][j] = true;

	if (q[walk] == 'R' || q[walk] == '?') {
		if (j < 6 && !visited[i][j + 1]) {
			dfs(i, j + 1, walk + 1);
		}
	}
	if (q[walk] == 'D' || q[walk] == '?') {
		if (i < 6 && !visited[i + 1][j]) {
			dfs(i + 1, j, walk + 1);
		}
	}
	if (q[walk] == 'L' || q[walk] == '?') {
		if (j > 0 && !visited[i][j - 1]) {
			dfs(i, j - 1, walk + 1);
		}
	}
	if (q[walk] == 'U' || q[walk] == '?') {
		if (i > 0 && !visited[i - 1][j]) {
			dfs(i - 1, j, walk + 1);
		}
	}
	
	visited[i][j] = false;
}

void solve() {
	cin >> q;
	dfs(0, 0, 0);
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