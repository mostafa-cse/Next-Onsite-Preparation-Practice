#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, q;
    cin >> n >> q;

    map<int, int> dp;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        dp[l]++;
        dp[r + 1]--;
        
        a.push_back(l);
        a.push_back(r);
        a.push_back(r + 1);
    }    

    vector<int> point(q);
    for (int i = 0; i < q; i++) {
        cin >> point[i];
        a.push_back(point[i]);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    
    for (int i = 1; i < a.size(); i++) {
        dp[a[i]] = dp[a[i]] + dp[a[i - 1]];
    }
    for (int i : point) {
        cout << dp[i] << endl;
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