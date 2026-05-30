/*
【模板名】大模拟命令解析
页眉：模块名=大模拟 | 页码=____ | 触发词=命令/解析
题面触发词：命令、日志、含空格字段
适用数据范围：命令数≤2e5
时间复杂度：O(总字符数)
空间复杂度：O(1)
你只需要改这里：
- 命令分发逻辑
常见错误：
- 忘记读取上一行换行
最小样例：
输入:
2
add user1 3
del user1
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    string line;
    getline(cin, line);

    int count_add = 0;
    for (int i = 0; i < q; i++) {
        getline(cin, line);
        stringstream ss(line);
        string cmd; ss >> cmd;
        if (cmd == "add") count_add++;
        // TODO: 按命令处理
    }
    cout << count_add << "\n";
    return 0;
}
