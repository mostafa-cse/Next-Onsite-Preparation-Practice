#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<bool> isPrime(1000005, true);
vector<int> primes;
auto PrimeSet = [] {
    for (int i = 2; i <= 1000000; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= 1000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return 0;
}();
void solve() {
    int n;
    cin >> n;

    int ans = 1;
    for (int i : primes) {
        if (i * i > n) break;
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            ans *= (cnt + 1);
        }
    }
    if (n != 1) {
        ans *= 2;
    }
    cout << ans - 1 << endl;
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}