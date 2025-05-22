#include <bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
void solve() {
    ld x, y, r;
    cin >> x >> y >> r;

    ld xx, yy, rr;
    cin >> xx >> yy >> rr;

    ld d = sqrtl((x - xx) * (x - xx) + (y - yy) * (y - yy));
    if (d >= r + rr) {
        return cout << 0 << endl, void();
    }
    
    if (d <= abs(r - rr)) {
        ld area = M_PI * min(r, rr) * min(r, rr);
        return cout << area << endl, void();
    }

    ld theta1 = 2 * acos((r * r + d * d - rr * rr) / (2 * d * r));
    ld theta2 = 2 * acos((rr * rr + d * d - r * r) / (2 * d * rr));

    // intersection_area = sector_area - triangle_area
    ld area1 = 0.5 * r * r * (theta1 - sin(theta1));
    ld area2 = 0.5 * rr * rr * (theta2 - sin(theta2));

    cout << area1 + area2 << endl;
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