#include <bits/stdc++.h>
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());

    while (q--) {
        int l, r;
        cin >> l >> r;

        int posl = lower_bound(a.begin(), a.end(), l) - a.begin();
        int posr = upper_bound(a.begin(), a.end(), r) - a.begin();
        cout << posr - posl << endl;
    }
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}