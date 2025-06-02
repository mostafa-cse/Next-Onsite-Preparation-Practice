#include<bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
string cdn[2] = {"NO", "YES"};
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
void Solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n + 1), AnsStops;
	for (int &i : a) {
		cin >> i;
	}

	auto f = [&](int Can_Walk) {
		int Walk = 0;
		int stop = 0;
		vector<int> v;
		for (int i : a) {
			if (Walk + i > Can_Walk) {
				stop++;
				if (stop > k) {
					return false;
				}
				v.push_back(Walk);
				Walk = i;
			} else {
				Walk += i;
			}
		}
		v.push_back(Walk);
		AnsStops = v;
		return true;
	};
	int Max_Walk = -1;
    int l = *max_element(all(a)), r = 1e9;
    while (l <= r) {
		int mid = (l + r) >> 1;

		if (f(mid)) {
			Max_Walk = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << Max_Walk << endl;

	int leftStops = k + 1 - AnsStops.size();
	vector<int> LeftAns;
	while (leftStops > 0) {
		int b = a.back();
		a.pop_back();

		LeftAns.push_back(b);
		AnsStops.back() -= b;
		if (AnsStops.back() == 0) {
			AnsStops.pop_back();
		} else {
			leftStops--;
		}
	}

	for (int &i : AnsStops) {
		cout << i << " \n";
	}
	for (int i = LeftAns.size() - 1; i >= 0; i--) {
		cout << LeftAns[i] << " \n";
	}
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
    	cout << "Case " << i + 1 << ": ";
    	Solve();
    }
    return 0;
}
