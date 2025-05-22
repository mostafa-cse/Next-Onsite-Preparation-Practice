#include <bits/stdc++.h>
using namespace std;
int grid[505][505];
int seg[4 * 505][4 * 505];
int N;
void build_y(int nodex, int lx, int rx, int nodey, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            seg[nodex][nodey] = grid[lx][ly];
        else
            seg[nodex][nodey] = max(seg[nodex * 2][nodey], seg[nodex * 2 + 1][nodey]);
    } else {
        int my = (ly + ry) / 2;
        build_y(nodex, lx, rx, nodey * 2, ly, my);
        build_y(nodex, lx, rx, nodey * 2 + 1, my + 1, ry);
        seg[nodex][nodey] = max(seg[nodex][nodey * 2], seg[nodex][nodey * 2 + 1]);
    }
}

void build_x(int nodex, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(nodex * 2, lx, mx);
        build_x(nodex * 2 + 1, mx + 1, rx);
    }
    build_y(nodex, lx, rx, 1, 0, N - 1);
}

int query_y(int nodex, int nodey, int ly, int ry, int qly, int qry) {
    if (qry < ly || ry < qly) return INT_MIN;
    if (qly <= ly && ry <= qry) return seg[nodex][nodey];
    int my = (ly + ry) / 2;
    return max(
        query_y(nodex, nodey * 2, ly, my, qly, qry),
        query_y(nodex, nodey * 2 + 1, my + 1, ry, qly, qry));
}

int query_x(int nodex, int lx, int rx, int qlx, int qrx, int qly, int qry) {
    if (qrx < lx || rx < qlx) return INT_MIN;
    if (qlx <= lx && rx <= qrx) return query_y(nodex, 1, 0, N-1, qly, qry);
    int mx = (lx + rx) / 2;
    return max(
        query_x(nodex * 2, lx, mx, qlx, qrx, qly, qry),
        query_x(nodex * 2 + 1, mx + 1, rx, qlx, qrx, qly, qry));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int Q;
        cin >> N >> Q;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> grid[i][j];

        build_x(1, 0, N-1);

        cout << "Case " << t << ":\n";
        while (Q--) {
            int i, j, s;
            cin >> i >> j >> s;
            int x1 = i - 1, y1 = j - 1;
            int x2 = x1 + s - 1, y2 = y1 + s - 1;
            cout << query_x(1, 0, N - 1, x1, x2, y1, y2) << '\n';
        }
        memset(seg, 0, sizeof seg);
    }
    return 0;
}
