#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    string s;
    cin >> s;

    vector<vector<int>> pali(s.size(), vector<int>(s.size(), -1));
    function<int(int, int)> rec = [&](int l, int r) -> int {
        if (l > r) {
            return 1;
        } else if (s[l] != s[r]) {
            return 0;
        } else if (pali[l][r] != -1) {
            return pali[l][r];
        }
        return pali[l][r] = rec(l + 1, r - 1);
    };
    for (int l = 0; l < s.size(); l++) {
        for (int r = l; r < s.size(); r++) {
            pali[l][r] = rec(l, r);
        }
    }

    vector<int> dp(s.size(), -1);
    function<int(int)> call = [&](int l) -> int {
        if (l >= s.size()) {
            return 0;
        }
        if (dp[l] != -1) {
            return dp[l];
        }
        int ans = s.size();
        for (int r = l; r < s.size(); r++) {
            if (pali[l][r]) {
                ans = min(ans, 1 + call(r + 1));
            }
        }
        return dp[l] = ans;
    };
    cout << call(0) << endl;
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