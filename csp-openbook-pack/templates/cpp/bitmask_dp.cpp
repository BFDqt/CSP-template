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
