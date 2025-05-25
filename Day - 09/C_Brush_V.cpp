#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
        adj[y].push_back({x, wt});
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dis(n + 1, 1e18);

    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty()) {
        auto [w, node] = pq.top();
        pq.pop();

        for (auto [nbr, wt] : adj[node]) {
            if (dis[nbr] > dis[node] + wt) {
                dis[nbr] = dis[node] + wt;
                pq.push({dis[nbr], nbr});
            }
        }
    }
    if (dis[n] != 1e18) {
        cout << dis[n] << endl;
    } else {
        cout << "Impossible" << endl;
    }
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