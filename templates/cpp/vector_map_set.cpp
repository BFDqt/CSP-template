/*
【模板名】vector/map/set 速用
页眉：模块名=基础模板 | 页码=____ | 触发词=去重/统计/有序
题面触发词：去重、统计次数、有序输出
适用数据范围：n≤2e5
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 统计字段
- 输出格式
常见错误：
- map 遍历顺序误解
最小样例：
输入:
5
2 1 2 3 1
输出:
1 2
2 2
3 1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    // 改这里：读入的元素类型/数量
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 用 map 统计频次，map 会自动按 key 升序
    map<ll, ll> cnt;
    for (ll x : a) cnt[x]++;

    // 按 key 有序输出
    for (auto &kv : cnt) {
        cout << kv.first << " " << kv.second << "\n";
    }
    return 0;
}
