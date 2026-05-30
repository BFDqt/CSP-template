/*
【模板名】并查集（DSU）
页眉：模块名=并查集 | 页码=____ | 触发词=连通性/合并
题面触发词：连通性、合并集合
适用数据范围：n≤2e5
时间复杂度：近似 O(1)
空间复杂度：O(n)
你只需要改这里：
- 操作类型
常见错误：
- 忘记路径压缩
最小样例：
输入:
5 3
1 1 2
1 2 3
2 1 3
输出:
YES
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p, r;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        p.resize(n + 1);
        r.assign(n + 1, 0);
        iota(p.begin(), p.end(), 0);
    }
    // 路径压缩
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    // 按秩合并
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    // 改这里：操作类型含义（1 合并 / 2 查询）
    DSU dsu(n);
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        // op=1 合并，op=2 查询
        if (op == 1) dsu.unite(a, b);
        else cout << (dsu.find(a) == dsu.find(b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
