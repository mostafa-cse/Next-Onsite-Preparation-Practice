#include <bits/stdc++.h>
#define int long long
using namespace std;
class DSU {
    vector<int> parent, sz;
public:
    DSU(int n) : parent(n + 1), sz(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;

        if (sz[ra] < sz[rb]) {
            swap(ra, rb);
        }
        parent[rb] = ra;
        sz[ra] += sz[rb];
        return true;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    int size(int x) {
        return sz[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    struct Node {
        int u, v, wt;
        Node(int a, int b, int c) : u(a), v(b), wt(c) {}
    };
    vector<Node> edge;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                edge.push_back(Node(i, j, a[i][j]));
            }
        }
    }
    sort(edge.begin(), edge.end(), [](const Node &x, const Node &y){
        return x.wt < y.wt;
    });

    int ans = 0;
    DSU ds(n);
    for (auto &[u, v, w] : edge) {
        if (!ds.unite(u,v)) {
            ans += w;
        }
    }

    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(ds.find(i));
        if (s.size() == 2) {
            cout << -1 << endl;
            return;
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