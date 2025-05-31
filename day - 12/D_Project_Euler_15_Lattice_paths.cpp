#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[501][501];
const int Mod = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;

    cout << dp[n][m] << endl;
}
signed main() {
    for (int i = 0; i <= 500; i++) dp[0][i] = dp[i][0] = 1;
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % Mod;
        }
    }
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}