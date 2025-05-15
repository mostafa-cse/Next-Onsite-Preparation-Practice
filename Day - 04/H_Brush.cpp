#include <bits/stdc++.h>
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
void solve() {
    int n, w;
    cin >> n >> w;

    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cin >> y[i];
    }
    sort(y.begin(), y.end());
    y.resize(unique(y.begin(), y.end()) - y.begin());

    vector<int> dp(n + 1, -1);
    function<int(int)> rec = [&] (int idx) -> int {
        if (idx >= y.size()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int ans = 1e18;
        int pos = upper_bound(y.begin(), y.end(), y[idx] + w) - y.begin();
        ans = min(ans, 1 + rec(pos));

        int pos1 = upper_bound(y.begin(), y.end(), y[idx] + (w >> 1)) - y.begin();
        ans = min(ans, 1 + rec(pos1));
        
        if (w & 1) {
            int pos2 = upper_bound(y.begin(), y.end(), y[idx] + (w + 1) / 2) - y.begin();
            ans = min(ans, 1 + rec(pos2));
        }
        return dp[idx] = ans;
    };
    cout << rec(0) << endl;
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