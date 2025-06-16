#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1); 
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int m; 
    cin >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, pow(a[v] - a[u], 3));
    }

    vector<int> dist(n + 1, 1e8);
    dist[1] = 0;

    for (int i = 1; i < n; ++i) {
        for (int u = 1; u <= n; ++u) {
            if (dist[u] != 1e8) {
                for (auto &[v, cost] : adj[u]) {
                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                    }
                }
            }
        }
    }

    vector<bool> isneg(n + 1, false);
    for (int u = 1; u <= n; ++u) {
        if (dist[u] != 1e8) {
            for (auto &[v, cost] : adj[u]) {
                if (dist[u] + cost < dist[v]) {
                    isneg[v] = true;
                }
            }
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;

        if (dist[x] < 3 || dist[x] == 1e8 || isneg[x]) {
            cout << "?" << endl;
        } else {
            cout << dist[x] << endl;
        }
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