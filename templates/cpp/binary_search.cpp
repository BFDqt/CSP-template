/*
【模板名】二分查找（第一个 >= target）
页眉：模块名=二分 | 页码=____ | 触发词=答案单调/最小满足
题面触发词：最小满足条件、答案单调
适用数据范围：n≤2e5
时间复杂度：O(log n)
空间复杂度：O(1)
你只需要改这里：
- check(mid) 条件
- 输出格式
常见错误：
- 边界死循环
最小样例：
输入:
5 4
1 2 4 4 9
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
    ll target;
    if (!(cin >> n >> target)) return 0;
    // 改这里：target 为目标值
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // 数组必须是有序的（升序）
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        // 找第一个 >= target 的位置
        if (a[mid] >= target) r = mid;
        else l = mid + 1;
    }
    // 未找到时输出 -1
    if (n == 0 || a[l] < target) cout << -1 << "\n";
    else cout << (l + 1) << "\n";
    return 0;
}
