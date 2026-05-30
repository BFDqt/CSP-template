/*
【模板名】树状数组（单点加/前缀和）
页眉：模块名=树状数组 | 页码=____ | 触发词=区间和/单点加
题面触发词：单点修改、区间查询
适用数据范围：n≤2e5
时间复杂度：O(log n)
空间复杂度：O(n)
你只需要改这里：
- 操作类型
常见错误：
- 下标从 1 开始
最小样例：
输入:
5 3
1 2 3 4 5
2 1 3
1 2 5
2 1 3
输出:
6
11
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int n = 0) { init(n); }
    void init(int n_) { n = n_; bit.assign(n + 1, 0); }
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    ll sumPrefix(int idx) {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    ll rangeSum(int l, int r) { return sumPrefix(r) - sumPrefix(l - 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    Fenwick fw(n);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        fw.add(i, x);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int idx; ll delta; cin >> idx >> delta;
            fw.add(idx, delta);
        } else {
            int l, r; cin >> l >> r;
            cout << fw.rangeSum(l, r) << "\n";
        }
    }
    return 0;
}
