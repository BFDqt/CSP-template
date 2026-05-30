# 目录

- 00 考场策略
  - 4 小时考试流程表（放首页）
  - CSP 形态
  - 目标分层
  - 240 分钟时间规划
  - 做题顺序建议
  - 卡住转移规则（保命）
- 02 题型路由表（看到就选模板）
  - 关键词 → 模板（页码留空）
  - 数据范围 → 复杂度
- 10 部分分攻略（重点）
  - 数据范围 → 暴力策略
  - Q4/Q5 不会正解时拿 20–50 分流程
  - 子集枚举
  - 全排列
  - 枚举区间
  - 暴力 DFS（例：枚举选或不选）
  - 每询问暴力模拟（q 小）
  - 每询问 BFS（图小）
  - 不要空题
- 11 调试与检查清单
  - CE 编译错误检查
  - WA 排查表
  - TLE 排查表
  - RE 排查表
  - 交题前 30 秒检查表

\newpage

# 00 考场策略
页眉：模块名=考场策略 | 页码=____ | 触发词=时间规划/得分目标/做题顺序
翻页索引：
- 4 小时考试流程表
- CSP 形态与得分目标
- 240 分钟时间规划
- 做题顺序与卡住转移

## 4 小时考试流程表（放首页）
| 时间段 | 目标 | 行动 |
|---|---|---|
| 0–10 分钟 | 扫题 | 读完 5 题题意与数据范围，标注可拿分题 |
| 10–40 分钟 | Q1 | 直接做完并通过样例 |
| 40–80 分钟 | Q2 | 稳定得分，尽量一次过 |
| 80–170 分钟 | Q3 | 重点，必要时先拿部分分 |
| 170–230 分钟 | Q4/Q5 | 找小数据部分分或简化模型 |
| 230–240 分钟 | 全局检查 | 输出格式/边界/提交顺序 |

## CSP 形态
- 4 小时，5 题，每题 100 分，总分 500。
- 难度递增，黑盒测试。
- 多次提交取最高，但每题提交次数有限。

## 目标分层
- 保底 100：Q1。
- 基础 200：Q1 + Q2。
- 进阶 250–320：Q1 + Q2 + Q3 部分/满分。
- 冲高分：Q4/Q5 部分分或正解。

## 240 分钟时间规划
- 0–10 分钟：扫题，写下每题数据范围与关键词。
- 10–40 分钟：Q1，直接实现。
- 40–80 分钟：Q2，优先正确性。
- 80–170 分钟：Q3，大模拟或中等算法。
- 170–230 分钟：Q4/Q5，拿部分分。
- 230–240 分钟：提交与检查。

## 做题顺序建议
- 通常：Q1 → Q2 → Q3 → Q4/Q5。
- 若 Q3 卡住：先做 Q4/Q5 的小数据部分分，避免空题。
- 能交就交：先交能过样例和小数据的版本，再做优化。

## 卡住转移规则（保命）
- 10 分钟内想不清思路：先做下一题。
- 代码超过 200 行仍未通样例：先切部分分方案。
- Q4/Q5 只要能过小数据，先拿分再说。

\newpage

# 02 题型路由表（看到就选模板）
页眉：模块名=题型路由 | 页码=____ | 触发词=关键词/模板选择
翻页索引：
- 关键词 → 模板
- 数据范围 → 复杂度

## 关键词 → 模板（页码留空）
| 题面触发词 | 立刻想到 | 页码 | 备注 |
|---|---|---|---|
| 区间和/子矩阵和 | 前缀和 1D/2D | ____ | O(1) 查询 |
| 多次区间加/最后查询 | 差分 1D/2D | ____ | 先改后算 |
| 连续子段/最长/最短满足条件 | 双指针/滑动窗口 | ____ | 单调性 |
| 最大值最小/最小值最大/答案单调 | 二分答案 | ____ | check(mid) |
| 网格最短步数/每步代价相同 | BFS（网格） | ____ | 4/8 方向 |
| 边权非负最短路 | Dijkstra | ____ | 堆优化 |
| 所有点对最短路且 n 小 | Floyd | ____ | n≤500 |
| 连通性/合并集合 | 并查集 | ____ | DSU |
| 依赖/先修/拓扑顺序 | 拓扑排序 | ____ | Kahn |
| 区间修改/区间查询 | 树状数组/线段树 | ____ | log n |
| 容量/预算/选择物品 | 背包 | ____ | DP |
| n≤20 | 状压/子集枚举 | ____ | 2^n |
| 命令/用户/文件/权限/状态/规则 | 大模拟 | ____ | 读题表 |
| 字符串匹配 | KMP/哈希 | ____ | 线性 |
| 频繁查询最值 | ST 表 | ____ | RMQ |

