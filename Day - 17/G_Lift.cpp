#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int u, v;
    cin >> u >> v;
    cout << abs(u - v) * 4 + 3 + 5 + 3 + (u * 4) + 3 + 5 << endl;
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