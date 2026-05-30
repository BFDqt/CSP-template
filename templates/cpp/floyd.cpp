/*
【模板名】Floyd（全点对最短路）
页眉：模块名=最短路 | 页码=____ | 触发词=全点对/小 n
题面触发词：所有点对最短路、n 小
适用数据范围：n≤500
时间复杂度：O(n^3)
空间复杂度：O(n^2)
你只需要改这里：
- 输出格式
常见错误：
- INF 溢出
最小样例：
输入:
3 3
1 2 2
2 3 3
1 3 10
输出:
0 2 5
2 0 3
5 3 0
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    // 改这里：节点数量和边数量
    const ll INF = (1LL << 60);
    // dist 初始化为 INF，自己到自己为 0
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        // 可能有重边，取最小
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    // 三重循环：枚举中转点 k
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) cout << " ";
            // 改这里：不可达的输出
            cout << dist[i][j];
        }
        cout << "\n";
    }
    return 0;
}
