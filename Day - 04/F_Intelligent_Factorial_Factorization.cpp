#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> primes;
void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> ans;
    for (int i : primes) {
        int cnt = 0;
        int val = n;
        while (val > 0) {
            cnt += val / i;
            val /= i;
        }
        if (cnt == 0) break;
        ans.push_back({i, cnt});
    }
    cout << n << " =";
    for (int i = 0; i < ans.size(); i++) {
        cout << " " << ans[i].first << " (" << ans[i].second << ") " << "*\n"[i + 1 == ans.size()];
    }
}
signed main() {
    int tc;
    cin >> tc;
    vector<bool> p(101, true);
    for (int i = 2; i <= 100; i++) {
        if (p[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= 100; j += i) {
                p[j] = false;
            }
        }
    }

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}