/*
【模板名】Dijkstra（非负边最短路）
页眉：模块名=最短路 | 页码=____ | 触发词=非负边/最短路
题面触发词：边权非负最短路
适用数据范围：n≤2e5, m≤2e5
时间复杂度：O(m log n)
空间复杂度：O(n+m)
你只需要改这里：
- 是否有向
常见错误：
- 未使用 long long
最小样例：
输入:
3 3 1
1 2 2
2 3 3
1 3 10
输出:
0 2 5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int to;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    if (!(cin >> n >> m >> s)) return 0;
    // 改这里：起点 s
    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        // 无向图：双向加边，有向图则删掉一行
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    const ll INF = (1LL << 60);
    // dist 初始化为无穷大
    vector<ll> dist(n + 1, INF);
    // 小根堆：每次取当前距离最小的点
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        // 过期的堆元素跳过
        if (d != dist[u]) continue;
        for (auto &e : g[u]) {
            // 松弛操作
            if (dist[e.to] > dist[u] + e.w) {
                dist[e.to] = dist[u] + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        // 改这里：不可达时输出什么
        cout << (dist[i] >= INF/2 ? -1 : dist[i]);
    }
    cout << "\n";
    return 0;
}
