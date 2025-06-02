#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e6;
vector<long double> fact(M + 1);
void solve() {
    int n, b;
    cin >> n >> b;
    cout << (int)(fact[n] / log(b)) + 1 << endl;
}
signed main() {
    fact[1] = log(1);
    for (int i = 2; i <= M; i++) {
        fact[i] = fact[i - 1] + log(i);
    }
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}