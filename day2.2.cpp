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
    auto ok = [&](vector<int> &row) {
        if (is_sorted(row.begin(), row.end()) or is_sorted(row.rbegin(), row.rend())) {
            int n = row.size();
            for (int i = 0; i < n - 1; i++) {
                if (abs(row[i] - row[i + 1]) > 3 or abs(row[i] - row[i + 1]) < 1) {
                    return false;
                } 
            }
            return true;
        }
        return false;
    };

    auto remove = [&](vector<int> &row) {
        int n = row.size();
        for (int i = 0; i < n; i++) {
            vector<int> a;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    a.push_back(row[j]);
                }
            }
            if (ok(a)) {
                return true;
            }
        }
        return false;
    };

    int ans = 0;
    string line;
    while (getline(std::cin, line)) {
        vector<int> row;
        stringstream ss(line);
        int number;
        while (ss >> number) {
            row.push_back(number);
        }

        if (ok(row) or remove(row)) {
            ans++;
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