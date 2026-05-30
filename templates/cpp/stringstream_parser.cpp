/*
【模板名】getline + stringstream 解析
页眉：模块名=字符串 | 页码=____ | 触发词=含空格/整行解析
题面触发词：整行输入、含空格字段
适用数据范围：行数≤2e5
时间复杂度：O(总字符数)
空间复杂度：O(1)
你只需要改这里：
- 字段类型和处理逻辑
常见错误：
- 忘记读取上一行换行
最小样例：
输入:
2
hello 1
world 2
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line);

    int count_lines = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        string word;
        int num = 0;
        ss >> word >> num;
        if (!word.empty()) count_lines++;
    }
    cout << count_lines << "\n";
    return 0;
}
