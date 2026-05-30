# 目录

- 00 考场策略
  - 4 小时考试流程表（放首页）
  - CSP 形态
  - 目标分层
  - 240 分钟时间规划
  - 做题顺序建议
  - 卡住转移规则（保命）
- 01 C++ 生存手册
  - C++17 最小程序
  - 输入输出（基础）
  - 卡常快读快写
  - getline 与 cin 混用
  - 字符串读写常见坑
  - stringstream 模板
  - STL 容器速查（什么时候用/怎么声明/怎么遍历/怎么增删查）
  - 常见编译错误（CE）
  - 常见运行错误（RE）
  - 常见 WA 原因
  - 容器示例模板
- 02 题型路由表（看到就选模板）
  - 关键词 → 模板（页码留空）
  - 数据范围 → 复杂度
- 03 Q1/Q2 基础模板
  - 计数
  - 排序
  - 前缀和 1D
  - 前缀和 2D
  - 差分 1D
  - 差分 2D
  - 双指针 / 滑动窗口
  - 二分
  - 简单贪心（区间选取最多）
  - 简单 BFS（图）
  - 简单 DP（方案数）
  - 日期时间（日期差）
  - 坐标压缩
- 04 Q3 大模拟（重点）
  - 大模拟读题表格（先填这个再写代码）
  - 大模拟代码骨架
  - 命令解析模板（getline + stringstream）
  - 状态机模板
  - 事件队列模板（按时间或优先级处理）
  - map<string, object> 管理模板
  - 日期时间转换模板（字符串 → 天数）
  - 权限/文件系统/用户系统简版（示意）
  - 先拿部分分的简化策略
  - 几百行代码不崩的命名与调试
- 05 图论模板
  - 邻接表（基础）
  - BFS（图）
  - DFS（图）
  - 网格 BFS
  - Dijkstra
  - Floyd
  - 并查集
  - Kruskal
  - 拓扑排序
  - 连通块（BFS 版）
- 06 DP 模板
  - 线性 DP（最大连续子段和）
  - 0/1 背包
  - 完全背包
  - 多重背包（基础版：二进制拆分）
  - 区间 DP
  - 状压 DP
  - 树形 DP（最大独立集简版）
  - LIS（O(n log n)）
- 07 数据结构模板
  - 树状数组（Fenwick）
  - 线段树（区间和 + 区间加）
  - 单调栈（求每个元素左侧更小）
  - 单调队列（滑动窗口最大值）
  - Sparse Table（RMQ 最小值）
  - 堆（priority_queue）
  - set 的 lower_bound/upper_bound
  - 什么时候用 set / map / priority_queue
- 08 数学模板
  - gcd/lcm/快速幂/组合数
  - 扩展 gcd
  - 埃氏筛（质数表）
  - 质因数分解
  - 前缀 gcd
  - 浮点比较
  - 分数比较（避免精度误差）
  - __int128 输入输出
- 09 字符串模板
  - 字符串遍历
  - split（按空格/分隔符）
  - replace（子串替换）
  - 大小写转换
  - KMP
  - 字符串哈希
  - trie（简版）
  - stringstream 解析混合字段
  - 多行输入处理
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
- 12 近年真题索引（人工补录）
  - 真题索引表（示例格式）
  - 题型统计（填空提示）
- 99 打印与总索引
  - 打印建议
  - 装订建议
  - 总索引（关键词 → 算法 → 页码）
- C++17 代码模板全集
  - base
  - bfs_graph
  - bfs_grid
  - big_sim_command_parser
  - big_sim_state_machine
  - binary_search
  - bitmask_dp
  - brute_force_intervals
  - brute_force_permutation
  - brute_force_subsets
  - difference_1d
  - difference_2d
  - dijkstra
  - dsu
  - fast_io
  - fenwick
  - floyd
  - gcd_fastpow_comb
  - interval_dp
  - kmp
  - knapsack_01
  - knapsack_complete
  - kruskal
  - prefix_sum_1d
  - prefix_sum_2d
  - segment_tree
  - string_hash
  - stringstream_parser
  - topo_sort
  - vector_map_set

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

# 01 C++ 生存手册
页眉：模块名=C++ 生存 | 页码=____ | 触发词=输入输出/STL/常见错误
翻页索引：
- C++17 最小程序
- 输入输出与快读快写
- 字符串与 stringstream
- STL 容器速查
- 常见编译/运行错误

