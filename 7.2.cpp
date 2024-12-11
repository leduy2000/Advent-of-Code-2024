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

	auto g = [&](vector<int> &a, int res) {
		int n = a.size();
		for (int i = 0; i < pow(3ll, n - 1); i++) {
			int cur = a[0];
			int state = i;
			for (int j = 0; j < (n - 1); j++) {
				if (state % 3 == 0) {
					cur += a[j + 1];
				} else if (state % 3 == 1) {
					cur *= a[j + 1];
				} else {
					string cur_str = to_string(cur);
					string next_str = to_string(a[j + 1]);
					string new_str = cur_str + next_str;
					cur = stoll(new_str);
				}
				state /= 3;
			}
			if (cur == res) {
				return true;
			}
		}
		return false;
	};

	string line;
	int ans = 0;
	while (getline(cin, line)) {
        vector<int> row;
        stringstream ss(line);
        int number;
        while (ss >> number) {
            row.push_back(number);
        }
		int res = row[0];
		row.erase(row.begin());
		if (g(row, res)) {
			ans += res;
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