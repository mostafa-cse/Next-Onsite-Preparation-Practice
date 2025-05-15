#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        ans += a * c;
    }
    cout << ans << endl;
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