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
    // 改这里：物品数量 n、容量 W
    vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    // dp[j] 表示容量为 j 的最大价值
    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        // 完全背包必须正序遍历容量
        for (int j = w[i]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    // 改这里：输出 dp[W] 或最大值
    cout << dp[W] << "\n";
    return 0;
}
