/*
【模板名】拓扑排序（Kahn）
页眉：模块名=拓扑排序 | 页码=____ | 触发词=依赖/先修
题面触发词：依赖关系、先修顺序
适用数据范围：n≤2e5, m≤2e5
时间复杂度：O(n+m)
空间复杂度：O(n+m)
你只需要改这里：
- 输出格式
常见错误：
- 有环时未判断
最小样例：
输入:
3 2
1 2
2 3
输出:
1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    // 改这里：读入依赖边（u -> v）
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        // u -> v
        g[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    // 入度为 0 的点先入队
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    // 有环时无法排出全部点
    if ((int)order.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    // 改这里：输出拓扑序或其他格式
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << order[i];
    }
    cout << "\n";
    return 0;
}
