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
