#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<int> suti(10005, 0);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        for (int j = x; j <= y; j++) {
            suti[j] = 1;
        }
    }

    int ans = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        bool sutinisi = 0;
        for (int j = x; j <= y; j++) {
            if (suti[j]) {
                sutinisi = 1;
                break;
            }
        }
        if (sutinisi == 0) {
            ans += (y - x + 1);
            for (int j = x; j <= y; j++) {
                suti[j] = 1;
            }
        }
    }
    cout << ans ;
    return 0;
}