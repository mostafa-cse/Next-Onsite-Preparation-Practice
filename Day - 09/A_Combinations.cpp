#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e6, Mod = 1000003;
vector<int> fact(M + 6);
int modexpo(int a, int p,int mod) {
    int res = 1;
    while (p) {
        if(p & 1) {
            res = (a * res) % mod;
        }
        p >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
auto pre = []() {
    fact[0] = 1;
    for (int i = 1; i <= M; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= Mod;
    }
    return "0";
}();
int nCr(int n, int r) {
    if (n < r) return 0;
    int ans = fact[n];
    ans = (ans * modexpo(fact[n - r], Mod - 2, Mod)) % Mod;
    ans = (ans * modexpo(fact[r], Mod - 2, Mod)) % Mod;
    return ans;
}
signed main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        int N, R;
        cin >> N >> R;
        
        cout << "Case " << i << ": ";
        if (N < R) {
            cout << 0 << endl;
        } else {
            cout << nCr(N, R) << endl;
        }
    }
    return 0;
}