#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    string s;
    cin >> s;
    s = s.substr(0, s.size() >> 1);
    reverse(s.begin(), s.end());

    cout << s << endl;
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << i << ": "'
        solve();
    }
    return 0;
}