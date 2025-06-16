#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int r = 3,l = 0; r <= n; ++r) {
        while (a[r] - a[l + 1] > k * 2) l++;
        while (l < r - 2 and dp[l] == 1e18) l++;
        if (l < r - 2) {
            dp[r] = min(dp[r], dp[l] + 1);
        }
    }
    cout << (dp[n] == 1e18 ? -1 : dp[n]) << endl;
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