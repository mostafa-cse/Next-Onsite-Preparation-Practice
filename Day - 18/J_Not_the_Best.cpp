#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mx = 5e3;
vector<pair<int, int>> adj[mx];
int dist[3][mx];

struct info {
    int u, v, w;
};
void dijkstra(int s, int n, int f1) {
    for (int i = 1; i <= n; i++)
        dist[f1][i] = 1e18;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        pq;

    dist[f1][s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int curD = pq.top().first;
        pq.pop();

        if (curD > dist[f1][u])
            continue;

        for (auto v : adj[u]) {
            if (v.second + curD < dist[f1][v.first]) {
                dist[f1][v.first] = v.second + curD;
                pq.push({dist[f1][v.first], v.first});
            }
        }
    }
}

int32_t main() {

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        for (int i = 1; i <= 5e3; i++)
            adj[i].clear();

        vector<info> edge;
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            edge.push_back({u, v, w});
        }

        dijkstra(1, n, 0);
        dijkstra(n, n, 1);

        int s1 = dist[0][n];
        int s2 = 1e18;

        for (auto e : edge) {
            int curD =
                min(dist[0][e.u] + dist[1][e.v], dist[1][e.u] + dist[0][e.v]);

            if (curD + e.w > s1) {
                s2 = min(s2, curD + e.w);
            }

            if (curD + e.w == s1)
                s2 = min(s2, curD + (e.w * 3));
        }

        cout << "Case " << tc << ": " << s2 << endl;
    }
    return 0;
}
