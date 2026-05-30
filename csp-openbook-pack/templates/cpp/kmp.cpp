/*
【模板名】KMP 字符串匹配
页眉：模块名=字符串 | 页码=____ | 触发词=模式匹配
题面触发词：子串匹配、模式匹配
适用数据范围：|s|≤1e6
时间复杂度：O(n+m)
空间复杂度：O(m)
你只需要改这里：
- 输出位置格式
常见错误：
- next 数组下标错
最小样例：
输入:
ababab
abab
输出:
1 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> build_next(const string &p) {
    int m = (int)p.size();
    vector<int> ne(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = ne[j - 1];
        if (p[i] == p[j]) j++;
        ne[i] = j;
    }
    return ne;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    if (!(cin >> s >> p)) return 0;
    auto ne = build_next(p);
    vector<int> pos;
    for (int i = 0, j = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != p[j]) j = ne[j - 1];
        if (s[i] == p[j]) j++;
        if (j == (int)p.size()) {
            pos.push_back(i - (int)p.size() + 2); // 1-based
            j = ne[j - 1];
        }
    }
    for (int i = 0; i < (int)pos.size(); i++) {
        if (i) cout << " ";
        cout << pos[i];
    }
    cout << "\n";
    return 0;
}
