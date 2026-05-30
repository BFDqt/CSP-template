/*
【模板名】子集枚举（位运算）
页眉：模块名=暴力 | 页码=____ | 触发词=子集/状压
题面触发词：n≤20，枚举子集
适用数据范围：n≤20
时间复杂度：O(n*2^n)
空间复杂度：O(1)
你只需要改这里：
- 统计逻辑
常见错误：
- 位运算顺序
最小样例：
输入:
3
1 2 3
输出:
6
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    // 改这里：n<=20 才能枚举
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll best = 0;
    int N = 1 << n;
    // mask 的每一位表示是否选第 i 个元素
    for (int mask = 0; mask < N; mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += a[i];
        }
        best = max(best, sum);
    }
    // 改这里：输出最大值/计数/是否存在
    cout << best << "\n";
    return 0;
}
