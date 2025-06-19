#include<bits/stdc++.h>
#define int long long
using namespace std;

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<array<int, 3>> edge;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edge.push_back({u,v,w});
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    auto dijkstra = [&](int src) {
        vector<int> dis(n + 1, 1e18);
        priority_queue<pair<int, int>> pq;
        dis[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (w + dis[u] < dis[v]) {
                    dis[v] = w + dis[u];
                    pq.push({-dis[v], v});
                }
            }
        }
        return dis;
    };
    vector<int> dis_1 = dijkstra(1);
    vector<int> dis_n = dijkstra(n);


    int s1 = dis_1[n], ans = 1e18;
    for (auto [u, v, w] : edge) {
        int cur = min(dis_1[u] + dis_n[v], dis_n[u] + dis_1[v]) + w;
        if (cur > s1) {
            ans = min(ans, cur);
        }
        if (cur == s1) {
            ans = min(ans, cur + 2 * w);
        }
    }
    cout << ans;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        if (i) {
            cout << endl;
        }
        cout << "Case " << i + 1 << ": ";
        Solve();
    }
    return 0;
}
