#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;

    map<string, vector<string>> graph;
    set<string> nodes;
    for (int i = 0; i < n - 1; i++) {
        string u, v;
        cin >> u >> v;
        graph[u].push_back(v);

        nodes.insert(u);
        nodes.insert(v);
    }

    function<int(string, string, bool)> dfs = [&](string u, string par, bool ok) -> int {
        if (ok) cout << u << "\n";
        int cnt = 0;
        for (string v : graph[u]) {
            if (v == par) continue;
            cnt = 1 + dfs(v, u, ok);
        }
        return cnt;
    };

    for (auto u : nodes) {
        int cnt = dfs(u, "", false);
        if (cnt + 1 == n) {
            dfs(u, "", true);
            cout << endl;
            return;
        }
    }
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": \n";
        solve();
        // cout << endl;
    }
    return 0;
}