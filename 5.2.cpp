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
	map<int, vector<int>> right;
	for (int i = 1; i <= 1176; i++) {
		int u, v;
		cin >> u >> v;
		right[u].push_back(v);
	}

	auto cmp = [&](int u, int v) {
		if (find(right[v].begin(), right[v].end(), u) != right[v].end()) {
			return false;
		}
		return true;
	};

	auto get_mid = [&](vector<int> &row) -> int {
		if (row.empty()) {
			return 0;
		}
		int n = row.size();
		auto row_copy = row;
		sort(row_copy.begin(), row_copy.end(), cmp);
		if (row_copy == row) {
			return 0;
		}
		return row_copy[(n - 1) / 2];
	};

	int ans = 0;

	string line;
	while (getline(std::cin, line)) {
        vector<int> row;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            row.push_back(num);
        }
       	ans += get_mid(row);
    }

    cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}