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

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void solve() {
    int ans = 0;
    int n = 140;
    vector<string> a(n);
    for (auto &row : a) {
        cin >> row;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'X') {
                for (int k = 0; k < 8; k++) {
                    string cur = "X";
                    int x = i, y = j;
                    for (int l = 0; l < 3; l++) {
                        x += dx[k];
                        y += dy[k];
                        if (x >= 0 and x < n and y >= 0 and y < n) {
                            cur += a[x][y];
                        }
                    }
                    if (cur == "XMAS") {
                        ans++;
                    }
                }
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