## C++17 最小程序
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: 读入、计算、输出
    return 0;
}
```

## 输入输出（基础）
- 读整数/字符串：`cin >> x;`
- 输出换行：`cout << x << "\n";`
- 多组数据：`while (cin >> x) { ... }`

## 卡常快读快写
- 需要极限 IO 时，直接用模板：
```cpp
/*
【模板名】快读快写
页眉：模块名=基础模板 | 页码=____ | 触发词=大输入/卡常
题面触发词：输入很大、IO 成为瓶颈
适用数据范围：数据总量≥1e6
时间复杂度：O(n)
空间复杂度：O(1)
你只需要改这里：
- 读入类型与输出内容
常见错误：
- 忘记处理负数
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

struct FastScanner {
    static const int BUFSIZE = 1 << 20;
    int idx, size;
    char buf[BUFSIZE];
    FastScanner() : idx(0), size(0) {}

    inline char read() {
        if (idx >= size) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }

    bool nextLong(ll &out) {
        char c = read();
        if (!c) return false;
        while (c != '-' && (c < '0' || c > '9')) {
            c = read();
            if (!c) return false;
        }
        ll sign = 1;
        if (c == '-') { sign = -1; c = read(); }
        ll val = 0;
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = read();
        }
        out = val * sign;
        return true;
    }

    bool nextString(string &s) {
        char c = read();
        if (!c) return false;
        while (isspace((unsigned char)c)) {
            c = read();
            if (!c) return false;
        }
        s.clear();
        while (c && !isspace((unsigned char)c)) {
            s.push_back(c);
            c = read();
        }
        return true;
    }
};

struct FastOutput {
    static const int BUFSIZE = 1 << 20;
    int idx;
    char buf[BUFSIZE];
    FastOutput() : idx(0) {}
    ~FastOutput() { flush(); }

    void flush() {
        if (idx) {
            fwrite(buf, 1, idx, stdout);
            idx = 0;
        }
    }

    void pushChar(char c) {
        if (idx >= BUFSIZE) flush();
        buf[idx++] = c;
    }

    void writeLong(ll x, char end = '\n') {
        if (x == 0) {
            pushChar('0');
            pushChar(end);
            return;
        }
        if (x < 0) { pushChar('-'); x = -x; }
        char s[32];
        int n = 0;
        while (x > 0) { s[n++] = char('0' + x % 10); x /= 10; }
        for (int i = n - 1; i >= 0; i--) pushChar(s[i]);
        pushChar(end);
    }
};

int main() {
    FastScanner fs;
    FastOutput fo;

    ll n;
    if (!fs.nextLong(n)) return 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        fs.nextLong(x);
        sum += x;
    }
    fo.writeLong(sum);
    return 0;
}

```

## getline 与 cin 混用
- 先读完 `cin` 后加一行：`cin.ignore(numeric_limits<streamsize>::max(), '\n');`
- 再使用 `getline`。

## 字符串读写常见坑
- 空行：`getline` 可能读到空串。
- 末尾空格：`stringstream` 会自动忽略连续空格。
- 大小写：使用 `tolower/ toupper`。

## stringstream 模板
```cpp
/*
【模板名】getline + stringstream 解析
页眉：模块名=字符串 | 页码=____ | 触发词=含空格/整行解析
题面触发词：整行输入、含空格字段
适用数据范围：行数≤2e5
时间复杂度：O(总字符数)
空间复杂度：O(1)
你只需要改这里：
- 字段类型和处理逻辑
常见错误：
- 忘记读取上一行换行
最小样例：
输入:
2
hello 1
world 2
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line);

    int count_lines = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        string word;
        int num = 0;
        ss >> word >> num;
        if (!word.empty()) count_lines++;
    }
    cout << count_lines << "\n";
    return 0;
}

```

## STL 容器速查（什么时候用/怎么声明/怎么遍历/怎么增删查）
### vector
- 用途：顺序数组，可随机访问。
- 声明：`vector<ll> a(n, 0);`
- 遍历：`for (ll x : a) {}` 或下标。
- 增删：`push_back`、`pop_back`。

### map / unordered_map
- 用途：键值映射。`map` 有序，`unordered_map` 更快但不稳定。
- 声明：`map<string, ll> mp;`
- 遍历：`for (auto &kv : mp) {}`
- 增删查：`mp[key] = val; mp.erase(key); mp.count(key);`

### set / unordered_set
- 用途：去重、查找。
- 声明：`set<ll> s;`
- 遍历：`for (ll x : s) {}`
- 增删查：`insert`、`erase`、`count`。

### queue / stack / deque
- queue：先进先出，BFS。
- stack：后进先出，括号匹配/DFS。
- deque：双端队列，单调队列常用。

### priority_queue
- 大根堆：`priority_queue<ll> pq;`
- 小根堆：`priority_queue<ll, vector<ll>, greater<ll>> pq;`

### pair / tuple
- pair：`pair<ll,ll> p = {a,b};`
- tuple：`tuple<ll,ll,ll> t = {a,b,c};`

### lambda 排序
```cpp
sort(a.begin(), a.end(), [](const Node &x, const Node &y){
    return x.key < y.key;
});
```

### 二维数组 / vector
```cpp
vector<vector<ll>> a(n, vector<ll>(m, 0));
```

### long long / __int128
- 大整数：用 `__int128` 做中间计算。
- 输出需手写转换函数。

### double 精度
- 比较：`fabs(a - b) < 1e-9`。
- 输出：`cout << fixed << setprecision(6);`

## 常见编译错误（CE）
- 缺少 `;` 或 `}`。
- 变量名重复或未声明。
- 模板尖括号 `>>` 不匹配（老编译器）。

## 常见运行错误（RE）
- 数组越界。
- 空队列 `front()`。
- 递归太深导致栈溢出。
- 除以 0。

## 常见 WA 原因
- 下标从 0/1 混用。
- 多组数据未清空容器。
- 输出格式多空格/少换行。
- 溢出使用 int。

## 容器示例模板
```cpp
/*
【模板名】vector/map/set 速用
页眉：模块名=基础模板 | 页码=____ | 触发词=去重/统计/有序
题面触发词：去重、统计次数、有序输出
适用数据范围：n≤2e5
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 统计字段
- 输出格式
常见错误：
- map 遍历顺序误解
最小样例：
输入:
5
2 1 2 3 1
输出:
1 2
2 2
3 1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> cnt;
    for (ll x : a) cnt[x]++;

    for (auto &kv : cnt) {
        cout << kv.first << " " << kv.second << "\n";
    }
    return 0;
}

```

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

# 03 Q1/Q2 基础模板
页眉：模块名=Q1/Q2 基础 | 页码=____ | 触发词=计数/排序/前缀和/差分/双指针
翻页索引：
- 计数
- 排序
- 前缀和 1D/2D
- 差分 1D/2D
- 双指针/滑动窗口
- 二分
- 简单贪心
- 简单 BFS
- 简单 DP
- 日期时间
- 坐标压缩

## 计数
```cpp
/*
【模板名】计数/频率统计
页眉：模块名=计数 | 页码=____ | 触发词=统计/次数/频率
题面触发词：统计次数、频率、众数、出现几次
适用数据范围：n≤2e5
时间复杂度：O(n log n)（map） / O(n)（unordered_map）
空间复杂度：O(n)
你只需要改这里：
- 读入字段类型
- 输出格式
常见错误：
- 忘记清空 map
- 用 int 导致溢出
最小样例：
输入:
5
1 2 2 3 3
输出:
1 1
2 2
3 2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    map<ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cnt[x]++;
    }
    for (auto &kv : cnt) {
        cout << kv.first << " " << kv.second << "\n";
    }
    return 0;
}
```

## 排序
```cpp
/*
【模板名】排序与排名
页眉：模块名=排序 | 页码=____ | 触发词=排序/排名/最小/最大
题面触发词：排序、排名、最小/最大、字典序
适用数据范围：n≤1e6
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 排序关键字（升序/降序）
- 输出格式
常见错误：
- 忘记稳定性
- 比较器写反
最小样例：
输入:
5
3 1 4 1 5
输出:
1 1 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
```

## 前缀和 1D
```cpp
/*
【模板名】前缀和 1D
页眉：模块名=前缀和 | 页码=____ | 触发词=区间和/子段和
题面触发词：区间和、连续子段和
适用数据范围：n≤1e6, q≤1e6
时间复杂度：预处理 O(n)，查询 O(1)
空间复杂度：O(n)
你只需要改这里：
- 输入格式
- 查询输出
常见错误：
- 下标从 1 还是 0
最小样例：
输入:
5 3
1 2 3 4 5
1 3
2 5
4 4
输出:
6
14
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << pre[r] - pre[l - 1] << "\n";
    }
    return 0;
}

```

## 前缀和 2D
```cpp
/*
【模板名】前缀和 2D
页眉：模块名=前缀和 | 页码=____ | 触发词=子矩阵和
题面触发词：矩形区域和、子矩阵和
适用数据范围：n,m≤2000
时间复杂度：预处理 O(nm)，查询 O(1)
空间复杂度：O(nm)
你只需要改这里：
- 输入矩阵与查询
常见错误：
- 下标从 1 开始
最小样例：
输入:
2 2 2
1 2
3 4
1 1 2 2
1 2 2 2
输出:
10
6
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<ll>> pre(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll x; cin >> x;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x;
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
    return 0;
}

```

## 差分 1D
```cpp
/*
【模板名】差分 1D（区间加）
页眉：模块名=差分 | 页码=____ | 触发词=多次区间加
题面触发词：多次区间加、最后输出数组
适用数据范围：n≤1e6, q≤1e6
时间复杂度：O(n+q)
空间复杂度：O(n)
你只需要改这里：
- 更新规则
常见错误：
- r+1 越界
最小样例：
输入:
5 2
1 2 3 4 5
1 3 10
2 5 -2
输出:
11 10 11 2 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> a(n + 1), diff(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        diff[i] += a[i] - a[i - 1];
    }
    while (q--) {
        int l, r; ll v;
        cin >> l >> r >> v;
        diff[l] += v;
        diff[r + 1] -= v;
    }
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        if (i > 1) cout << " ";
        cout << diff[i];
    }
    cout << "\n";
    return 0;
}

```

## 差分 2D
```cpp
/*
【模板名】差分 2D（子矩阵加）
页眉：模块名=差分 | 页码=____ | 触发词=多次子矩阵加
题面触发词：多次矩形加、最后输出矩阵
适用数据范围：n,m≤2000, q≤2e5
时间复杂度：O(nm+q)
空间复杂度：O(nm)
你只需要改这里：
- 更新规则
常见错误：
- 边界 r+1/c+1 越界
最小样例：
输入:
2 2 1
1 1 2 2 5
输出:
5 5
5 5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<ll>> diff(n + 2, vector<ll>(m + 2, 0));
    while (q--) {
        int x1, y1, x2, y2; ll v;
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        diff[x1][y1] += v;
        diff[x2 + 1][y1] -= v;
        diff[x1][y2 + 1] -= v;
        diff[x2 + 1][y2 + 1] += v;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i][j] = diff[i][j] + diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            if (j > 1) cout << " ";
            cout << diff[i][j];
        }
        cout << "\n";
    }
    return 0;
}

```

## 双指针 / 滑动窗口
```cpp
/*
【模板名】双指针（最短子段和 ≥ S）
页眉：模块名=双指针 | 页码=____ | 触发词=连续子段/最短/滑动窗口
题面触发词：连续子段、最短/最长满足条件
适用数据范围：n≤2e5（元素非负）
时间复杂度：O(n)
空间复杂度：O(1)
你只需要改这里：
- 条件 sum >= S
- 输出逻辑（最短/最长）
常见错误：
- 元素允许负数时不能用此模板
- 边界 n=0
最小样例：
输入:
5 7
2 3 1 2 4
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll S;
    if (!(cin >> n >> S)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    int ans = n + 1;
    for (int l = 0, r = 0; r < n; r++) {
        sum += a[r];
        while (sum >= S) {
            ans = min(ans, r - l + 1);
            sum -= a[l++];
        }
    }
    if (ans == n + 1) ans = 0;
    cout << ans << "\n";
    return 0;
}
```

## 二分
```cpp
/*
【模板名】二分查找（第一个 >= target）
页眉：模块名=二分 | 页码=____ | 触发词=答案单调/最小满足
题面触发词：最小满足条件、答案单调
适用数据范围：n≤2e5
时间复杂度：O(log n)
空间复杂度：O(1)
你只需要改这里：
- check(mid) 条件
- 输出格式
常见错误：
- 边界死循环
最小样例：
输入:
5 4
1 2 4 4 9
输出:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll target;
    if (!(cin >> n >> target)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= target) r = mid;
        else l = mid + 1;
    }
    if (n == 0 || a[l] < target) cout << -1 << "\n";
    else cout << (l + 1) << "\n";
    return 0;
}

```

## 简单贪心（区间选取最多）
```cpp
/*
【模板名】区间调度（最多不重叠）
页眉：模块名=贪心 | 页码=____ | 触发词=最多区间/不重叠
题面触发词：最多选择、不重叠区间、时间安排
适用数据范围：n≤2e5
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 区间结构与输入
- 输出（数量/列表）
常见错误：
- 排序按右端点
- 忘记更新 last_end
最小样例：
输入:
3
1 3
2 4
3 5
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Seg {
    ll l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<Seg> segs(n);
    for (int i = 0; i < n; i++) cin >> segs[i].l >> segs[i].r;
    sort(segs.begin(), segs.end(), [](const Seg &a, const Seg &b) {
        if (a.r != b.r) return a.r < b.r;
        return a.l < b.l;
    });

    ll last_end = LLONG_MIN / 4;
    int cnt = 0;
    for (auto &s : segs) {
        if (s.l >= last_end) {
            cnt++;
            last_end = s.r;
        }
    }
    cout << cnt << "\n";
    return 0;
}
```

## 简单 BFS（图）
```cpp
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

```

## 简单 DP（方案数）
```cpp
/*
【模板名】线性 DP（爬楼梯）
页眉：模块名=简单 DP | 页码=____ | 触发词=方案数/路径数
题面触发词：方案数、路径数、走法
适用数据范围：n≤1e6
时间复杂度：O(n)
空间复杂度：O(n) 或 O(1)
你只需要改这里：
- 转移公式
- 取模大小
常见错误：
- 忘记取模
- n 很小时初始化错误
最小样例：
输入:
5
输出:
8
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    if (n == 0) {
        cout << 1 << "\n";
        return 0;
    }
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}
```

## 日期时间（日期差）
```cpp
/*
【模板名】日期转天数（用于求差）
页眉：模块名=日期时间 | 页码=____ | 触发词=日期/时间差
题面触发词：日期差、天数、时间跨度
适用数据范围：年份在合理范围内（1900~2100）
时间复杂度：O(1)
空间复杂度：O(1)
你只需要改这里：
- 日期范围和输出格式
常见错误：
- 闰年判断错误
- 月份天数表写错
最小样例：
输入:
2024 2 28
2024 3 1
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

ll date_to_days(int y, int m, int d) {
    static int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    ll days = 0;
    for (int year = 1970; year < y; year++) {
        days += is_leap(year) ? 366 : 365;
    }
    for (int month = 1; month < m; month++) {
        days += mdays[month - 1];
        if (month == 2 && is_leap(y)) days += 1;
    }
    days += d - 1;
    return days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int y1, m1, d1, y2, m2, d2;
    if (!(cin >> y1 >> m1 >> d1)) return 0;
    cin >> y2 >> m2 >> d2;
    ll diff = llabs(date_to_days(y1, m1, d1) - date_to_days(y2, m2, d2));
    cout << diff << "\n";
    return 0;
}
```

## 坐标压缩
```cpp
/*
【模板名】坐标压缩
页眉：模块名=坐标压缩 | 页码=____ | 触发词=值域大/离散化
题面触发词：值域很大、只关心相对大小
适用数据范围：n≤2e5
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 需要压缩的数组
- 输出压缩值或映射
常见错误：
- 忘记去重
- 用原值直接下标越界
最小样例：
输入:
5
100 10 100 50 10
输出:
2 0 2 1 0
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++) {
        int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (i) cout << " ";
        cout << id;
    }
    cout << "\n";
    return 0;
}
```

\newpage

# 04 Q3 大模拟（重点）
页眉：模块名=大模拟 | 页码=____ | 触发词=命令/规则/状态/权限
翻页索引：
- 读题表格
- 代码骨架
- 命令解析模板
- 状态机模板
- 事件队列模板
- map 管理模板
- 日期时间转换模板
- 权限/文件系统简版
- 部分分策略与调试

## 大模拟读题表格（先填这个再写代码）
| 实体 | 属性 | 操作 | 状态变化 | 输出 | 边界 |
|---|---|---|---|---|---|
| 用户 | id, 组 | 登录/登出 | 当前用户 | 是否成功 | 重复登录 |
| 文件 | 权限, 拥有者 | 读/写/删除 | 权限变化 | 是否成功 | 不存在 |
| 目录 | 子节点 | 创建/删除 | 结构变化 | 列表 | 空目录 |

## 大模拟代码骨架
```cpp
/*
【模板名】大模拟骨架
页眉：模块名=大模拟 | 页码=____ | 触发词=命令/状态/规则
题面触发词：命令、用户、文件、权限、状态、规则
适用数据范围：n≤2e5（按题设）
时间复杂度：O(总命令数 × 单次操作)
空间复杂度：O(实体数)
你只需要改这里：
- 实体字段
- 命令解析与分发
- 状态更新
常见错误：
- 状态未初始化
- 多组数据未清空
最小样例：
输入:
3
login alice
mkfile a.txt
logout
输出:
OK
OK
OK
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Entity {
    string name;
    int state = 0;
};

void parseCommand(const string &line, vector<string> &tokens) {
    tokens.clear();
    stringstream ss(line);
    string t;
    while (ss >> t) tokens.push_back(t);
}

void applyOperation(const vector<string> &tokens) {
    // TODO: 根据 tokens[0] 分发操作
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    string line;
    getline(cin, line);

    for (int i = 0; i < q; i++) {
        getline(cin, line);
        vector<string> tokens;
        parseCommand(line, tokens);
        applyOperation(tokens);
    }
    return 0;
}
```

## 命令解析模板（getline + stringstream）
```cpp
/*
【模板名】大模拟命令解析
页眉：模块名=大模拟 | 页码=____ | 触发词=命令/解析
题面触发词：命令、日志、含空格字段
适用数据范围：命令数≤2e5
时间复杂度：O(总字符数)
空间复杂度：O(1)
你只需要改这里：
- 命令分发逻辑
常见错误：
- 忘记读取上一行换行
最小样例：
输入:
2
add user1 3
del user1
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    string line;
    getline(cin, line);

    int count_add = 0;
    for (int i = 0; i < q; i++) {
        getline(cin, line);
        stringstream ss(line);
        string cmd; ss >> cmd;
        if (cmd == "add") count_add++;
        // TODO: 按命令处理
    }
    cout << count_add << "\n";
    return 0;
}

```

## 状态机模板
```cpp
/*
【模板名】状态机模板
页眉：模块名=大模拟 | 页码=____ | 触发词=状态/切换
题面触发词：状态切换、规则驱动
适用数据范围：命令数≤2e5
时间复杂度：O(q)
空间复杂度：O(1)
你只需要改这里：
- 状态枚举
- 转移规则
常见错误：
- 忘记非法状态判断
最小样例：
输入:
4
OPEN
LOCK
UNLOCK
CLOSE
输出:
OK
DENY
OK
OK
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    const int CLOSED = 0, OPEN = 1, LOCKED = 2;
    int state = CLOSED;
    while (q--) {
        string cmd; cin >> cmd;
        if (cmd == "OPEN") {
            if (state == CLOSED) { state = OPEN; cout << "OK\n"; }
            else cout << "DENY\n";
        } else if (cmd == "CLOSE") {
            if (state == OPEN) { state = CLOSED; cout << "OK\n"; }
            else cout << "DENY\n";
        } else if (cmd == "LOCK") {
            if (state == OPEN) { state = LOCKED; cout << "OK\n"; }
            else cout << "DENY\n";
        } else if (cmd == "UNLOCK") {
            if (state == LOCKED) { state = OPEN; cout << "OK\n"; }
            else cout << "DENY\n";
        }
    }
    return 0;
}

```

## 事件队列模板（按时间或优先级处理）
```cpp
/*
【模板名】事件队列（优先处理最早事件）
页眉：模块名=大模拟 | 页码=____ | 触发词=事件/调度/排队
题面触发词：事件、时间点、调度
适用数据范围：事件数≤2e5
时间复杂度：O(E log E)
空间复杂度：O(E)
你只需要改这里：
- 事件字段
- 处理函数
常见错误：
- 优先级写反
- 时间相同处理顺序不稳定
最小样例：
输入:
2
1 A
2 B
输出:
A
B
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Event {
    ll t;
    string name;
    bool operator<(const Event &other) const {
        return t > other.t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    priority_queue<Event> pq;
    for (int i = 0; i < n; i++) {
        Event e;
        cin >> e.t >> e.name;
        pq.push(e);
    }
    while (!pq.empty()) {
        cout << pq.top().name << "\n";
        pq.pop();
    }
    return 0;
}
```

## map<string, object> 管理模板
```cpp
/*
【模板名】字符串键管理实体
页眉：模块名=大模拟 | 页码=____ | 触发词=对象表/字典
题面触发词：用名称索引对象、查找/创建
适用数据范围：实体数≤2e5
时间复杂度：O(log n)（map）/ O(1) 均摊（unordered_map）
空间复杂度：O(n)
你只需要改这里：
- Entity 字段
- 默认值
常见错误：
- 直接使用不存在的 key 导致默认创建
- 忘记更新
最小样例：
输入:
3
set A 10
get A
get B
输出:
10
NULL
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Entity {
    ll value = 0;
    bool exists = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    unordered_map<string, Entity> mp;
    for (int i = 0; i < q; i++) {
        string op, key;
        cin >> op >> key;
        if (op == "set") {
            ll v; cin >> v;
            mp[key] = {v, true};
        } else {
            if (mp.count(key) && mp[key].exists) cout << mp[key].value << "\n";
            else cout << "NULL\n";
        }
    }
    return 0;
}
```

## 日期时间转换模板（字符串 → 天数）
```cpp
/*
【模板名】日期时间字符串解析
页眉：模块名=大模拟 | 页码=____ | 触发词=时间戳/日期
题面触发词：日期、时间、日志
适用数据范围：年份合理范围
时间复杂度：O(1)
空间复杂度：O(1)
你只需要改这里：
- 输入格式
- 输出字段
常见错误：
- 闰年判断
- 月份天数
最小样例：
输入:
2024-01-02 03:04:05
输出:
19724 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int days_before_date(int y, int m, int d) {
    static int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days = 0;
    for (int year = 1970; year < y; year++) days += is_leap(year) ? 366 : 365;
    for (int month = 1; month < m; month++) {
        days += mdays[month - 1];
        if (month == 2 && is_leap(y)) days++;
    }
    days += d - 1;
    return days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;
    int y, mo, d, hh, mm, ss;
    sscanf(s.c_str(), "%d-%d-%d %d:%d:%d", &y, &mo, &d, &hh, &mm, &ss);
    int days = days_before_date(y, mo, d);
    cout << days << " " << hh << " " << mm << " " << ss << "\n";
    return 0;
}
```

## 权限/文件系统/用户系统简版（示意）
```cpp
/*
【模板名】权限检查简版
页眉：模块名=大模拟 | 页码=____ | 触发词=用户/权限/文件
题面触发词：权限、用户、文件系统
适用数据范围：实体数≤2e5
时间复杂度：O(1) 均摊
空间复杂度：O(n)
你只需要改这里：
- 权限字段
- 检查逻辑
常见错误：
- 忘记继承/默认权限
- 未登录也允许操作
最小样例：
输入:
2
login alice
read file1
输出:
OK
DENY
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct User {
    string name;
    bool logged = false;
};

struct File {
    string name;
    string owner;
    int perm = 0; // 1=read,2=write,4=exec
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    unordered_map<string, User> users;
    unordered_map<string, File> files;
    string cur = "";

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;
        if (op == "login") {
            string u; cin >> u;
            users[u].name = u;
            users[u].logged = true;
            cur = u;
            cout << "OK\n";
        } else if (op == "read") {
            string f; cin >> f;
            if (cur.empty()) {
                cout << "DENY\n";
                continue;
            }
            if (!files.count(f) || !(files[f].perm & 1)) cout << "DENY\n";
            else cout << "OK\n";
        }
    }
    return 0;
}
```

## 先拿部分分的简化策略
- 只实现题面保证的最小子任务（小 n / 小 q / 子任务 1）。
- 忽略复杂优化，保证正确性。
- 先提交拿分，再优化。

## 几百行代码不崩的命名与调试
- 统一命名：`cur_user`、`file_map`、`events`。
- 单一入口：所有命令统一进 `applyOperation()`。
- 每步打印：本地调试时打印状态，交卷前注释掉。
- 先写断言：非法状态立刻输出错误信息。

\newpage

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
```cpp
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

```

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
```cpp
/*
【模板名】网格 BFS（最短步数）
页眉：模块名=BFS | 页码=____ | 触发词=网格/最短路/等权
题面触发词：网格最短步数、每步代价相同
适用数据范围：n,m≤2000
时间复杂度：O(nm)
空间复杂度：O(nm)
你只需要改这里：
- 起点终点字符
- 4/8 方向
常见错误：
- 忘记标记访问
最小样例：
输入:
3 3
S..
.#.
..T
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    int sx = -1, sy = -1, tx = -1, ty = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') { sx = i; sy = j; }
            if (g[i][j] == 'T') { tx = i; ty = j; }
        }
    }
    q.push({sx, sy});
    dist[sx][sy] = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[tx][ty] << "\n";
    return 0;
}

```

## Dijkstra
```cpp
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
    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    const ll INF = (1LL << 60);
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : g[u]) {
            if (dist[e.to] > dist[u] + e.w) {
                dist[e.to] = dist[u] + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << (dist[i] >= INF/2 ? -1 : dist[i]);
    }
    cout << "\n";
    return 0;
}

```

## Floyd
```cpp
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
    const ll INF = (1LL << 60);
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
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
            cout << dist[i][j];
        }
        cout << "\n";
    }
    return 0;
}

```

## 并查集
```cpp
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
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
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
    DSU dsu(n);
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) dsu.unite(a, b);
        else cout << (dsu.find(a) == dsu.find(b) ? "YES" : "NO") << "\n";
    }
    return 0;
}

```

## Kruskal
```cpp
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

```

## 拓扑排序
```cpp
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
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if ((int)order.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << order[i];
    }
    cout << "\n";
    return 0;
}

```

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

\newpage

# 06 DP 模板
页眉：模块名=DP 模板 | 页码=____ | 触发词=动态规划/背包/区间
翻页索引：
- 线性 DP
- 0/1 背包
- 完全背包
- 多重背包
- 区间 DP
- 状压 DP
- 树形 DP
- LIS

## 线性 DP（最大连续子段和）
DP 含义/初始化/转移/遍历：
- dp[i]：以 i 结尾的最大连续子段和。
- 初始化：dp[0] = a[0]。
- 转移：dp[i] = max(a[i], dp[i-1] + a[i])。
- 遍历：i 从 1 到 n-1。
```cpp
/*
【模板名】线性 DP（最大连续子段和）
页眉：模块名=DP | 页码=____ | 触发词=最大子段和
题面触发词：最大连续子段和
适用数据范围：n≤2e5
时间复杂度：O(n)
空间复杂度：O(n) 或 O(1)
你只需要改这里：
- 输出最大值或区间
常见错误：
- 全负数时处理错误
最小样例：
输入:
5
-2 1 -3 4 -1
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll best = a[0];
    ll cur = a[0];
    for (int i = 1; i < n; i++) {
        cur = max(a[i], cur + a[i]);
        best = max(best, cur);
    }
    cout << best << "\n";
    return 0;
}
```

## 0/1 背包
DP 含义/初始化/转移/遍历：
- dp[j]：容量为 j 的最大价值。
- 初始化：dp[0..W]=0。
- 转移：dp[j] = max(dp[j], dp[j-w]+v)。
- 遍历：j 从 W 递减。
```cpp
/*
【模板名】0/1 背包
页眉：模块名=背包 | 页码=____ | 触发词=每件最多一次
题面触发词：每件物品只能选 0/1 次
适用数据范围：n≤2e5, W≤2e5
时间复杂度：O(nW)
空间复杂度：O(W)
你只需要改这里：
- 价值与容量
常见错误：
- 容量遍历方向写错（必须倒序）
最小样例：
输入:
3 5
2 3
3 4
4 5
输出:
7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    if (!(cin >> n >> W)) return 0;
    vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << "\n";
    return 0;
}

```

## 完全背包
DP 含义/初始化/转移/遍历：
- dp[j]：容量为 j 的最大价值。
- 初始化：dp[0..W]=0。
- 转移：dp[j] = max(dp[j], dp[j-w]+v)。
- 遍历：j 从 w 递增。
```cpp
/*
【模板名】完全背包
页眉：模块名=背包 | 页码=____ | 触发词=每件无限次
题面触发词：每件物品可选多次
适用数据范围：n≤2e5, W≤2e5
时间复杂度：O(nW)
空间复杂度：O(W)
你只需要改这里：
- 价值与容量
常见错误：
- 容量遍历方向写错（必须正序）
最小样例：
输入:
2 5
2 3
3 4
输出:
7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    if (!(cin >> n >> W)) return 0;
    vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = w[i]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << "\n";
    return 0;
}

```

## 多重背包（基础版：二进制拆分）
DP 含义/初始化/转移/遍历：
- dp[j]：容量为 j 的最大价值。
- 初始化：dp[0..W]=0。
- 转移：拆分为若干 0/1 物品，再按 0/1 背包处理。
- 遍历：j 从 W 递减。
```cpp
/*
【模板名】多重背包（二进制拆分）
页眉：模块名=DP | 页码=____ | 触发词=多重背包
题面触发词：每种物品有数量限制
适用数据范围：n≤2e5, W≤2e5
时间复杂度：O(W * 总拆分量)
空间复杂度：O(W)
你只需要改这里：
- 物品数量与价值
常见错误：
- 忘记拆分
- 容量方向写反
最小样例：
输入:
2 5
2 3 3
3 4 2
输出:
7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Item { ll w, v; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    if (!(cin >> n >> W)) return 0;
    vector<Item> items;
    for (int i = 0; i < n; i++) {
        ll w, v, c;
        cin >> w >> v >> c;
        for (ll k = 1; c > 0; k <<= 1) {
            ll take = min(k, c);
            c -= take;
            items.push_back({w * take, v * take});
        }
    }

    vector<ll> dp(W + 1, 0);
    for (auto &it : items) {
        for (int j = W; j >= it.w; j--) {
            dp[j] = max(dp[j], dp[j - it.w] + it.v);
        }
    }
    cout << dp[W] << "\n";
    return 0;
}
```

## 区间 DP
DP 含义/初始化/转移/遍历：
- dp[l][r]：合并区间 [l,r] 的最小代价。
- 初始化：dp[i][i]=0。
- 转移：枚举分割点 k。
- 遍历：区间长度从小到大。
```cpp
/*
【模板名】区间 DP（合并最小代价）
页眉：模块名=区间 DP | 页码=____ | 触发词=区间合并
题面触发词：合并区间、最小代价
适用数据范围：n≤500
时间复杂度：O(n^3)
空间复杂度：O(n^2)
你只需要改这里：
- 代价计算
常见错误：
- dp 初始化为 INF
最小样例：
输入:
4
1 2 3 4
输出:
19
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    auto sum = [&](int l, int r) { return pre[r] - pre[l - 1]; };

    const ll INF = (1LL << 60);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = INF;
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum(l, r));
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}

```

## 状压 DP
DP 含义/初始化/转移/遍历：
- dp[mask][i]：状态 mask，最后在 i 的最小代价。
- 初始化：dp[1<<0][0]=0。
- 转移：从 mask 去掉 i 转移过来。
- 遍历：mask 从小到大。
```cpp
/*
【模板名】状压 DP（旅行商简版）
页眉：模块名=状压 DP | 页码=____ | 触发词=n≤20/子集
题面触发词：n≤20、状态包含已选集合
适用数据范围：n≤20
时间复杂度：O(n^2 * 2^n)
空间复杂度：O(n * 2^n)
你只需要改这里：
- 起点与终点规则
常见错误：
- mask 下标溢出
最小样例：
输入:
3
0 1 2
1 0 3
2 3 0
输出:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<vector<ll>> w(n, vector<ll>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> w[i][j];

    const ll INF = (1LL << 60);
    int N = 1 << n;
    vector<vector<ll>> dp(N, vector<ll>(n, INF));
    dp[1][0] = 0;
    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] >= INF / 2) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int nmask = mask | (1 << v);
                dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + w[u][v]);
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < n; i++) ans = min(ans, dp[N - 1][i]);
    cout << ans << "\n";
    return 0;
}

```

## 树形 DP（最大独立集简版）
DP 含义/初始化/转移/遍历：
- dp[u][0]：u 不选时子树最大值。
- dp[u][1]：u 选时子树最大值。
- 初始化：dp[u][1]=val[u]。
- 遍历：后序 DFS。
```cpp
/*
【模板名】树形 DP（最大独立集）
页眉：模块名=DP | 页码=____ | 触发词=树形 DP
题面触发词：树上选点最大化、相邻不可同时选
适用数据范围：n≤2e5
时间复杂度：O(n)
空间复杂度：O(n)
你只需要改这里：
- 点权
- 输出最大值
常见错误：
- 忘记父子关系
- 树没建双向边
最小样例：
输入:
3
1 2 3
1 2
2 3
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<ll> val;
vector<array<ll,2>> dp;

void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = val[u];
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    g.assign(n + 1, {});
    val.assign(n + 1, 0);
    dp.assign(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return 0;
}
```

## LIS（O(n log n)）
DP 含义/初始化/转移/遍历：
- d[len]：长度为 len 的上升子序列的最小末尾值。
- 初始化：d 为空。
- 转移：用 lower_bound 替换。
- 遍历：顺序扫描。
```cpp
/*
【模板名】最长上升子序列
页眉：模块名=DP | 页码=____ | 触发词=LIS/上升子序列
题面触发词：最长上升子序列
适用数据范围：n≤2e5
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 改为非严格上升时用 upper_bound
常见错误：
- 严格/非严格搞反
最小样例：
输入:
6
1 2 2 3 1 5
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> d;
    for (ll x : a) {
        auto it = lower_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    cout << (int)d.size() << "\n";
    return 0;
}
```

\newpage

# 07 数据结构模板
页眉：模块名=数据结构 | 页码=____ | 触发词=区间/最值/查询
翻页索引：
- 树状数组
- 线段树
- 单调栈/单调队列
- Sparse Table
- 堆/priority_queue
- set lower_bound/upper_bound
- 什么时候用 set/map/priority_queue

## 树状数组（Fenwick）
```cpp
/*
【模板名】树状数组（单点加/前缀和）
页眉：模块名=树状数组 | 页码=____ | 触发词=区间和/单点加
题面触发词：单点修改、区间查询
适用数据范围：n≤2e5
时间复杂度：O(log n)
空间复杂度：O(n)
你只需要改这里：
- 操作类型
常见错误：
- 下标从 1 开始
最小样例：
输入:
5 3
1 2 3 4 5
2 1 3
1 2 5
2 1 3
输出:
6
11
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int n = 0) { init(n); }
    void init(int n_) { n = n_; bit.assign(n + 1, 0); }
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    ll sumPrefix(int idx) {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    ll rangeSum(int l, int r) { return sumPrefix(r) - sumPrefix(l - 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    Fenwick fw(n);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        fw.add(i, x);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int idx; ll delta; cin >> idx >> delta;
            fw.add(idx, delta);
        } else {
            int l, r; cin >> l >> r;
            cout << fw.rangeSum(l, r) << "\n";
        }
    }
    return 0;
}

```

## 线段树（区间和 + 区间加）
```cpp
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
        build(a, p * 2, l, m);
        build(a, p * 2 + 1, m + 1, r);
        st[p].sum = st[p * 2].sum + st[p * 2 + 1].sum;
    }

    void apply(int p, int l, int r, ll val) {
        st[p].sum += val * (r - l + 1);
        st[p].lazy += val;
    }

    void push(int p, int l, int r) {
        if (st[p].lazy == 0 || l == r) return;
        int m = (l + r) / 2;
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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    SegTree st(n);
    st.build(a, 1, 1, n);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; ll v; cin >> l >> r >> v;
            st.rangeAdd(1, 1, n, l, r, v);
        } else {
            int l, r; cin >> l >> r;
            cout << st.rangeSum(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}

```

## 单调栈（求每个元素左侧更小）
```cpp
/*
【模板名】单调栈（前一个更小）
页眉：模块名=数据结构 | 页码=____ | 触发词=单调栈/最近更小
题面触发词：最近更小/更大、下一个更小
适用数据范围：n≤2e5
时间复杂度：O(n)
空间复杂度：O(n)
你只需要改这里：
- 比较方向（更小/更大）
常见错误：
- 栈为空时访问 top
最小样例：
输入:
5
2 1 4 3 5
输出:
0 0 2 2 4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> ans(n + 1, 0);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        ans[i] = st.empty() ? 0 : st.back();
        st.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}
```

## 单调队列（滑动窗口最大值）
```cpp
/*
【模板名】单调队列（窗口最大值）
页眉：模块名=数据结构 | 页码=____ | 触发词=滑动窗口/区间最值
题面触发词：滑动窗口最大值/最小值
适用数据范围：n≤2e5
时间复杂度：O(n)
空间复杂度：O(n)
你只需要改这里：
- 比较方向（最大/最小）
常见错误：
- 忘记弹出窗口外元素
最小样例：
输入:
8 3
1 3 -1 -3 5 3 6 7
输出:
3 3 5 5 6 7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) {
            if (i >= k) cout << " ";
            cout << a[dq.front()];
        }
    }
    cout << "\n";
    return 0;
}
```

## Sparse Table（RMQ 最小值）
```cpp
/*
【模板名】Sparse Table
页眉：模块名=数据结构 | 页码=____ | 触发词=RMQ/静态区间最值
题面触发词：静态区间最小/最大值
适用数据范围：n≤2e5, q≤2e5
时间复杂度：预处理 O(n log n)，查询 O(1)
空间复杂度：O(n log n)
你只需要改这里：
- min/max
常见错误：
- log 预处理
最小样例：
输入:
5 2
1 3 2 5 4
1 3
2 5
输出:
1
2
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

    int K = 0;
    while ((1 << K) <= n) K++;
    vector<vector<ll>> st(K, vector<ll>(n + 1));
    vector<int> lg(n + 1, 0);
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++) st[0][i] = a[i];
    for (int k = 1; k < K; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int k = lg[r - l + 1];
        ll ans = min(st[k][l], st[k][r - (1 << k) + 1]);
        cout << ans << "\n";
    }
    return 0;
}
```

## 堆（priority_queue）
```cpp
/*
【模板名】堆（优先队列）
页眉：模块名=数据结构 | 页码=____ | 触发词=取最小/最大
题面触发词：取最小值/最大值、实时最值
适用数据范围：n≤2e5
时间复杂度：插入/取顶 O(log n)
空间复杂度：O(n)
你只需要改这里：
- 大根堆或小根堆
常见错误：
- greater 用错
最小样例：
输入:
3
5 1 2
输出:
1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        pq.push(x);
    }
    cout << pq.top() << "\n";
    return 0;
}
```

## set 的 lower_bound/upper_bound
```cpp
/*
【模板名】set 查找最接近
页眉：模块名=数据结构 | 页码=____ | 触发词=前驱/后继
题面触发词：前驱/后继、最近元素
适用数据范围：n≤2e5
时间复杂度：O(log n)
空间复杂度：O(n)
你只需要改这里：
- 输出规则
常见错误：
- 迭代器越界
最小样例：
输入:
5 2
1 3 5 7 9
6
4
输出:
7
5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        s.insert(x);
    }
    while (q--) {
        ll x; cin >> x;
        auto it = s.lower_bound(x);
        if (it == s.end()) cout << "NONE\n";
        else cout << *it << "\n";
    }
    return 0;
}
```

## 什么时候用 set / map / priority_queue
- set：需要有序去重、找前驱后继。
- map：需要有序键值映射。
- priority_queue：反复取当前最小/最大值。

\newpage

# 08 数学模板
页眉：模块名=数学模板 | 页码=____ | 触发词=取模/质数/组合数
翻页索引：
- gcd/lcm/快速幂/组合数
- 扩展 gcd
- 埃氏筛
- 质因数分解
- 前缀 gcd
- 浮点比较
- 分数比较
- __int128 输入输出

## gcd/lcm/快速幂/组合数
```cpp
/*
【模板名】gcd/lcm/快速幂/组合数
页眉：模块名=数学 | 页码=____ | 触发词=gcd/快速幂/组合数
题面触发词：最大公约数、最小公倍数、幂、组合数
适用数据范围：int64，组合数需模为质数
时间复杂度：O(log n) 或 O(n)
空间复杂度：O(n)
你只需要改这里：
- 模数 mod
- 组合数上限
常见错误：
- mod 不是质数仍用费马逆元
最小样例：
输入:
5 2 1000000007
输出:
10
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

ll modpow(ll a, ll e, ll mod) {
    ll r = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

struct Comb {
    ll mod;
    vector<ll> fact, invfact;
    void init(int n, ll m) {
        mod = m;
        fact.assign(n + 1, 1);
        invfact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
        invfact[n] = modpow(fact[n], mod - 2, mod);
        for (int i = n; i >= 1; i--) invfact[i - 1] = invfact[i] * i % mod;
    }
    ll C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    ll mod;
    if (!(cin >> n >> k >> mod)) return 0;
    Comb comb;
    comb.init(n, mod);
    cout << comb.C(n, k) << "\n";
    return 0;
}

```

## 扩展 gcd
```cpp
/*
【模板名】扩展 gcd
页眉：模块名=数学 | 页码=____ | 触发词=线性同余/逆元
题面触发词：ax+by=gcd(a,b)、求逆元
适用数据范围：int64
时间复杂度：O(log n)
空间复杂度：O(1)
你只需要改这里：
- 模数 m
常见错误：
- 逆元不存在（gcd!=1）
最小样例：
输入:
3 11
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, m;
    if (!(cin >> a >> m)) return 0;
    ll x, y;
    ll g = exgcd(a, m, x, y);
    if (g != 1) {
        cout << -1 << "\n";
        return 0;
    }
    x = (x % m + m) % m;
    cout << x << "\n";
    return 0;
}
```

## 埃氏筛（质数表）
```cpp
/*
【模板名】埃氏筛
页眉：模块名=数学 | 页码=____ | 触发词=质数/筛法
题面触发词：求 1..n 的质数
适用数据范围：n≤1e7
时间复杂度：O(n log log n)
空间复杂度：O(n)
你只需要改这里：
- n 的上限
常见错误：
- 1 不是质数
最小样例：
输入:
10
输出:
2 3 5 7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> is_prime(n + 1, 1);
    if (n >= 0) is_prime[0] = 0;
    if (n >= 1) is_prime[1] = 0;
    for (int i = 2; i * 1LL * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) is_prime[j] = 0;
        }
    }
    bool first = true;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << "\n";
    return 0;
}
```

## 质因数分解
```cpp
/*
【模板名】质因数分解
页眉：模块名=数学 | 页码=____ | 触发词=分解/因子
题面触发词：分解质因数、因子统计
适用数据范围：n≤1e12
时间复杂度：O(sqrt n)
空间复杂度：O(1)
你只需要改这里：
- 输出格式
常见错误：
- 忘记处理剩余大质数
最小样例：
输入:
60
输出:
2 2
3 1
5 1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    if (!(cin >> n)) return 0;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            cout << p << " " << cnt << "\n";
        }
    }
    if (n > 1) cout << n << " 1\n";
    return 0;
}
```

## 前缀 gcd
```cpp
/*
【模板名】前缀 gcd
页眉：模块名=数学 | 页码=____ | 触发词=前缀 gcd
题面触发词：前缀/后缀 gcd
适用数据范围：n≤2e5
时间复杂度：O(n log V)
空间复杂度：O(n)
你只需要改这里：
- 输出需求
常见错误：
- 0 的 gcd 处理
最小样例：
输入:
4
12 18 6 3
输出:
12 6 6 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = gcdll(pre[i - 1], a[i]);
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << pre[i];
    }
    cout << "\n";
    return 0;
}
```

## 浮点比较
```cpp
/*
【模板名】浮点比较
页眉：模块名=数学 | 页码=____ | 触发词=精度/浮点
题面触发词：浮点比较、误差
适用数据范围：double
时间复杂度：O(1)
空间复杂度：O(1)
你只需要改这里：
- eps 大小
常见错误：
- 直接用 == 比较 double
最小样例：
输入:
0.1 0.2 0.3
输出:
EQ
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    double x = a + b;
    const double eps = 1e-9;
    if (fabs(x - c) < eps) cout << "EQ\n";
    else cout << "NE\n";
    return 0;
}
```

## 分数比较（避免精度误差）
```cpp
/*
【模板名】分数比较
页眉：模块名=数学 | 页码=____ | 触发词=分数/比较大小
题面触发词：分数大小比较
适用数据范围：int64
时间复杂度：O(1)
空间复杂度：O(1)
你只需要改这里：
- 分子分母输入
常见错误：
- 直接转成 double
最小样例：
输入:
1 3
2 5
输出:
LT
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c, d;
    if (!(cin >> a >> b)) return 0;
    cin >> c >> d;
    i128 left = (i128)a * d;
    i128 right = (i128)c * b;
    if (left < right) cout << "LT\n";
    else if (left > right) cout << "GT\n";
    else cout << "EQ\n";
    return 0;
}
```

## __int128 输入输出
```cpp
/*
【模板名】__int128 输入输出
页眉：模块名=数学 | 页码=____ | 触发词=大整数
题面触发词：超大整数
适用数据范围：超过 64 位
时间复杂度：O(位数)
空间复杂度：O(1)
你只需要改这里：
- 输入来源
常见错误：
- 直接用 cout 输出 __int128
最小样例：
输入:
12345678901234567890
输出:
12345678901234567890
*/
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;

