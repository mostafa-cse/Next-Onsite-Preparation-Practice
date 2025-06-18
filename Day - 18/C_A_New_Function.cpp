#include <bits/stdc++.h>
#define int long long
using namespace std;
long long sod(long long num) {
    long long sum = 0;
    for (long long i = 2; i <= sqrt(num); i++) {
        long long t1 = i * (num / i - i + 1); 
        long long t2 = (((num / i) * (num / i + 1)) / 2) - ((i * (i + 1)) / 2);
        sum += t1 + t2;
    }
    return sum;
}
void solve() {
    int n;
    cin >> n;
    cout << sod(n) << endl;
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