#include <bits/stdc++.h>
#define int long long
using namespace std;
const uint64_t MOD = (1ULL << 64);

// Matrix multiplication function
vector<vector<uint64_t>> matmul(const vector<vector<uint64_t>> &A, const vector<vector<uint64_t>> &B) {
    vector<vector<uint64_t>> C(2, vector<uint64_t>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Matrix exponentiation function
vector<vector<uint64_t>> matexpo(vector<vector<uint64_t>> base, uint64_t exp) {
    vector<vector<uint64_t>> result = {{1, 0}, {0, 1}}; // Identity matrix
    while (exp) {
        if (exp & 1) {
            result = matmul(result, base);
        }
        base = matmul(base, base);
        exp >>= 1;
    }
    return result;
}

void solve() {
    uint64_t p, q, n;
    cin >> p >> q >> n;

    if (n == 0) {
        cout << "2\n"; // S_0 = 2
        return;
    }
    if (n == 1) {
        cout << p << "\n"; // S_1 = p
        return;
    }

    // Matrix representation
    vector<vector<uint64_t>> M = {{p, MOD - q}, {1, 0}}; // MOD - q ensures modulo arithmetic works correctly
    vector<vector<uint64_t>> Mn = matexpo(M, n - 1);

    // Compute S_n using matrix multiplication
    uint64_t S_n = (Mn[0][0] * p + Mn[0][1] * 2) % MOD; // S_n = Mn[0][0] * S_1 + Mn[0][1] * S_0
    cout << S_n << "\n";
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