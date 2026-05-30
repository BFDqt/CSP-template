/*
【模板名】线段树（区间加/区间和）
页眉：模块名=线段树 | 页码=____ | 触发词=区间修改/区间查询
题面触发词：区间修改、区间查询
适用数据范围：n≤2e5
时间复杂度：O(log n)
空间复杂度：O(n)
你只需要改这里：
- 操作类型
常见错误：
- lazy 下推遗漏
最小样例：
输入:
5 3
1 2 3 4 5
2 1 3
1 2 4 2
2 1 3
输出:
6
10
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    struct Node { ll sum = 0, lazy = 0; };
    int n;
    vector<Node> st;
    SegTree(int n = 0) { init(n); }
    void init(int n_) { n = n_; st.assign(4 * n + 4, {}); }

    void build(vector<ll> &a, int p, int l, int r) {
        if (l == r) { st[p].sum = a[l]; return; }
        int m = (l + r) / 2;
        // 递归建树
        build(a, p * 2, l, m);
        build(a, p * 2 + 1, m + 1, r);
        st[p].sum = st[p * 2].sum + st[p * 2 + 1].sum;
    }

    void apply(int p, int l, int r, ll val) {
        // 把懒标记作用在节点上
        st[p].sum += val * (r - l + 1);
        st[p].lazy += val;
    }

    void push(int p, int l, int r) {
        if (st[p].lazy == 0 || l == r) return;
        int m = (l + r) / 2;
        // 把懒标记下推给子节点
        apply(p * 2, l, m, st[p].lazy);
        apply(p * 2 + 1, m + 1, r, st[p].lazy);
        st[p].lazy = 0;
    }

    void rangeAdd(int p, int l, int r, int ql, int qr, ll val) {
        if (ql <= l && r <= qr) { apply(p, l, r, val); return; }
        push(p, l, r);
        int m = (l + r) / 2;
        if (ql <= m) rangeAdd(p * 2, l, m, ql, qr, val);
        if (qr > m) rangeAdd(p * 2 + 1, m + 1, r, ql, qr, val);
        // 回溯更新父节点
        st[p].sum = st[p * 2].sum + st[p * 2 + 1].sum;
    }

    ll rangeSum(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return st[p].sum;
        push(p, l, r);
        int m = (l + r) / 2;
        ll res = 0;
        if (ql <= m) res += rangeSum(p * 2, l, m, ql, qr);
        if (qr > m) res += rangeSum(p * 2 + 1, m + 1, r, ql, qr);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    // 改这里：数组长度与操作数
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    SegTree st(n);
    st.build(a, 1, 1, n);

    while (q--) {
        int op; cin >> op;
        // 改这里：操作类型定义
        if (op == 1) {
            int l, r; ll v; cin >> l >> r >> v;
            // 区间加
            st.rangeAdd(1, 1, n, l, r, v);
        } else {
            int l, r; cin >> l >> r;
            // 区间和
            cout << st.rangeSum(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}
