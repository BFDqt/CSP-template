/*
【模板名】字符串哈希（滚动哈希）
页眉：模块名=字符串 | 页码=____ | 触发词=子串相等/哈希
题面触发词：比较子串相等
适用数据范围：|s|≤1e6, q≤2e5
时间复杂度：预处理 O(n)，查询 O(1)
空间复杂度：O(n)
你只需要改这里：
- base/mod
常见错误：
- 溢出未取模
最小样例：
输入:
abcab
2
1 3
3 5
输出:
294
588
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll MOD = 1000000007LL;
    const ll BASE = 911382323LL;

    string s;
    if (!(cin >> s)) return 0;
    int n = (int)s.size();
    vector<ll> h(n + 1, 0), p(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * BASE + s[i - 1]) % MOD;
        p[i] = (p[i - 1] * BASE) % MOD;
    }
    auto get = [&](int l, int r) {
        ll res = (h[r] - h[l - 1] * p[r - l + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << get(l, r) << "\n";
    }
    return 0;
}
