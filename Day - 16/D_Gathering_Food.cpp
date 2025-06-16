//M0stafa wrote this code
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;

    vector<vector<char>> a(n,vector<char>(n));
    for (vector<char>&sub : a) {
        for (char &c : sub) {
            cin >> c;
        }
    }

    int r = -1, c = -1;
    for (int i = 0; i < n and r == -1; ++i) {
        for (int j = 0; j < n and c == -1; ++j) {
            if (a[i][j] == 'A') {
                r = i, c = j;
                break;
            }
        }
    }

    if (r == -1 and c == -1) {
        cout << 0 << endl;
        return;
    }

    function<int(int, int, char)> dfs = [&](int i, int j, char cur) -> int {
        if (i == n or j == n or a[i][j] == '#' or (isalpha(a[i][j]) and a[i][j] != cur)) {
            return 0;
        }
        int ans = 1e18;
        if (i + 1 < n) {
            if (a[i + 1][j] == '.')  ans = min(ans, 1 + dfs(i + 1, j, cur));
            else if (a[i + 1][j] == cur) ans = min(ans, 1 + dfs(i + 1, j, cur + 1));
        }
        if (i - 1 >= 0) {
            if (a[i - 1][j] == '.')  ans = min(ans, 1 + dfs(i - 1, j, cur));
            else if (a[i - 1][j] == cur) ans = min(ans, 1 + dfs(i - 1, j, cur + 1));
        }

        if (j + 1 < n) {
            if (a[i][j + 1] == '.') ans = min(ans, 1 + dfs(i, j + 1, cur));
            else if (a[i][j + 1] == cur) ans = min(ans, 1 + dfs(i, j + 1, cur + 1));
        }
    };
    cout << dfs(r, c, 'A') << endl;
}
int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}