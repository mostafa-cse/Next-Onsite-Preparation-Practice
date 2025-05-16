#include <bits/stdc++.h>
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
void solve() {
    int n;
    cin >> n;

    vector<int> adj[n], deg(n, 0);
    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;

        char a, b;
        int k;
        cin >> a >> k >> b;

        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            deg[x]++;
            adj[node].push_back(x);
        }
    }

    vector<int> vis(n, 0), par(n, 0), disc(n, 0), low(n, 0);
    int timeCounter = 0;
    vector<pair<int, int>> ans;
    function<void(int)> dfs = [&](int u) -> void {
        vis[u] = true;
        disc[u] = low[u] = ++timeCounter;

        for (int v : adj[u]) {
            if (!vis[v]) {
                par[v] = u;
                dfs(v);

                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u])
                    ans.push_back({min(u, v), max(u, v)});
            }
            else if (v != par[u]) {
                low[u] = min(low[u], disc[v]);
            }
    }
    };
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << " critical links" << endl;
    for (auto [x, y] : ans) {
        cout << x << " - " << y << endl;
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