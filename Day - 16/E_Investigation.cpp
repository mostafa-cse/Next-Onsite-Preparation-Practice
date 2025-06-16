#include<bits/stdc++.h>
#define int long long
using namespace std;
class digit_Dp {
private:
    int a, b, k, res, n,dp[10][2][95][95];
    string num;
    int calculate(int idx, bool last, int sum, int dsum) {
        if(idx == n) {
            if(sum == 0 and dsum == 0) {
                return 1;
            }
            return 0;
        }
        if(dp[idx][last][sum][dsum] != -1) {
            return dp[idx][last][sum][dsum];
        }
        int ans = 0, range = (last ? num[idx] - '0' : 9);
        for (int i = 0; i <= range; i++) {
            ans += calculate(idx + 1, 
                            last && i == range,
                            ((sum * 10) % k + i) % k, 
                            (dsum + i) % k
                    );
        }
        return dp[idx][last][sum][dsum] = ans;
    }
    int getval (int x) {
        if(k > 90) {
            return 0;
        }
        memset(dp, -1, sizeof dp);
        num = to_string(x);
        n = num.size();
        res = calculate(0, 1, 0, 0);
        return res;
    }
public:
    void solve() {
        cin >> a >> b >> k;
        res = getval(b) - getval(a - 1);
        cout << res << endl;
    }
};
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    int tc;
    cin >> tc;
    digit_Dp obj;
    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        obj.solve();
    }
    return 0;
}