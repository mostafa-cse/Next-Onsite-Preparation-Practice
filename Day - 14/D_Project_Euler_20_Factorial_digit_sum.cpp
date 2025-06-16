#include <bits/stdc++.h>
#define int long long
using namespace std;
string Multiply(const string& a, const string& b) { 
    int n = a.size();
    int m = b.size();
    vector<int> ans(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        int digit1 = a[i] - '0';
        for (int j = m - 1; j >= 0; --j) {
            int digit2 = b[j] - '0';
            int mul    = digit1 * digit2;
            int sum    = ans[i + j + 1] + mul; 
            ans[i + j + 1] = sum % 10;    
            ans[i + j]   += sum / 10;       
        }
    }
    string res;
    for (int x : ans) {
        if (!(res.empty() && x == 0)) {
            res.push_back(char('0' + x));
        }
    }
    return res.empty() ? "0" : res;
}
vector<string> fact(1001);
void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for (auto e : fact[n]) {
        ans += (e - '0');
    }
    cout << ans << endl;
}
signed main() {
    fact[0] = "1";
    for (int i = 1; i <= 1000; i++) {
        fact[i] = Multiply(fact[i - 1], to_string(i));
    }
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}