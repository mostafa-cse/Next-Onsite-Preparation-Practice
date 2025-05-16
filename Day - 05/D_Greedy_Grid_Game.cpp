#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    function<int(int, int, int, int dir)> dfs = [&](int i, int j, int cnt, int dir) -> int {
        if (i < 0 or i >= n or j < 0 or j >= m or vis[i][j]) {
            return 0;
        }
        vis[i][j] = 1;
        int ans = 0;
        if (cnt) {
            if (j == m - 1 or i == n - 1) {
                ans += a[i][j] + dfs(i + 1, j + 1, 0, 0) + dfs(i + 1, j - 1, 0, 0) + dfs(i - 1, j + 1, 0, 0) + dfs(i - 1, j - 1, 0, 0);
            }
        }
        if (dir == 0) {
            ans += a[i][j] + dfs(i + 1, j, 1, cnt);
            ans += a[i][j] + dfs(i, j + 1, 2, cnt);
        } else if (dir == 1) {
            ans += a[i][j] + dfs(i + 1, j, 1, cnt);
        } else if (dir == 2) {
            ans += a[i][j] + dfs(i, j + 1, 2, cnt);
        }
        return ans;
    };
    cout << dfs(0, 0, 0, 1) << endl;
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}