#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<string> ones = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
void rec(int n, vector<string>& parts) {
    if (n < 20) {
        parts.push_back(ones[n]);
    }
    else if (n < 100) {
        parts.push_back(tens[n/10]);
        if (n % 10 != 0)
            rec(n % 10, parts);
    }
    else if (n < 1000) {
        rec(n/100, parts);
        parts.push_back("Hundred");
        if (n % 100 != 0)
            rec(n % 100, parts);
    }
    else if (n < 1000000) {
        rec(n/1000, parts);
        parts.push_back("Thousand");
        if (n % 1000 != 0)
            rec(n % 1000, parts);
    }
    else if (n < 1000000000) {
        rec(n/1000000, parts);
        parts.push_back("Million");
        if (n % 1000000 != 0)
            rec(n % 1000000, parts);
    }
    else {
        rec(n/1000000000, parts);
        parts.push_back("Billion");
        if (n % 1000000000 != 0)
            rec(n % 1000000000, parts);
    }
}

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "Zero\n";
        return;
    }

    vector<string> parts;
    rec(n, parts);

    for (int i = 0; i < (int)parts.size(); i++) {
        cout << parts[i];
        if (i + 1 < (int)parts.size())
            cout << ' ';
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
