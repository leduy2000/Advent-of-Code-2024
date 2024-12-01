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
	vector<int> a, b;
	map<int, int> freq;
	for (int i = 0; i < 2000; i++) {
		int x;
		cin >> x;
		if (i % 2 == 0) {
			b.push_back(x);
		} else {
			a.push_back(x);
		}
	}

	for (int x : b) {
		freq[x]++;
	}

	int ans = 0;
	for (int x : a) {
		ans += x * freq[x];
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}