#include <bits/stdc++.h>
#define int long long
using namespace std;
class DSU {
    map<string, int> rank;

public:
    // vector<int> parent, rank;
    map<string, string> parent;
    DSU() {}
    string find(string x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(string a, string b) {
        string ra = find(a);
        string rb = find(b);
        if (ra == rb) return false;
        if (rank[ra] < rank[rb]) swap(ra, rb);

        parent[rb] = ra;
        if (rank[ra] == rank[rb]) {
            ++rank[ra];
        }
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    struct edge {
        string u, v;
        int wt;
    };
    
    DSU ds;    
    vector<edge> a(n);
    for (auto &[u,v,w] : a) {
        cin >> u >> v >> w;
        ds.parent[u] = u;
        ds.parent[v] = v;
    }
    sort(a.begin(), a.end(), [](const edge &X, const edge &Y){
        return X.wt < Y.wt;
    });
    int ans = 0;
    for (auto &[u,v,w] : a) {
        if (ds.unite(u,v)) {
            ans += w;
        }
    }
    
    int cnt = 0;
    set<string> par;
    for (auto &[u,v,w] : a) {
        par.insert(ds.find(u));
        par.insert(ds.find(v));

        if (par.size() >= 2) {
            cout << "Impossible" << endl;
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