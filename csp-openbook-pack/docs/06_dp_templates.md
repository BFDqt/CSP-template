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
{{include:templates/cpp/knapsack_01.cpp}}

## 完全背包
DP 含义/初始化/转移/遍历：
- dp[j]：容量为 j 的最大价值。
- 初始化：dp[0..W]=0。
- 转移：dp[j] = max(dp[j], dp[j-w]+v)。
- 遍历：j 从 w 递增。
{{include:templates/cpp/knapsack_complete.cpp}}

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
{{include:templates/cpp/interval_dp.cpp}}

## 状压 DP
DP 含义/初始化/转移/遍历：
- dp[mask][i]：状态 mask，最后在 i 的最小代价。
- 初始化：dp[1<<0][0]=0。
- 转移：从 mask 去掉 i 转移过来。
- 遍历：mask 从小到大。
{{include:templates/cpp/bitmask_dp.cpp}}

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
