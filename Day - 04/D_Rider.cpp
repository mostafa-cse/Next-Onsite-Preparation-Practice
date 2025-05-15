#include <bits/stdc++.h>
#define int long long
using namespace std;
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    set<char> digit;
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != '.') {
                digit.insert(grid[i][j]);
                cnt[grid[i][j]]++;
            }
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    function<int(int, int, int, int)> dfs = [&](int i, int j, int rem, int num) -> int {
        if (rem == 0)
            return 0;
        if (i < 0 or j < 0 or i >= n or j >= m or vis[i][j] == 1) {
            return 1e18;
        }
        if (grid[i][j] != '.') {
            if (grid[i][j] - '0' > num) {
                return 1e18;
            }
        }
        vis[i][j] = 1;
        int ans = 1e18;
        for (int p = 1; p <= num; p++) {
            for (int d = 0; d < 8; d++) {
                ans = min(ans, 1 + (i + dx[d], j + dy[d], rem - (grid[i][j] - '0' == num), num));
            }
        }
        return ans;
    };
    int ans = 0;
    function<void()> reset = [&]() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }
    };
    for (char d = '1'; d <= '9'; d++) {
        bool ok = true;
        reset();
        for (int i = 0; i < n and ok; i++) {
            for (int j = 0; j < m and ok; j++) {
                if (grid[i][j] == d) {
                    ans += dfs(i, j, cnt[grid[i][j]], d - '0');
                    ok = false;
                }
            }
        }
    }
    cout << ans << endl;
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