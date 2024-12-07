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
	int n = 130, m;
	vector<string> a(n);
	for (auto &s : a) {
		cin >> s;
		m = s.size();
	}

	int r, c;
	char dir = '^';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '^') {
				r = i, c = j;
				a[i][j] = '.';
				break;
			}
		}
	}

	auto g = [&]() {
		int x = r, y = c;
		dir = '^';
		vector<vector<map<char, bool>>> visited(n, vector<map<char, bool>>(m));
		while (true) {
			if (visited[x][y][dir]) {
				return 1;
			}
			visited[x][y][dir] = true;
			int x1, y1;
			if (dir == '<') {
				x1 = x;
				y1 = y - 1;
			} else if (dir == '^') {
				x1 = x - 1;
				y1 = y;
			} else if (dir == '>') {
				x1 = x;
				y1 = y + 1;
			} else {
				x1 = x + 1;
				y1 = y;
			}

			if (x1 < 0 or x1 == n or y1 < 0 or y1 == m) {
				break;
			}

			if (a[x1][y1] == '#') {
				if (dir == '<') {
					dir = '^';
				} else if (dir == '^') {
					dir = '>';
				} else if (dir == '>') {
					dir = '.';
				} else {
					dir = '<';
				}
			} else {
				x = x1;
				y = y1;
			}
		}
		return 0;
	};

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.' and (i != r or j != c)) {
				a[i][j] = '#';
				ans += g();
				a[i][j] = '.';
			}
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