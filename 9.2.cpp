#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k
// find_by_order(k) : K-th element in a set (counting from zero)

const int MOD = 1e9 + 7;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(n), c(n);
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}

	vector<vector<int>> b(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			c[i] = cnt;
			cnt++;
		} else {
			c[i] = -1;
		}
	}

	vector<int> v;
	vector<bool> mv(n);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < a[i]; j++) {
				v.push_back(c[i]);
			}
		} else {
			int sz = a[i];
			for (int j = n - 1; j > i; j--) {
				if (j % 2 == 0 and !mv[j]) {
					if (sz >= a[j]) {
						sz -= a[j];
						for (int k = 0; k < a[j]; k++) {
							v.push_back(c[j]);
						}
						c[j] = -1;
						mv[j] = true;
					}
				}
			}
			while (sz--) {
				v.push_back(-1);
			}
		}
	}

	
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != -1) {
			ans += i * v[i];
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}