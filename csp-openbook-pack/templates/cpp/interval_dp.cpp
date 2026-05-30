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
