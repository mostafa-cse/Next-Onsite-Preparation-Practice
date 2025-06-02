#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;

    int cnt = 0, bit = 0;
    for (int i = 0; i < 30; i++) {
        if ((n >> i & 1) and !(n >> (i + 1) & 1)) {
            n ^= (1 << i);
            n ^= (1 << (i + 1));
            bit = i;
            break;
        }
        cnt += (n >> i & 1);
    }
    n &= ~((1 << bit) - 1);
    n |= ((1 << cnt) - 1);
    cout << n << endl;
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