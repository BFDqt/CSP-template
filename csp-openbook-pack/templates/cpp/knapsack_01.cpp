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
