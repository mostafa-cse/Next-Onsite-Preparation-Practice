#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
template<typename T> bool smin(T& a, const T& b) { if (b < a) { a = b; return true; } return false;}
template<typename T> bool smax(T& a, const T& b) { if (a < b) { a = b; return true; } return false;}
template <class A, class B> ostream &operator<<(ostream &out, const pair<A, B> &a){return out << a.first << " " << a.second;}
template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x: v) in >> x; return in; }
template<typename T>ostream &operator<<(ostream &out, const vector<T> &v) { for (const T &x: v) out << x << ' ';return out;}
template <class K, class V>
using ht = gp_hash_table<K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true>>;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
void pbit(int a) {
    cout << a << " : " << bitset<40>(a) << endl;
}
void Solve () {
    int P, L;
    cin >> P >> L;

    int tot = P - L;
    set<int> ans;
    for (int i = 1; i * i <= tot; i++) {
        if (tot % i == 0) {
            if (P % i == L) ans.insert(i);
            if (P % (tot / i) == L) ans.insert(tot / i);
        }
    }
    if (ans.empty()) {
        cout << "impossible";
        return;
    }
    for (auto el : ans) {
        cout << el << " ";
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc = 1;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        Solve();
        cout << endl;
    }
    return 0;
}