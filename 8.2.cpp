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

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void solve() {
	int n = 50, m;
	vector<string> a(n);
	for (auto &s : a) {
		cin >> s;
		m =s.size();
	}

	map<char, vector<array<int, 2>>> mp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '.') {
				mp[a[i][j]].push_back({i, j});
			}
		}
	}

	vector<vector<bool>> f(n, vector<bool>(m));

	int ans = 0;
	for (auto [k, v] : mp) {
		int sz = v.size();
		for (int i = 0; i < sz - 1; i++) {
			for (int j = i; j < sz; j++) {
				if (i != j) {
					auto p = v[i];
					auto q = v[j];
					auto new_p = p;
					auto new_q = q;
					if (p[1] > q[1]) {
						int dy = p[1] - q[1];
						int dx = q[0] - p[0];
						new_q[1] -= dy;
						new_q[0] += dx;
						new_p[1] += dy;
						new_p[0] -= dx;
						while (new_p[0] >= 0 and new_p[0] < n and new_p[1] < m and new_p[1] >= 0) {
							f[new_p[0]][new_p[1]] = true;
							new_p[1] += dy;
							new_p[0] -= dx;
						}
						while (new_q[0] >= 0 and new_q[0] < n and new_q[1] < m and new_q[1] >= 0) {
							f[new_q[0]][new_q[1]] = true;
							new_q[1] -= dy;
							new_q[0] += dx;
						}
					} else {
						int dy = q[1] - p[1];
						int dx = q[0] - p[0];
						new_q[1] += dy;
						new_q[0] += dx;
						new_p[1] -= dy;
						new_p[0] -= dx;

						while (new_p[0] >= 0 and new_p[0] < n and new_p[1] < m and new_p[1] >= 0) {
							f[new_p[0]][new_p[1]] = true;
							new_p[1] -= dy;
							new_p[0] -= dx;
						}
						while (new_q[0] >= 0 and new_q[0] < n and new_q[1] < m and new_q[1] >= 0) {
							f[new_q[0]][new_q[1]] = true;
							new_q[1] += dy;
							new_q[0] += dx;
						}
					}
				}
			}
			cout << '\n';
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '.') {
				f[i][j] = true;
			}
			if (f[i][j]) {
				ans++;
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