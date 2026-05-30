/*
【模板名】Kruskal（最小生成树）
页眉：模块名=最小生成树 | 页码=____ | 触发词=最小生成树
题面触发词：最小生成树、连通最小代价
适用数据范围：n≤2e5, m≤2e5
时间复杂度：O(m log m)
空间复杂度：O(n+m)
你只需要改这里：
- 是否无向
常见错误：
- 图不连通
最小样例：
输入:
3 3
1 2 1
2 3 2
1 3 10
输出:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p, r;
    DSU(int n = 0) { init(n); }
    void init(int n) { p.resize(n + 1); r.assign(n + 1, 0); iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll total = 0;
    int used = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
            used++;
        }
    }
    if (used != n - 1) cout << -1 << "\n";
    else cout << total << "\n";
    return 0;
}
