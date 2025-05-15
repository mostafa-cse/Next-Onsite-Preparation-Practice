#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<bool> p(100005, true);
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> cnt;
    for (char c : s) {
        cnt[c]++;
    }

    vector<pair<char, int>> ans;
    for (auto [x, y] : cnt) {
        if (p[y]) {
            ans.emplace_back(x, y);
        }
    }

    if (ans.empty()) {
        cout << "Love is painful !\n";
    } else {
        for (auto [x, y] : ans) {
            cout << x << " = " << y << endl;
        }
    }
}
signed main() {
    int tc;
    cin >> tc;
    p[1] = false;
    for (int i = 2; i <= 100000; i++) {
        if (p[i]) {
            for (int j = i * i; j <= 100000; j += i) {
                p[j] = false;
            }
        }
    }
    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": \n";
        solve();
    }
    return 0;
}