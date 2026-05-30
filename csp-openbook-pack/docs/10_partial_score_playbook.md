# 10 部分分攻略（重点）
页眉：模块名=部分分攻略 | 页码=____ | 触发词=小数据/暴力/子任务
翻页索引：
- 数据范围 → 暴力策略
- Q4/Q5 20–50 分流程
- 暴力模板合集
- 不要空题

## 数据范围 → 暴力策略
| 数据范围 | 暴力思路 | 典型模板 |
|---|---|---|
| n ≤ 10 | 全排列/DFS | 暴力排列 |
| n ≤ 20 | 子集枚举/状压 | 子集枚举 |
| n ≤ 100 | O(n^3) | Floyd/三重循环 |
| n ≤ 1000 | O(n^2) | 双重循环/DP |
| q 小 | 每次查询暴力 | 每询问模拟 |
| 图小 | Floyd | 全点对最短路 |

## Q4/Q5 不会正解时拿 20–50 分流程
1. 找测试点约束（题面子任务）。
2. 写最小正确暴力（哪怕超慢）。
3. 先提交拿分。
4. 再局部优化（剪枝/预处理/缓存）。

## 子集枚举
{{include:templates/cpp/brute_force_subsets.cpp}}

## 全排列
{{include:templates/cpp/brute_force_permutation.cpp}}

## 枚举区间
{{include:templates/cpp/brute_force_intervals.cpp}}

## 暴力 DFS（例：枚举选或不选）
```cpp
/*
【模板名】暴力 DFS（选/不选）
页眉：模块名=部分分 | 页码=____ | 触发词=暴力/DFS
题面触发词：小 n、需要枚举组合
适用数据范围：n≤20
时间复杂度：O(2^n)
空间复杂度：O(n)
你只需要改这里：
- 剪枝条件
- 计分逻辑
常见错误：
- 忘记回溯
最小样例：
输入:
3
1 2 3
输出:
6
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll best = 0;
vector<ll> a;

void dfs(int idx, ll sum) {
    if (idx == (int)a.size()) {
        best = max(best, sum);
        return;
    }
    dfs(idx + 1, sum);          // 不选
    dfs(idx + 1, sum + a[idx]); // 选
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    dfs(0, 0);
    cout << best << "\n";
    return 0;
}
```

## 每询问暴力模拟（q 小）
```cpp
/*
【模板名】每询问暴力模拟
页眉：模块名=部分分 | 页码=____ | 触发词=q 小/逐次模拟
题面触发词：q 小、每次查询独立
适用数据范围：n≤2e5, q≤2e3
时间复杂度：O(n*q)
空间复杂度：O(n)
你只需要改这里：
- 查询逻辑
常见错误：
- 重复清空中间变量
最小样例：
输入:
5 2
1 2 3 4 5
1 3
2 5
输出:
6
14
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        int l, r; cin >> l >> r;
        ll sum = 0;
        for (int i = l; i <= r; i++) sum += a[i];
        cout << sum << "\n";
    }
    return 0;
}
```

## 每询问 BFS（图小）
```cpp
/*
【模板名】每询问 BFS
页眉：模块名=部分分 | 页码=____ | 触发词=图小/多次查询
题面触发词：多次路径查询且图小
适用数据范围：n≤2000, q≤200
时间复杂度：O(q*(n+m))
空间复杂度：O(n+m)
你只需要改这里：
- 目标条件
常见错误：
- 忘记清空队列/距离数组
最小样例：
输入:
3 2 2
1 2
2 3
1 3
2 1
输出:
2
1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while (q--) {
        int s, t; cin >> s >> t;
        vector<int> dist(n + 1, -1);
        queue<int> qu;
        qu.push(s);
        dist[s] = 0;
        while (!qu.empty()) {
            int u = qu.front(); qu.pop();
            for (int v : g[u]) if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
        cout << dist[t] << "\n";
    }
    return 0;
}
```

## 不要空题
- 能过样例的暴力也要先交。
- 小数据能拿 20–50 分，别放弃。
