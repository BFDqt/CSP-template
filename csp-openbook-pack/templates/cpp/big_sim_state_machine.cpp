/*
【模板名】状态机模板
页眉：模块名=大模拟 | 页码=____ | 触发词=状态/切换
题面触发词：状态切换、规则驱动
适用数据范围：命令数≤2e5
时间复杂度：O(q)
空间复杂度：O(1)
你只需要改这里：
- 状态枚举
- 转移规则
常见错误：
- 忘记非法状态判断
最小样例：
输入:
4
OPEN
LOCK
UNLOCK
CLOSE
输出:
OK
DENY
OK
OK
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    const int CLOSED = 0, OPEN = 1, LOCKED = 2;
    int state = CLOSED;
    while (q--) {
        string cmd; cin >> cmd;
        if (cmd == "OPEN") {
            if (state == CLOSED) { state = OPEN; cout << "OK\n"; }
            else cout << "DENY\n";
        } else if (cmd == "CLOSE") {
            if (state == OPEN) { state = CLOSED; cout << "OK\n"; }
            else cout << "DENY\n";
        } else if (cmd == "LOCK") {
            if (state == OPEN) { state = LOCKED; cout << "OK\n"; }
            else cout << "DENY\n";
        } else if (cmd == "UNLOCK") {
            if (state == LOCKED) { state = OPEN; cout << "OK\n"; }
            else cout << "DENY\n";
        }
    }
    return 0;
}
