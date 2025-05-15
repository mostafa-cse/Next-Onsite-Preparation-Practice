#include <bits/stdc++.h>
#define int long long
using namespace std;
void Solve() {
    int n;
    cin >> n;

    list<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, 0});
        adj[b].push_back({a, c});
    }

    function<int(int, int, int)> dfs = [&](int node, int par, int lvl) -> int {
        // cout << '[' << par << "->" << node << " " << lvl << ']' << endl;
        if (lvl == n + 1) {
            return 0;
        }
        int ans = 1e15;
        for (auto [nbr, wt] : adj[node]) {
            if (par != nbr) {
                ans = min(ans, wt + dfs(nbr, node, lvl + 1));
            }
        }
        return ans;
    };
    cout << dfs(1, 0, 1) << endl;
}
signed main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        Solve(); 
    }
    return 0;
}