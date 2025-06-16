#include <bits/stdc++.h>
#define int long long
using namespace std;
bool isVowel(char ch) {
    return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
void solve() {
    string s;
    cin >> s;
    bool bad = false, good = false;
    vector<vector<int>> dp(3, vector<int>(5, 0));
    dp[0][0] = true;
    for (char ch : s) {
        vector<vector<int>> cur(3, vector<int>(5, 0));
        for (int v = 0; v < 3; ++v) {
            for (int c = 0; c < 5; ++c) {
                if (!dp[v][c]) continue;

                auto fun = [&](bool isvowel) {
                    int nv = isvowel ? v + 1 : 0;
                    int nc = isvowel ? 0 : c + 1;
                    if (nv >= 3 || nc >= 5) {
                        bad = true;
                    } else {
                        cur[nv][nc] = true;
                    }
                };

                if (ch == '?') {
                    fun(true);
                    fun(false);
                } else if (isVowel(ch)) {
                    fun(true);
                } else {
                    fun(false);
                }
            }
        }
        dp = cur;
    }

    for (int v = 0; v < 3 && !good; ++v) {
        for (int c = 0; c < 5; ++c) {
            if (dp[v][c]) {
                good = true;
                break;
            }
        }
    }

    if (bad && !good) {
        cout << "BAD" << endl;
    } else if (!bad && good) {
        cout << "GOOD" << endl;
    } else {
        cout << "MIXED" << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
