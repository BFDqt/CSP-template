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
    // 改这里：n 行 m 列，q 次查询
    // pre[i][j] 表示子矩阵 (1,1)-(i,j) 的和
    vector<vector<ll>> pre(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll x; cin >> x;
            // 经典二维前缀和公式
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x;
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 子矩阵和 = 四块前缀相减
        ll ans = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
    return 0;
}
