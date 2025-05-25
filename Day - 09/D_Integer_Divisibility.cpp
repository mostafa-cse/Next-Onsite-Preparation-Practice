#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int mod, d;
    cin >> mod >> d;

    int ans = 0, val = 0;
    while (true) {
        val = (val * 10 + d) % mod;
        ans++;
        if (val == 0) {
            break;
        }
    }
    cout << ans << endl;
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