#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, q;
    cin >> n >> q;

    unordered_map<int, vector<int>> idx;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        idx[x].push_back(i);
    }

    while (q--) {
        int l, r, val;
        cin >> l >> r >> val;

        if (idx[val].empty()) {
            cout << "NO" << endl;
            continue;
        }
        auto pos = lower_bound(idx[val].begin(), idx[val].end(), l);
        if (pos == idx[val].end()) {
            cout << "NO" << endl;
            continue;
        }

        if (*pos <= r) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}