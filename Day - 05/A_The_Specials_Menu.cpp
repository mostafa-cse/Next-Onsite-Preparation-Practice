#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    string s;
    cin >> s;

    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
    function<int(int, int)> rec = [&] (int i, int j) -> int {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        // Now skip i, count palindrome (i + 1), j
        // Now skip j, count palindrome i, (j - 1)
        // Skip both i, j, means i + 1, j - 1
        if (s[i] == s[j]) {
            ans += 1 + rec(i + 1, j) + rec(i, j - 1);
        } else {
            ans += rec(i + 1, j) + rec(i, j - 1) - rec(i + 1, j - 1);
        }
        return dp[i][j] = ans;
    };

    cout << rec(0, s.size() - 1) << endl;
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}