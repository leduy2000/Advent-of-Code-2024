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
	int n = 8;
    vector<int> a(n);
    map<int, int> mp;
    for (int &x : a) {
        cin >> x;
        mp[x]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= 75; i++) {
        map<int, int> cur_mp; 
        for (auto [k, v] : mp) {
            string s = to_string(k);
            if (k == 0) {
                cur_mp[1] += mp[k];
            } else if (s.size() % 2 == 0) {
                string p, q;
                for (int j = 0; j < s.size() / 2; j++) {
                    p += s[j];
                }
                for (int j = s.size() / 2; j < s.size(); j++) {
                    q += s[j];
                }
                cur_mp[stoll(p)] += mp[k];
                cur_mp[stoll(q)] += mp[k];
            } else {
                cur_mp[k * 2024] += mp[k];
            }
        }
        mp = cur_mp;
    }

    int sum = 0;
    for (auto [k, v] : mp) {
        sum += v;
    }
    cout << sum << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}