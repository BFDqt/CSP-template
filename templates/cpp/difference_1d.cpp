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
    // 改这里：n 为数组长度，q 为修改次数
    vector<ll> a(n + 1), diff(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 构建差分数组：diff[i] = a[i] - a[i-1]
    for (int i = 1; i <= n; i++) {
        diff[i] += a[i] - a[i - 1];
    }
    while (q--) {
        int l, r; ll v;
        cin >> l >> r >> v;
        // 区间加：在 l 加 v，在 r+1 减 v
        diff[l] += v;
        diff[r + 1] -= v;
    }
    // 差分前缀还原原数组
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        if (i > 1) cout << " ";
        cout << diff[i];
    }
    cout << "\n";
    return 0;
}
