#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    int n;
    cin >> n;

    if (n != 1 and n <= 3) {
    	return cout << "NO SOLUTION", 0;
    }
   	for (int j = 2; j <= n; j += 2) cout << j << " ";
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    return 0;
}
