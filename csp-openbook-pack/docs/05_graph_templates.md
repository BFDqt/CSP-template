# 05 图论模板
页眉：模块名=图论模板 | 页码=____ | 触发词=最短路/连通/拓扑
翻页索引：
- 邻接表
- BFS / DFS
- 网格 BFS
- Dijkstra
- Floyd
- 并查集
- Kruskal
- 拓扑排序
- 连通块

## 邻接表（基础）
```cpp
/*
【模板名】邻接表
页眉：模块名=图论 | 页码=____ | 触发词=图/边/点
题面触发词：无向图、有向图、边列表
适用数据范围：n≤2e5, m≤2e5
时间复杂度：建图 O(n+m)
空间复杂度：O(n+m)
你只需要改这里：
- 是否无向（双向加边）
- 是否带权
常见错误：
- 忘记双向加边
- 节点从 1 开始
最小样例：
输入:
3 2
1 2
2 3
输出:
OK
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

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
    }
    cout << "OK\n";
    return 0;
}
```

## BFS（图）
{{include:templates/cpp/bfs_graph.cpp}}

## DFS（图）
```cpp
/*
【模板名】DFS（连通块/遍历）
页眉：模块名=图论 | 页码=____ | 触发词=连通块/遍历
题面触发词：连通块、遍历、可达性
适用数据范围：n≤2e5, m≤2e5
时间复杂度：O(n+m)
空间复杂度：O(n+m)
你只需要改这里：
- 递归或栈实现
- 访问时处理逻辑
常见错误：
- 递归过深
- 忘记标记 visited
最小样例：
输入:
3 2
1 2
2 3
输出:
1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> vis;

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) if (!vis[v]) dfs(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    g.assign(n + 1, {});
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int comps = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            comps++;
        }
    }
    cout << comps << "\n";
    return 0;
}
```

## 网格 BFS
{{include:templates/cpp/bfs_grid.cpp}}

## Dijkstra
{{include:templates/cpp/dijkstra.cpp}}

## Floyd
{{include:templates/cpp/floyd.cpp}}

## 并查集
{{include:templates/cpp/dsu.cpp}}

## Kruskal
{{include:templates/cpp/kruskal.cpp}}

## 拓扑排序
{{include:templates/cpp/topo_sort.cpp}}

## 连通块（BFS 版）
```cpp
/*
【模板名】连通块（BFS）
页眉：模块名=图论 | 页码=____ | 触发词=连通块
题面触发词：连通块、可达性、区域数量
适用数据范围：n≤2e5, m≤2e5
时间复杂度：O(n+m)
空间复杂度：O(n+m)
你只需要改这里：
- 图是否无向
- 输出需求
常见错误：
- 访问标记重复
最小样例：
输入:
4 2
1 2
3 4
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    int comps = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        comps++;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    cout << comps << "\n";
    return 0;
}
```
