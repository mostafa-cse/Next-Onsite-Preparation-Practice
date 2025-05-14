#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct BigInt {
    static constexpr int BASE = 1000000000, BASE_DIGITS = 9;
    int sign = 1;
    vector<int> a;
    BigInt(i64 v = 0) { *this = v; }
    BigInt& operator=(i64 v) {
        sign = v < 0 ? (v = -v, -1) : 1;
        a.clear();
        for (; v; v /= BASE) a.push_back(v % BASE);
        return *this;
    }
    void trim() {
        while (!a.empty() && a.back() == 0) a.pop_back();
        if (a.empty()) sign = 1;
    }
    friend ostream& operator<<(ostream& os, const BigInt& v) {
        if (v.sign < 0) os << '-';
        if (v.a.empty()) return os << '0';
        os << v.a.back();
        for (int i = (int)v.a.size() - 2; i >= 0; --i)
            os << setw(BASE_DIGITS) << setfill('0') << v.a[i];
        return os;
    }
    void mulInt(int m) {
        if (m < 0) sign = -sign, m = -m;
        long long carry = 0;
        for (size_t i = 0; i < a.size() || carry; ++i) {
            if (i == a.size()) a.push_back(0);
            long long cur = carry + 1LL * a[i] * m;
            a[i] = int(cur % BASE);
            carry = cur / BASE;
        }
        trim();
    }
    BigInt operator*(const BigInt& v) const {
        BigInt res;
        res.sign = sign * v.sign;
        vector<long long> tmp(a.size() + v.a.size());
        for (size_t i = 0; i < a.size(); ++i)
            for (size_t j = 0; j < v.a.size(); ++j)
                tmp[i + j] += 1LL * a[i] * v.a[j];
        res.a.resize(tmp.size());
        long long carry = 0;
        for (size_t i = 0; i < tmp.size(); ++i) {
            long long cur = tmp[i] + carry;
            res.a[i] = int(cur % BASE);
            carry = cur / BASE;
        }
        res.trim();
        return res;
    }
    BigInt& operator*=(const BigInt& v) { return *this = *this * v; }
};

BigInt powBig(BigInt base, int exp) {
    BigInt result = 1;
    while (exp) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}
const int SZ = 10000 + 4;
vector<int> prime;
vector<bool> isPrime(SZ, true);
auto PrimeSet = [] {
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < SZ; ++i) {
        if (isPrime[i]) {
            for (int j = 2 * i; j < SZ; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < SZ; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
    return 0;
}();
void Solve() {
    int n;
    cin >> n;
    vector<int> xs(n);
    for (auto &x : xs) {
        cin >> x;
    }

    unordered_map<int,int> mxpw;
    for (int v : xs) {
        int t = v;
        for (int p : prime) {
            if ((i64)p * p > t) break;
            int cnt = 0;
            while (t % p == 0) {
                t /= p;
                ++cnt;
            }
            if (cnt) mxpw[p] = max(mxpw[p], cnt);
        }
        if (t > 1) {
            mxpw[int(t)] = max(mxpw[int(t)], 1);
        }
    }

    BigInt ans = 1;
    for (auto& [p, e] : mxpw) {
        BigInt term = powBig(BigInt(p), e);
        ans *= term;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        cout << "Case " << tc << ": ";
        Solve();
        cout << "\n";
    }
    return 0;
}