string to_string_i128(i128 x) {
    if (x == 0) return "0";
    bool neg = false;
    if (x < 0) { neg = true; x = -x; }
    string s;
    while (x > 0) {
        int d = (int)(x % 10);
        s.push_back(char('0' + d));
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    i128 x = 0;
    for (char ch : s) x = x * 10 + (ch - '0');
    cout << to_string_i128(x) << "\n";
    return 0;
}
```

\newpage

# 09 字符串模板
页眉：模块名=字符串模板 | 页码=____ | 触发词=匹配/解析/替换
翻页索引：
- 字符串遍历
- split/replace/大小写
- KMP
- 字符串哈希
- trie
- stringstream 解析
- 多行输入

## 字符串遍历
```cpp
/*
【模板名】字符串遍历
页眉：模块名=字符串 | 页码=____ | 触发词=遍历/统计
题面触发词：统计字符、逐字符处理
适用数据范围：|s|≤1e6
时间复杂度：O(n)
空间复杂度：O(1)
你只需要改这里：
- 统计逻辑
常见错误：
- 忘记处理空串
最小样例：
输入:
abca
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    int cnt = 0;
    for (char c : s) if (c == 'a') cnt++;
    cout << cnt << "\n";
    return 0;
}
```

## split（按空格/分隔符）
```cpp
/*
【模板名】split（按分隔符）
页眉：模块名=字符串 | 页码=____ | 触发词=拆分/分隔
题面触发词：分割字符串
适用数据范围：|s|≤1e6
时间复杂度：O(n)
空间复杂度：O(n)
你只需要改这里：
- 分隔符
常见错误：
- 连续分隔符处理
最小样例：
输入:
a,b,,c
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> split(const string &s, char delim) {
    vector<string> out;
    string cur;
    for (char c : s) {
        if (c == delim) {
            out.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    out.push_back(cur);
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    auto parts = split(s, ',');
    cout << parts.size() << "\n";
    return 0;
}
```

## replace（子串替换）
```cpp
/*
【模板名】replace（子串替换）
页眉：模块名=字符串 | 页码=____ | 触发词=替换/查找
题面触发词：替换所有子串
适用数据范围：|s|≤1e6
时间复杂度：O(n*m)
空间复杂度：O(n)
你只需要改这里：
- 旧子串与新子串
常见错误：
- 死循环（替换结果包含旧串）
最小样例：
输入:
abcabc
abc x
输出:
xx
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, oldp, np;
    if (!(cin >> s)) return 0;
    cin >> oldp >> np;
    string out;
    for (size_t i = 0; i < s.size();) {
        if (s.compare(i, oldp.size(), oldp) == 0) {
            out += np;
            i += oldp.size();
        } else {
            out += s[i++];
        }
    }
    cout << out << "\n";
    return 0;
}
```

## 大小写转换
```cpp
/*
【模板名】大小写转换
页眉：模块名=字符串 | 页码=____ | 触发词=大小写
题面触发词：大小写转换
适用数据范围：|s|≤1e6
时间复杂度：O(n)
空间复杂度：O(1)
你只需要改这里：
- 转换方向
常见错误：
- 忘记类型转换
最小样例：
输入:
AbC
输出:
abc
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    for (char &c : s) c = (char)tolower(c);
    cout << s << "\n";
    return 0;
}
```

## KMP
```cpp
/*
【模板名】KMP 字符串匹配
页眉：模块名=字符串 | 页码=____ | 触发词=模式匹配
题面触发词：子串匹配、模式匹配
适用数据范围：|s|≤1e6
时间复杂度：O(n+m)
空间复杂度：O(m)
你只需要改这里：
- 输出位置格式
常见错误：
- next 数组下标错
最小样例：
输入:
ababab
abab
输出:
1 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> build_next(const string &p) {
    int m = (int)p.size();
    vector<int> ne(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = ne[j - 1];
        if (p[i] == p[j]) j++;
        ne[i] = j;
    }
    return ne;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    if (!(cin >> s >> p)) return 0;
    auto ne = build_next(p);
    vector<int> pos;
    for (int i = 0, j = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != p[j]) j = ne[j - 1];
        if (s[i] == p[j]) j++;
        if (j == (int)p.size()) {
            pos.push_back(i - (int)p.size() + 2); // 1-based
            j = ne[j - 1];
        }
    }
    for (int i = 0; i < (int)pos.size(); i++) {
        if (i) cout << " ";
        cout << pos[i];
    }
    cout << "\n";
    return 0;
}

```

## 字符串哈希
```cpp
/*
【模板名】字符串哈希（滚动哈希）
页眉：模块名=字符串 | 页码=____ | 触发词=子串相等/哈希
题面触发词：比较子串相等
适用数据范围：|s|≤1e6, q≤2e5
时间复杂度：预处理 O(n)，查询 O(1)
空间复杂度：O(n)
你只需要改这里：
- base/mod
常见错误：
- 溢出未取模
最小样例：
输入:
abcab
2
1 3
3 5
输出:
294
588
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll MOD = 1000000007LL;
    const ll BASE = 911382323LL;

    string s;
    if (!(cin >> s)) return 0;
    int n = (int)s.size();
    vector<ll> h(n + 1, 0), p(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * BASE + s[i - 1]) % MOD;
        p[i] = (p[i - 1] * BASE) % MOD;
    }
    auto get = [&](int l, int r) {
        ll res = (h[r] - h[l - 1] * p[r - l + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << get(l, r) << "\n";
    }
    return 0;
}

```

## trie（简版）
```cpp
/*
【模板名】trie 简版
页眉：模块名=字符串 | 页码=____ | 触发词=前缀/字典树
题面触发词：前缀统计、字典树
适用数据范围：总字符数≤2e5
时间复杂度：插入/查询 O(长度)
空间复杂度：O(总字符数)
你只需要改这里：
- 字符范围
常见错误：
- 节点数组大小不够
最小样例：
输入:
3
ab
abc
ab
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int nxt[26];
    int cnt;
    Node() { memset(nxt, -1, sizeof(nxt)); cnt = 0; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<Node> trie(1);
    auto insert = [&](const string &s) {
        int p = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (trie[p].nxt[idx] == -1) {
                trie[p].nxt[idx] = (int)trie.size();
                trie.emplace_back();
            }
            p = trie[p].nxt[idx];
        }
        trie[p].cnt++;
    };
    auto query = [&](const string &s) {
        int p = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (trie[p].nxt[idx] == -1) return 0;
            p = trie[p].nxt[idx];
        }
        return trie[p].cnt;
    };

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        insert(words[i]);
    }
    cout << query(words[0]) << "\n";
    return 0;
}
```

## stringstream 解析混合字段
```cpp
/*
【模板名】getline + stringstream 解析
页眉：模块名=字符串 | 页码=____ | 触发词=含空格/整行解析
题面触发词：整行输入、含空格字段
适用数据范围：行数≤2e5
时间复杂度：O(总字符数)
空间复杂度：O(1)
你只需要改这里：
- 字段类型和处理逻辑
常见错误：
- 忘记读取上一行换行
最小样例：
输入:
2
hello 1
world 2
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line);

    int count_lines = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        string word;
        int num = 0;
        ss >> word >> num;
        if (!word.empty()) count_lines++;
    }
    cout << count_lines << "\n";
    return 0;
}

```

## 多行输入处理
```cpp
/*
【模板名】多行输入处理
页眉：模块名=字符串 | 页码=____ | 触发词=多行/含空格
题面触发词：多行、含空格输入
适用数据范围：行数≤2e5
时间复杂度：O(总字符数)
空间复杂度：O(1)
你只需要改这里：
- 每行处理逻辑
常见错误：
- 忘记 getline 前的换行
最小样例：
输入:
3
hello world
abc def
gg
输出:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        cnt += (int)line.size() > 0;
    }
    cout << cnt << "\n";
    return 0;
}
```

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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll best = 0;
    int N = 1 << n;
    for (int mask = 0; mask < N; mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += a[i];
        }
        best = max(best, sum);
    }
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
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int cnt = 0;
    do {
        cnt++;
        // TODO: 检查当前排列
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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll best = LLONG_MIN / 4;
    for (int l = 1; l <= n; l++) {
        ll sum = 0;
        for (int r = l; r <= n; r++) {
            sum += a[r];
            best = max(best, sum);
        }
    }
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

\newpage

# 12 近年真题索引（人工补录）
页眉：模块名=真题索引 | 页码=____ | 触发词=真题/题型/模板
翻页索引：
- 真题索引表
- 题型统计

> 说明：当前环境无法联网，先预留表格结构。请在考前人工补录。

## 真题索引表（示例格式）
| 年月-题号 | 题名 | 知识点 | 难度 | 推荐模板页 |
|---|---|---|---|---|
| 2024-12 Q1 | 统计类 | 计数/排序 | 易 | ____ |
| 2024-12 Q2 | 模拟类 | 前缀和/差分 | 中 | ____ |
| 2024-12 Q3 | 大模拟 | 命令解析/状态机 | 中 | ____ |
| 2024-12 Q4 | 图论/DP | 最短路/DP | 难 | ____ |
| 2024-12 Q5 | 高级算法 | 组合/数据结构 | 难 | ____ |

## 题型统计（填空提示）
- Q1 常见：计数、排序、简单模拟。
- Q2 常见：前缀和、差分、二分、双指针。
- Q3 常见：大模拟、状态机、命令解析。
- Q4/Q5 常见：图论、DP、数据结构、数学。

> 建议：每次做题后，把题面关键词写进 02 题型路由表。

\newpage

# 99 打印与总索引
页眉：模块名=打印索引 | 页码=____ | 触发词=打印/装订/索引
翻页索引：
- 打印建议
- 装订建议
- 总索引（关键词 → 算法 → 页码）

## 打印建议
- A4 双面打印。
- 代码模板部分单独成册。
- 快速卡片部分单独成册。
- 大模拟专册加标签页。

## 装订建议
- 第一册：Quick Cards，约 20–40 页。
- 第二册：C++/STL/Debug，约 40–60 页。
- 第三册：算法模板，约 80–150 页。
- 第四册：大模拟与部分分，约 40–80 页。
- 每册首页有目录。
- 每页页脚留页码和模块名。

## 总索引（关键词 → 算法 → 页码）
| 题面关键词 | 对应算法/模板 | 页码 |
|---|---|---|
| 区间和 | 前缀和 1D/2D | ____ |
| 子矩阵和 | 前缀和 2D | ____ |
| 区间加 | 差分 1D/2D | ____ |
| 最长满足条件 | 双指针 | ____ |
| 答案单调 | 二分答案 | ____ |
| 网格最短路 | BFS 网格 | ____ |
| 边权非负 | Dijkstra | ____ |
| 连通性 | 并查集 | ____ |
| 拓扑顺序 | 拓扑排序 | ____ |
| 区间查询 | 树状数组/线段树 | ____ |
| 选择物品 | 背包 | ____ |
| 状态爆炸 | 状压/子集枚举 | ____ |
| 命令与规则 | 大模拟 | ____ |
| 字符串匹配 | KMP/哈希 | ____ |


\newpage

# C++17 代码模板全集

页眉：模块名=代码模板合集 | 页码=____ | 触发词=模板/照抄

翻页索引：按文件名顺序

## base

```cpp
/*
【模板名】C++17 最小模板
页眉：模块名=基础模板 | 页码=____ | 触发词=空白/最小程序
题面触发词：任何题的起手模板
适用数据范围：通用
时间复杂度：O(1)
空间复杂度：O(1)
你只需要改这里：
- 读入与输出逻辑
常见错误：
- 忘记加同步关闭
最小样例：
输入:
1
输出:
1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: 读入与计算
    return 0;
}

```

## bfs_graph

```cpp
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

```

## bfs_grid

```cpp
/*
【模板名】网格 BFS（最短步数）
页眉：模块名=BFS | 页码=____ | 触发词=网格/最短路/等权
题面触发词：网格最短步数、每步代价相同
适用数据范围：n,m≤2000
时间复杂度：O(nm)
空间复杂度：O(nm)
你只需要改这里：
- 起点终点字符
- 4/8 方向
常见错误：
- 忘记标记访问
最小样例：
输入:
3 3
S..
.#.
..T
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    int sx = -1, sy = -1, tx = -1, ty = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') { sx = i; sy = j; }
            if (g[i][j] == 'T') { tx = i; ty = j; }
        }
    }
    q.push({sx, sy});
    dist[sx][sy] = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[tx][ty] << "\n";
    return 0;
}

```

## big_sim_command_parser

```cpp
/*
【模板名】大模拟命令解析
页眉：模块名=大模拟 | 页码=____ | 触发词=命令/解析
题面触发词：命令、日志、含空格字段
适用数据范围：命令数≤2e5
时间复杂度：O(总字符数)
空间复杂度：O(1)
你只需要改这里：
- 命令分发逻辑
常见错误：
- 忘记读取上一行换行
最小样例：
输入:
2
add user1 3
del user1
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    string line;
    getline(cin, line);

    int count_add = 0;
    for (int i = 0; i < q; i++) {
        getline(cin, line);
        stringstream ss(line);
        string cmd; ss >> cmd;
        if (cmd == "add") count_add++;
        // TODO: 按命令处理
    }
    cout << count_add << "\n";
    return 0;
}

```

## big_sim_state_machine

```cpp
/*
【模板名】状态机模板
页眉：模块名=大模拟 | 页码=____ | 触发词=状态/切换
题面触发词：状态切换、规则驱动
适用数据范围：命令数≤2e5
时间复杂度：O(q)
空间复杂度：O(1)
你只需要改这里：
- 状态枚举
- 转移规则
常见错误：
- 忘记非法状态判断
最小样例：
输入:
4
OPEN
LOCK
UNLOCK
CLOSE
输出:
OK
DENY
OK
OK
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    const int CLOSED = 0, OPEN = 1, LOCKED = 2;
    int state = CLOSED;
    while (q--) {
        string cmd; cin >> cmd;
        if (cmd == "OPEN") {
            if (state == CLOSED) { state = OPEN; cout << "OK\n"; }
            else cout << "DENY\n";
        } else if (cmd == "CLOSE") {
            if (state == OPEN) { state = CLOSED; cout << "OK\n"; }
            else cout << "DENY\n";
        } else if (cmd == "LOCK") {
            if (state == OPEN) { state = LOCKED; cout << "OK\n"; }
            else cout << "DENY\n";
        } else if (cmd == "UNLOCK") {
            if (state == LOCKED) { state = OPEN; cout << "OK\n"; }
            else cout << "DENY\n";
        }
    }
    return 0;
}

```

## binary_search

```cpp
/*
【模板名】二分查找（第一个 >= target）
页眉：模块名=二分 | 页码=____ | 触发词=答案单调/最小满足
题面触发词：最小满足条件、答案单调
适用数据范围：n≤2e5
时间复杂度：O(log n)
空间复杂度：O(1)
你只需要改这里：
- check(mid) 条件
- 输出格式
常见错误：
- 边界死循环
最小样例：
输入:
5 4
1 2 4 4 9
输出:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll target;
    if (!(cin >> n >> target)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= target) r = mid;
        else l = mid + 1;
    }
    if (n == 0 || a[l] < target) cout << -1 << "\n";
    else cout << (l + 1) << "\n";
    return 0;
}

```

## bitmask_dp

```cpp
/*
【模板名】状压 DP（旅行商简版）
页眉：模块名=状压 DP | 页码=____ | 触发词=n≤20/子集
题面触发词：n≤20、状态包含已选集合
适用数据范围：n≤20
时间复杂度：O(n^2 * 2^n)
空间复杂度：O(n * 2^n)
你只需要改这里：
- 起点与终点规则
常见错误：
- mask 下标溢出
最小样例：
输入:
3
0 1 2
1 0 3
2 3 0
输出:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<vector<ll>> w(n, vector<ll>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> w[i][j];

    const ll INF = (1LL << 60);
    int N = 1 << n;
    vector<vector<ll>> dp(N, vector<ll>(n, INF));
    dp[1][0] = 0;
    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] >= INF / 2) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int nmask = mask | (1 << v);
                dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + w[u][v]);
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < n; i++) ans = min(ans, dp[N - 1][i]);
    cout << ans << "\n";
    return 0;
}

```

## brute_force_intervals

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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll best = LLONG_MIN / 4;
    for (int l = 1; l <= n; l++) {
        ll sum = 0;
        for (int r = l; r <= n; r++) {
            sum += a[r];
            best = max(best, sum);
        }
    }
    cout << best << "\n";
    return 0;
}

```

## brute_force_permutation

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
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int cnt = 0;
    do {
        cnt++;
        // TODO: 检查当前排列
    } while (next_permutation(p.begin(), p.end()));
    cout << cnt << "\n";
    return 0;
}

```

## brute_force_subsets

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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll best = 0;
    int N = 1 << n;
    for (int mask = 0; mask < N; mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += a[i];
        }
        best = max(best, sum);
    }
    cout << best << "\n";
    return 0;
}

```

## difference_1d

```cpp
/*
【模板名】差分 1D（区间加）
页眉：模块名=差分 | 页码=____ | 触发词=多次区间加
题面触发词：多次区间加、最后输出数组
适用数据范围：n≤1e6, q≤1e6
时间复杂度：O(n+q)
空间复杂度：O(n)
你只需要改这里：
- 更新规则
常见错误：
- r+1 越界
最小样例：
输入:
5 2
1 2 3 4 5
1 3 10
2 5 -2
输出:
11 10 11 2 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> a(n + 1), diff(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        diff[i] += a[i] - a[i - 1];
    }
    while (q--) {
        int l, r; ll v;
        cin >> l >> r >> v;
        diff[l] += v;
        diff[r + 1] -= v;
    }
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        if (i > 1) cout << " ";
        cout << diff[i];
    }
    cout << "\n";
    return 0;
}

```

## difference_2d

```cpp
/*
【模板名】差分 2D（子矩阵加）
页眉：模块名=差分 | 页码=____ | 触发词=多次子矩阵加
题面触发词：多次矩形加、最后输出矩阵
适用数据范围：n,m≤2000, q≤2e5
时间复杂度：O(nm+q)
空间复杂度：O(nm)
你只需要改这里：
- 更新规则
常见错误：
- 边界 r+1/c+1 越界
最小样例：
输入:
2 2 1
1 1 2 2 5
输出:
5 5
5 5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<ll>> diff(n + 2, vector<ll>(m + 2, 0));
    while (q--) {
        int x1, y1, x2, y2; ll v;
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        diff[x1][y1] += v;
        diff[x2 + 1][y1] -= v;
        diff[x1][y2 + 1] -= v;
        diff[x2 + 1][y2 + 1] += v;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i][j] = diff[i][j] + diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            if (j > 1) cout << " ";
            cout << diff[i][j];
        }
        cout << "\n";
    }
    return 0;
}

```

## dijkstra

```cpp
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
    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    const ll INF = (1LL << 60);
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : g[u]) {
            if (dist[e.to] > dist[u] + e.w) {
                dist[e.to] = dist[u] + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << (dist[i] >= INF/2 ? -1 : dist[i]);
    }
    cout << "\n";
    return 0;
}

```

## dsu

```cpp
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
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
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
    DSU dsu(n);
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) dsu.unite(a, b);
        else cout << (dsu.find(a) == dsu.find(b) ? "YES" : "NO") << "\n";
    }
    return 0;
}

```

## fast_io

```cpp
/*
【模板名】快读快写
页眉：模块名=基础模板 | 页码=____ | 触发词=大输入/卡常
题面触发词：输入很大、IO 成为瓶颈
适用数据范围：数据总量≥1e6
时间复杂度：O(n)
空间复杂度：O(1)
你只需要改这里：
- 读入类型与输出内容
常见错误：
- 忘记处理负数
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

struct FastScanner {
    static const int BUFSIZE = 1 << 20;
    int idx, size;
    char buf[BUFSIZE];
    FastScanner() : idx(0), size(0) {}

    inline char read() {
        if (idx >= size) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }

    bool nextLong(ll &out) {
        char c = read();
        if (!c) return false;
        while (c != '-' && (c < '0' || c > '9')) {
            c = read();
            if (!c) return false;
        }
        ll sign = 1;
        if (c == '-') { sign = -1; c = read(); }
        ll val = 0;
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = read();
        }
        out = val * sign;
        return true;
    }

    bool nextString(string &s) {
        char c = read();
        if (!c) return false;
        while (isspace((unsigned char)c)) {
            c = read();
            if (!c) return false;
        }
        s.clear();
        while (c && !isspace((unsigned char)c)) {
            s.push_back(c);
            c = read();
        }
        return true;
    }
};

struct FastOutput {
    static const int BUFSIZE = 1 << 20;
    int idx;
    char buf[BUFSIZE];
    FastOutput() : idx(0) {}
    ~FastOutput() { flush(); }

    void flush() {
        if (idx) {
            fwrite(buf, 1, idx, stdout);
            idx = 0;
        }
    }

    void pushChar(char c) {
        if (idx >= BUFSIZE) flush();
        buf[idx++] = c;
    }

    void writeLong(ll x, char end = '\n') {
        if (x == 0) {
            pushChar('0');
            pushChar(end);
            return;
        }
        if (x < 0) { pushChar('-'); x = -x; }
        char s[32];
        int n = 0;
        while (x > 0) { s[n++] = char('0' + x % 10); x /= 10; }
        for (int i = n - 1; i >= 0; i--) pushChar(s[i]);
        pushChar(end);
    }
};

int main() {
    FastScanner fs;
    FastOutput fo;

    ll n;
    if (!fs.nextLong(n)) return 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        fs.nextLong(x);
        sum += x;
    }
    fo.writeLong(sum);
    return 0;
}

```

## fenwick

```cpp
/*
【模板名】树状数组（单点加/前缀和）
页眉：模块名=树状数组 | 页码=____ | 触发词=区间和/单点加
题面触发词：单点修改、区间查询
适用数据范围：n≤2e5
时间复杂度：O(log n)
空间复杂度：O(n)
你只需要改这里：
- 操作类型
常见错误：
- 下标从 1 开始
最小样例：
输入:
5 3
1 2 3 4 5
2 1 3
1 2 5
2 1 3
输出:
6
11
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int n = 0) { init(n); }
    void init(int n_) { n = n_; bit.assign(n + 1, 0); }
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    ll sumPrefix(int idx) {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    ll rangeSum(int l, int r) { return sumPrefix(r) - sumPrefix(l - 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    Fenwick fw(n);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        fw.add(i, x);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int idx; ll delta; cin >> idx >> delta;
            fw.add(idx, delta);
        } else {
            int l, r; cin >> l >> r;
            cout << fw.rangeSum(l, r) << "\n";
        }
    }
    return 0;
}

```

## floyd

```cpp
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
    const ll INF = (1LL << 60);
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
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
            cout << dist[i][j];
        }
        cout << "\n";
    }
    return 0;
}

```

## gcd_fastpow_comb

```cpp
/*
【模板名】gcd/lcm/快速幂/组合数
页眉：模块名=数学 | 页码=____ | 触发词=gcd/快速幂/组合数
题面触发词：最大公约数、最小公倍数、幂、组合数
适用数据范围：int64，组合数需模为质数
时间复杂度：O(log n) 或 O(n)
空间复杂度：O(n)
你只需要改这里：
- 模数 mod
- 组合数上限
常见错误：
- mod 不是质数仍用费马逆元
最小样例：
输入:
5 2 1000000007
输出:
10
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

ll modpow(ll a, ll e, ll mod) {
    ll r = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

struct Comb {
    ll mod;
    vector<ll> fact, invfact;
    void init(int n, ll m) {
        mod = m;
        fact.assign(n + 1, 1);
        invfact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
        invfact[n] = modpow(fact[n], mod - 2, mod);
        for (int i = n; i >= 1; i--) invfact[i - 1] = invfact[i] * i % mod;
    }
    ll C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    ll mod;
    if (!(cin >> n >> k >> mod)) return 0;
    Comb comb;
    comb.init(n, mod);
    cout << comb.C(n, k) << "\n";
    return 0;
}

```

## interval_dp

```cpp
/*
【模板名】区间 DP（合并最小代价）
页眉：模块名=区间 DP | 页码=____ | 触发词=区间合并
题面触发词：合并区间、最小代价
适用数据范围：n≤500
时间复杂度：O(n^3)
空间复杂度：O(n^2)
你只需要改这里：
- 代价计算
常见错误：
- dp 初始化为 INF
最小样例：
输入:
4
1 2 3 4
输出:
19
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    auto sum = [&](int l, int r) { return pre[r] - pre[l - 1]; };

    const ll INF = (1LL << 60);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = INF;
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum(l, r));
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}

```

## kmp

```cpp
/*
【模板名】KMP 字符串匹配
页眉：模块名=字符串 | 页码=____ | 触发词=模式匹配
题面触发词：子串匹配、模式匹配
适用数据范围：|s|≤1e6
时间复杂度：O(n+m)
空间复杂度：O(m)
你只需要改这里：
- 输出位置格式
常见错误：
- next 数组下标错
最小样例：
输入:
ababab
abab
输出:
1 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> build_next(const string &p) {
    int m = (int)p.size();
    vector<int> ne(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = ne[j - 1];
        if (p[i] == p[j]) j++;
        ne[i] = j;
    }
    return ne;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    if (!(cin >> s >> p)) return 0;
    auto ne = build_next(p);
    vector<int> pos;
    for (int i = 0, j = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != p[j]) j = ne[j - 1];
        if (s[i] == p[j]) j++;
        if (j == (int)p.size()) {
            pos.push_back(i - (int)p.size() + 2); // 1-based
            j = ne[j - 1];
        }
    }
    for (int i = 0; i < (int)pos.size(); i++) {
        if (i) cout << " ";
        cout << pos[i];
    }
    cout << "\n";
    return 0;
}

```

## knapsack_01

```cpp
/*
【模板名】0/1 背包
页眉：模块名=背包 | 页码=____ | 触发词=每件最多一次
题面触发词：每件物品只能选 0/1 次
适用数据范围：n≤2e5, W≤2e5
时间复杂度：O(nW)
空间复杂度：O(W)
你只需要改这里：
- 价值与容量
常见错误：
- 容量遍历方向写错（必须倒序）
最小样例：
输入:
3 5
2 3
3 4
4 5
输出:
7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    if (!(cin >> n >> W)) return 0;
    vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << "\n";
    return 0;
}

```

## knapsack_complete

```cpp
/*
【模板名】完全背包
页眉：模块名=背包 | 页码=____ | 触发词=每件无限次
题面触发词：每件物品可选多次
适用数据范围：n≤2e5, W≤2e5
时间复杂度：O(nW)
空间复杂度：O(W)
你只需要改这里：
- 价值与容量
常见错误：
- 容量遍历方向写错（必须正序）
最小样例：
输入:
2 5
2 3
3 4
输出:
7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    if (!(cin >> n >> W)) return 0;
    vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = w[i]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << "\n";
    return 0;
}

```

## kruskal

```cpp
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

```

## prefix_sum_1d

```cpp
/*
【模板名】前缀和 1D
页眉：模块名=前缀和 | 页码=____ | 触发词=区间和/子段和
题面触发词：区间和、连续子段和
适用数据范围：n≤1e6, q≤1e6
时间复杂度：预处理 O(n)，查询 O(1)
空间复杂度：O(n)
你只需要改这里：
- 输入格式
- 查询输出
常见错误：
- 下标从 1 还是 0
最小样例：
输入:
5 3
1 2 3 4 5
1 3
2 5
4 4
输出:
6
14
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << pre[r] - pre[l - 1] << "\n";
    }
    return 0;
}

```

## prefix_sum_2d

```cpp
/*
【模板名】前缀和 2D
页眉：模块名=前缀和 | 页码=____ | 触发词=子矩阵和
题面触发词：矩形区域和、子矩阵和
适用数据范围：n,m≤2000
时间复杂度：预处理 O(nm)，查询 O(1)
空间复杂度：O(nm)
你只需要改这里：
- 输入矩阵与查询
常见错误：
- 下标从 1 开始
最小样例：
输入:
2 2 2
1 2
3 4
1 1 2 2
1 2 2 2
输出:
10
6
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<ll>> pre(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll x; cin >> x;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x;
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
    return 0;
}

```

## segment_tree

```cpp
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
        build(a, p * 2, l, m);
        build(a, p * 2 + 1, m + 1, r);
        st[p].sum = st[p * 2].sum + st[p * 2 + 1].sum;
    }

    void apply(int p, int l, int r, ll val) {
        st[p].sum += val * (r - l + 1);
        st[p].lazy += val;
    }

    void push(int p, int l, int r) {
        if (st[p].lazy == 0 || l == r) return;
        int m = (l + r) / 2;
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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    SegTree st(n);
    st.build(a, 1, 1, n);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; ll v; cin >> l >> r >> v;
            st.rangeAdd(1, 1, n, l, r, v);
        } else {
            int l, r; cin >> l >> r;
            cout << st.rangeSum(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}

```

## string_hash

```cpp
/*
【模板名】字符串哈希（滚动哈希）
页眉：模块名=字符串 | 页码=____ | 触发词=子串相等/哈希
题面触发词：比较子串相等
适用数据范围：|s|≤1e6, q≤2e5
时间复杂度：预处理 O(n)，查询 O(1)
空间复杂度：O(n)
你只需要改这里：
- base/mod
常见错误：
- 溢出未取模
最小样例：
输入:
abcab
2
1 3
3 5
输出:
294
588
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll MOD = 1000000007LL;
    const ll BASE = 911382323LL;

    string s;
    if (!(cin >> s)) return 0;
    int n = (int)s.size();
    vector<ll> h(n + 1, 0), p(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * BASE + s[i - 1]) % MOD;
        p[i] = (p[i - 1] * BASE) % MOD;
    }
    auto get = [&](int l, int r) {
        ll res = (h[r] - h[l - 1] * p[r - l + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << get(l, r) << "\n";
    }
    return 0;
}

```

## stringstream_parser

```cpp
/*
【模板名】getline + stringstream 解析
页眉：模块名=字符串 | 页码=____ | 触发词=含空格/整行解析
题面触发词：整行输入、含空格字段
适用数据范围：行数≤2e5
时间复杂度：O(总字符数)
空间复杂度：O(1)
你只需要改这里：
- 字段类型和处理逻辑
常见错误：
- 忘记读取上一行换行
最小样例：
输入:
2
hello 1
world 2
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line);

    int count_lines = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        string word;
        int num = 0;
        ss >> word >> num;
        if (!word.empty()) count_lines++;
    }
    cout << count_lines << "\n";
    return 0;
}

```

## topo_sort

```cpp
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
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if ((int)order.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << order[i];
    }
    cout << "\n";
    return 0;
}

```

## vector_map_set

```cpp
/*
【模板名】vector/map/set 速用
页眉：模块名=基础模板 | 页码=____ | 触发词=去重/统计/有序
题面触发词：去重、统计次数、有序输出
适用数据范围：n≤2e5
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 统计字段
- 输出格式
常见错误：
- map 遍历顺序误解
最小样例：
输入:
5
2 1 2 3 1
输出:
1 2
2 2
3 1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> cnt;
    for (ll x : a) cnt[x]++;

    for (auto &kv : cnt) {
        cout << kv.first << " " << kv.second << "\n";
    }
    return 0;
}

```
