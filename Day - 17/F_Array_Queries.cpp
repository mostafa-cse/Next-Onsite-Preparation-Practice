#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx], tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left] , tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return INT_MAX;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;  
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return min(p1 , p2); 
}
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(tree, 0xff, sizeof(tree));
    init(1, 1, n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << '\n';
    }
}
int main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}