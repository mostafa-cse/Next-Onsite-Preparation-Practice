#include <bits/stdc++.h>
using namespace std;
#define int long long

int getdigit(char c) {
    if ('0' <= c && c <= '9') {
        return (c - '0');
    }
    return (c - 'A') + 10;
}

int dp[(1 << 17)][21];
void solve() {
    int base, k;
    cin >> base >> k;

    string str;
    cin >> str;

    int n = str.size();
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int idx = 0; idx < n; idx++) {
            if (mask & (1 << idx))
                continue;
            for (int rem = 0; rem < k; rem++) {
                int dig = getdigit(str[idx]);
                dp[mask | (1 << idx)][(rem * base + dig) % k] += dp[mask][rem];
            }
        }
    }
    cout << dp[(1 << n) - 1][0] << endl;
    return;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i < t + 1; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}