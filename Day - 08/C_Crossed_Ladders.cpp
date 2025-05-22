#include <bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
void solve() {
    ld x, y, h;
    cin >> x >> y >> h;
    /**
    * d1 = c / tan(acos(x / d))
    * d2 = c / tan(acos(y / d))
    * d = d1 + d2
    **/
    function<bool(ld)> fun = [&](ld d) {
        ld d1 = h / tan(acos(d / x));
        ld d2 = h / tan(acos(d / y));
        return d1 + d2 <= d;
    };

    ld l = 0.00, r = min(x, y), ans = 0.00;
    for (int i = 0; i < 100; i++) {
        ld mid = (l + r) * 0.5;

        if (fun(mid)) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << ans << endl;
}
signed main() {
    cout.unsetf(ios::floatfield);
    cout.precision(10);
    cout.setf(ios::fixed, ios::floatfield);
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}