## 数据范围 → 复杂度
| 数据范围 | 可尝试复杂度 | 常见模板 |
|---|---|---|
| n ≤ 20 | O(2^n) / O(n·2^n) | 子集枚举、状压 DP |
| n ≤ 100 | O(n^3) | Floyd、区间 DP |
| n ≤ 1000 | O(n^2) | 双重循环、DP |
| n ≤ 1e5 | O(n log n) | 排序、树状数组、线段树 |
| q 小 | 每次查询暴力 | 逐次模拟 |

\newpage

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
```cpp
/*
【模板名】子集枚举（位运算）
页眉：模块名=暴力 | 页码=____ | 触发词=子集/状压
题面触发词：n≤20，枚举子集
适用数据范围：n≤20
时间复杂度：O(n*2^n)
空间复杂度：O(1)
你只需要改这里：
- 统计逻辑
常见错误：
- 位运算顺序
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    // 改这里：n<=20 才能枚举
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll best = 0;
    int N = 1 << n;
    // mask 的每一位表示是否选第 i 个元素
    for (int mask = 0; mask < N; mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += a[i];
        }
        best = max(best, sum);
    }
    // 改这里：输出最大值/计数/是否存在
    cout << best << "\n";
    return 0;
}

```

## 全排列
```cpp
/*
【模板名】全排列枚举
页眉：模块名=暴力 | 页码=____ | 触发词=全排列/n≤10
题面触发词：n≤10，枚举全排列
适用数据范围：n≤10
时间复杂度：O(n! * n)
空间复杂度：O(n)
你只需要改这里：
- 检查逻辑
常见错误：
- 忘记初始化序列
最小样例：
输入:
3
输出:
6
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    // 改这里：n<=10 才能枚举全排列
    vector<int> p(n);
    // 从 1..n 的初始排列开始
    iota(p.begin(), p.end(), 1);
    int cnt = 0;
    do {
        cnt++;
        // 改这里：检查当前排列
    } while (next_permutation(p.begin(), p.end()));
    cout << cnt << "\n";
    return 0;
}

```

## 枚举区间
```cpp
/*
【模板名】枚举区间（O(n^2)）
页眉：模块名=暴力 | 页码=____ | 触发词=枚举区间
题面触发词：n≤2000，区间枚举
适用数据范围：n≤2000
时间复杂度：O(n^2)
空间复杂度：O(1)
你只需要改这里：
- 统计逻辑
常见错误：
- 双重循环边界
最小样例：
输入:
4
1 -2 3 4
输出:
7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    // 改这里：n<=2000 才能 O(n^2)
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll best = LLONG_MIN / 4;
    // 枚举所有区间 [l,r]
    for (int l = 1; l <= n; l++) {
        ll sum = 0;
        for (int r = l; r <= n; r++) {
            sum += a[r];
            best = max(best, sum);
        }
    }
    // 改这里：输出最大值/最小值/计数
    cout << best << "\n";
    return 0;
}

```

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

\newpage

# 11 调试与检查清单
页眉：模块名=调试检查 | 页码=____ | 触发词=WA/TLE/RE/CE
翻页索引：
- CE 编译错误
- WA 排查
- TLE 排查
- RE 排查
- 交题前 30 秒检查表

## CE 编译错误检查
- 缺少 `;` 或 `}`。
- 变量名拼写不一致。
- `vector` 未包含头文件（用 bits 可避免）。
- 模板尖括号写错。

## WA 排查表
- 输入是否读全（多行/空格/空行）。
- int 是否溢出（用 long long）。
- 0/1 下标是否混用。
- 排序比较器是否正确。
- 边界 n=0/1 是否处理。
- 多组数据是否清空容器。
- 输出格式是否多空格/少换行。

## TLE 排查表
- 复杂度是否超过数据范围。
- 是否可以前缀和/排序/二分替代。
- 是否重复计算。
- map/unordered_map 是否可替换。

## RE 排查表
- 数组越界。
- 空容器 `top()/front()`。
- 递归爆栈。
- 除以 0。

## 交题前 30 秒检查表
- 是否使用 `ios::sync_with_stdio(false); cin.tie(nullptr);`。
- 是否所有输出有换行。
- 是否处理最小输入。
- 是否提交的是最新版本。
