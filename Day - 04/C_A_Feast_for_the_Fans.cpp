#include <bits/stdc++.h>
#define int long long
using namespace std;
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string a[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int Episod[] = {0, 10, 10, 10, 10, 10, 10, 7};
map<string, int> mark;
signed main() {
    for (int i = 1; i <= 12; i++) {
        mark[a[i]] = i;
        month[i] += month[i - 1];
    }

    int tc;
    cin >> tc;
    auto Pirnt = [](int sea, int epi) {
        cout << "S0" << sea << 'E';
        if (epi != 10) {
            cout << '0';
        }
        cout << epi << endl;
    };
    int season = 7, episod = 67;
    for (int i = 1; i <= tc; ++i) {
        string mnth;
        int n;
        cin >> mnth >> n;

        int total_day = month[mark[mnth] - 1] + n;
        total_day %= episod;
        if (total_day == 0) {
            Pirnt(7, 7);
            continue;
        }
        int ans_episod = total_day, ans_season = 1;
        for (; ans_season <= 7; ans_season++) {
            if (ans_episod - Episod[ans_season] <= 0) {
                break;
            }
            ans_episod -= Episod[ans_season];
        }
        Pirnt(ans_season, ans_episod);
    }
    
    return 0;
}