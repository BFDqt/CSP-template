/*
【模板名】图 BFS（最短路）
页眉：模块名=BFS | 页码=____ | 触发词=无权图/最短路
题面触发词：无权图最短路、最少步数
适用数据范围：n≤2e5, m≤2e5
时间复杂度：O(n+m)
空间复杂度：O(n+m)
你只需要改这里：
- 起点与输出
常见错误：
- 忘记初始化 dist
最小样例：
输入:
4 3 1
1 2
2 3
3 4
输出:
0 1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    if (!(cin >> n >> m >> s)) return 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << dist[i];
    }
    cout << "\n";
    return 0;
}
