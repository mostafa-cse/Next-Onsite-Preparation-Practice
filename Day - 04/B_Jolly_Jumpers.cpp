#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
        }

        map<int, bool> ans;
        for (int i = 1; i < n; i++) {
            ans[abs(a[i] - a[i - 1])] = true;
        }

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (!ans[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Jolly" : "Not jolly") << endl;
    }
    return 0;
}