#include <bits/stdc++.h>
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
void solve() {
    int n;
    cin >> n;


    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    function<int(int, int)> rec = [&](int r, int c) -> int{
        if (r >= n or c >= n) {
            return 0;
        }
        if (dp[r][c] != -1) return dp[r][c];
        int ans = 0;
        ans = max(ans, a[r][c] + rec(r + 1, c));
        ans = max(ans, a[r][c] + rec(r + 1, c + 1));
        return dp[r][c] = ans;
    };
    cout << rec(0, 0) << endl;
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}