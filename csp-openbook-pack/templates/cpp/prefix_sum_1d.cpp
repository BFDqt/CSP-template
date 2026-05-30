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
