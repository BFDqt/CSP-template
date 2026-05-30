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
