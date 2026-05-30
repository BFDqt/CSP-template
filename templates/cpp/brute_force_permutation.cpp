/*
【模板名】全排列枚举
页眉：模块名=暴力 | 页码=____ | 触发词=全排列/n≤10
题面触发词：n≤10，枚举全排列
适用数据范围：n≤10
时间复杂度：O(n! * n)
空间复杂度：O(n)
你只需要改这里：
- 检查逻辑
常见错误：
- 忘记初始化序列
最小样例：
输入:
3
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
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int cnt = 0;
    do {
        cnt++;
        // TODO: 检查当前排列
    } while (next_permutation(p.begin(), p.end()));
    cout << cnt << "\n";
    return 0;
}
