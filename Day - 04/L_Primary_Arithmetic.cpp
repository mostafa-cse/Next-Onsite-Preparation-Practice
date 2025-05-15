#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    string a, b;
    while (cin >> a >> b) {
        if (a == "0" and b == "0") break;
        if (a.size() > b.size()) swap(a, b);
        while (a.size() < b.size()) {
            a = "0" + a;
        }
        int ans = 0, sum = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            int x = a[i] - '0';
            int y = b[i] - '0';
            sum += (x + y);
            ans += sum / 10;
            sum /= 10;
        }
        if (ans == 0) {
            cout << "No";
            cout << " carry operation." << endl;
        } else {
            cout << ans;
            if (ans == 1) {
                cout << " carry operation." << endl;
            } else {
                cout << " carry operations." << endl;    
            }
        }
    }
    return 0;
}