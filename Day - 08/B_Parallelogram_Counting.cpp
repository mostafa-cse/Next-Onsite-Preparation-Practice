#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }

    vector<pair<double, double>> mid_point;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // A parallelogram is fully determined by its two diagonals intersecting at the same midpoint.
            double x = (a[i].first + a[j].first) * 0.5;
            double y = (a[i].second + a[j].second) * 0.5;
            mid_point.push_back({x, y});
        }
    }
    sort(mid_point.begin(), mid_point.end());
    
    int ans = 0;
    int cnt = 0;
    pair<double, double> last;
    for (int i = 0; i < mid_point.size(); i++) {
        if (i == 0) {
            cnt = 1;
            last = mid_point[i];
        } else if (last == mid_point[i]) {
            cnt++;
        } else {
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
            last = mid_point[i];
        }
    }
    ans += cnt * (cnt - 1) / 2;
    cout << ans << endl;
}

signed main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
