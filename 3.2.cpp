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

pair<int, int> extractNumbersFromSingleMul(const string& mulString) {
    regex pattern(R"(^mul\((\d+),(\d+)\)$)");
    smatch match;

    if (regex_match(mulString, match, pattern)) {
        int num1 = stoi(match[1].str());
        int num2 = stoi(match[2].str());
        return {num1, num2};
    } else {
        throw invalid_argument("Invalid format: " + mulString);
    }
}

vector<string> extractPatterns(const string& line) {
    regex pattern(R"(mul\(\d+,\d+\)|do\(\)|don't\(\))");
    sregex_iterator begin(line.begin(), line.end(), pattern);
    sregex_iterator end;

    vector<string> results;
    for (auto it = begin; it != end; ++it) {
        results.push_back(it->str());
    }
    return results;
}

bool startsWithMul(const string& str) {
    return str.rfind("mul(", 0) == 0;
}

void solve() {
    int ans = 0;
    string line;
    bool bruh = false;
    while (getline(cin, line)) {
        vector<string> patterns = extractPatterns(line);
        if (!bruh) {
            patterns.insert(patterns.begin(), "do()");
            bruh = true;
        }
        
        int n = patterns.size();
        for (int i = 0; i < n; i++) {
            if (patterns[i] == "do()") {
                for (int j = i + 1; j < n; j++) {
                    if (!startsWithMul(patterns[j])) {
                        break;
                    }
                    auto [u, v] = extractNumbersFromSingleMul(patterns[j]);
                    ans += u * v;
                    i = j;
                }
            }
        }
    }
    cout << ans << '\n';
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    solve();
    return 0;
}