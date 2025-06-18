#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, r, p, q;
    cin >> n >> r >> p >> q;
    
    assert(n >= r);
    
    function<int(int, int)> cnt = [&](int x, int p) -> int {
        int ans = 0;
        while (x) {
            ans += x / p;
            x /= p;
        }
        return ans;
    };
    function<int(int, int)> factor = [&](int x, int p) -> int {
        int ans = 0;
        while (x % p == 0) {
            ans += 1;
            x /= p;
        }
        return ans;
    };
    
    int cnt2 = cnt(n, 2) - cnt(r, 2) - cnt(n - r, 2) + q * factor(p, 2);
    int cnt5 = cnt(n, 5) - cnt(r, 5) - cnt(n - r, 5) + q * factor(p, 5);
    // cout << cnt2 << " " << cnt5 << endl;
    cout << min(cnt2, cnt5) << endl;
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