#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;

    cout << __gcd(abs(x - xx), abs(y - yy)) + 1 << endl;
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