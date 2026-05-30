# 04 Q3 大模拟（重点）
页眉：模块名=大模拟 | 页码=____ | 触发词=命令/规则/状态/权限
翻页索引：
- 读题表格
- 代码骨架
- 命令解析模板
- 状态机模板
- 事件队列模板
- map 管理模板
- 日期时间转换模板
- 权限/文件系统简版
- 部分分策略与调试

## 大模拟读题表格（先填这个再写代码）
| 实体 | 属性 | 操作 | 状态变化 | 输出 | 边界 |
|---|---|---|---|---|---|
| 用户 | id, 组 | 登录/登出 | 当前用户 | 是否成功 | 重复登录 |
| 文件 | 权限, 拥有者 | 读/写/删除 | 权限变化 | 是否成功 | 不存在 |
| 目录 | 子节点 | 创建/删除 | 结构变化 | 列表 | 空目录 |

## 大模拟代码骨架
```cpp
/*
【模板名】大模拟骨架
页眉：模块名=大模拟 | 页码=____ | 触发词=命令/状态/规则
题面触发词：命令、用户、文件、权限、状态、规则
适用数据范围：n≤2e5（按题设）
时间复杂度：O(总命令数 × 单次操作)
空间复杂度：O(实体数)
你只需要改这里：
- 实体字段
- 命令解析与分发
- 状态更新
常见错误：
- 状态未初始化
- 多组数据未清空
最小样例：
输入:
3
login alice
mkfile a.txt
logout
输出:
OK
OK
OK
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Entity {
    string name;
    int state = 0;
};

void parseCommand(const string &line, vector<string> &tokens) {
    tokens.clear();
    stringstream ss(line);
    string t;
    while (ss >> t) tokens.push_back(t);
}

void applyOperation(const vector<string> &tokens) {
    // TODO: 根据 tokens[0] 分发操作
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    string line;
    getline(cin, line);

    for (int i = 0; i < q; i++) {
        getline(cin, line);
        vector<string> tokens;
        parseCommand(line, tokens);
        applyOperation(tokens);
    }
    return 0;
}
```

## 命令解析模板（getline + stringstream）
{{include:templates/cpp/big_sim_command_parser.cpp}}

## 状态机模板
{{include:templates/cpp/big_sim_state_machine.cpp}}

## 事件队列模板（按时间或优先级处理）
```cpp
/*
【模板名】事件队列（优先处理最早事件）
页眉：模块名=大模拟 | 页码=____ | 触发词=事件/调度/排队
题面触发词：事件、时间点、调度
适用数据范围：事件数≤2e5
时间复杂度：O(E log E)
空间复杂度：O(E)
你只需要改这里：
- 事件字段
- 处理函数
常见错误：
- 优先级写反
- 时间相同处理顺序不稳定
最小样例：
输入:
2
1 A
2 B
输出:
A
B
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Event {
    ll t;
    string name;
    bool operator<(const Event &other) const {
        return t > other.t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    priority_queue<Event> pq;
    for (int i = 0; i < n; i++) {
        Event e;
        cin >> e.t >> e.name;
        pq.push(e);
    }
    while (!pq.empty()) {
        cout << pq.top().name << "\n";
        pq.pop();
    }
    return 0;
}
```

## map<string, object> 管理模板
```cpp
/*
【模板名】字符串键管理实体
页眉：模块名=大模拟 | 页码=____ | 触发词=对象表/字典
题面触发词：用名称索引对象、查找/创建
适用数据范围：实体数≤2e5
时间复杂度：O(log n)（map）/ O(1) 均摊（unordered_map）
空间复杂度：O(n)
你只需要改这里：
- Entity 字段
- 默认值
常见错误：
- 直接使用不存在的 key 导致默认创建
- 忘记更新
最小样例：
输入:
3
set A 10
get A
get B
输出:
10
NULL
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Entity {
    ll value = 0;
    bool exists = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    unordered_map<string, Entity> mp;
    for (int i = 0; i < q; i++) {
        string op, key;
        cin >> op >> key;
        if (op == "set") {
            ll v; cin >> v;
            mp[key] = {v, true};
        } else {
            if (mp.count(key) && mp[key].exists) cout << mp[key].value << "\n";
            else cout << "NULL\n";
        }
    }
    return 0;
}
```

## 日期时间转换模板（字符串 → 天数）
```cpp
/*
【模板名】日期时间字符串解析
页眉：模块名=大模拟 | 页码=____ | 触发词=时间戳/日期
题面触发词：日期、时间、日志
适用数据范围：年份合理范围
时间复杂度：O(1)
空间复杂度：O(1)
你只需要改这里：
- 输入格式
- 输出字段
常见错误：
- 闰年判断
- 月份天数
最小样例：
输入:
2024-01-02 03:04:05
输出:
19724 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int days_before_date(int y, int m, int d) {
    static int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days = 0;
    for (int year = 1970; year < y; year++) days += is_leap(year) ? 366 : 365;
    for (int month = 1; month < m; month++) {
        days += mdays[month - 1];
        if (month == 2 && is_leap(y)) days++;
    }
    days += d - 1;
    return days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;
    int y, mo, d, hh, mm, ss;
    sscanf(s.c_str(), "%d-%d-%d %d:%d:%d", &y, &mo, &d, &hh, &mm, &ss);
    int days = days_before_date(y, mo, d);
    cout << days << " " << hh << " " << mm << " " << ss << "\n";
    return 0;
}
```

## 权限/文件系统/用户系统简版（示意）
```cpp
/*
【模板名】权限检查简版
页眉：模块名=大模拟 | 页码=____ | 触发词=用户/权限/文件
题面触发词：权限、用户、文件系统
适用数据范围：实体数≤2e5
时间复杂度：O(1) 均摊
空间复杂度：O(n)
你只需要改这里：
- 权限字段
- 检查逻辑
常见错误：
- 忘记继承/默认权限
- 未登录也允许操作
最小样例：
输入:
2
login alice
read file1
输出:
OK
DENY
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct User {
    string name;
    bool logged = false;
};

struct File {
    string name;
    string owner;
    int perm = 0; // 1=read,2=write,4=exec
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;
    unordered_map<string, User> users;
    unordered_map<string, File> files;
    string cur = "";

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;
        if (op == "login") {
            string u; cin >> u;
            users[u].name = u;
            users[u].logged = true;
            cur = u;
            cout << "OK\n";
        } else if (op == "read") {
            string f; cin >> f;
            if (cur.empty()) {
                cout << "DENY\n";
                continue;
            }
            if (!files.count(f) || !(files[f].perm & 1)) cout << "DENY\n";
            else cout << "OK\n";
        }
    }
    return 0;
}
```

## 先拿部分分的简化策略
- 只实现题面保证的最小子任务（小 n / 小 q / 子任务 1）。
- 忽略复杂优化，保证正确性。
- 先提交拿分，再优化。

## 几百行代码不崩的命名与调试
- 统一命名：`cur_user`、`file_map`、`events`。
- 单一入口：所有命令统一进 `applyOperation()`。
- 每步打印：本地调试时打印状态，交卷前注释掉。
- 先写断言：非法状态立刻输出错误信息。
