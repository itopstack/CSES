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
    sort(a, a + n);

    int cnt = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        cnt++;
        if (a[i] + a[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
    }

    cout << cnt;
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