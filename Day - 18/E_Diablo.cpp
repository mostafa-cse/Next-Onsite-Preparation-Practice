#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegmentTree {
    vector<int> sgt;
    vector<int> a;
    int n;
    SegmentTree(int N) {
        this->n = N;
        a.assign(N + 1, 0);
        sgt.assign(N * 4 + 1, 0);
    }
    int combine(int a, int b) {
        return a + b;        // ➜ sum
    }
    void build (int node, int l, int r) {
        if (l == r) {
            sgt[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            sgt[node] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (l > qr or r < ql) {
            return 0; // Edit here
        }
        if (l >= ql and r <= qr) {
            return sgt[node];
        }
        int mid = l + (r - l) / 2;
        int left = query(node * 2, l, mid, ql, qr);
        int right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return combine(left, right);
    }
    void build() { build(1, 1, n); }
    void update(int idx, int val) { update(1, 1, n, idx, val); }
    int query(int l, int r) { return query(1, 1, n, l, r); }
};
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    SegmentTree sg(n + 50005);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sg.update(i, 1);
    }

    while (q--) {
        char c;
        cin >> c;

        int val;
        cin >> val;
        if (c == 'c') {
            int l = 1, r = a.size(), idx = -1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (sg.query(1, mid) >= val) {
                    idx = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (sg.query(1, idx) != val) {
                cout << "none" << endl;
            } else {
                cout << a[idx] << endl;
                // cout << "Index: " << idx << " : " << sg.query(1, idx) << endl;
                sg.update(idx, 0);
            }
        } else {
            a.push_back(val);
            sg.update(a.size() - 1, 1);
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