# 09 字符串模板
页眉：模块名=字符串模板 | 页码=____ | 触发词=匹配/解析/替换
翻页索引：
- 字符串遍历
- split/replace/大小写
- KMP
- 字符串哈希
- trie
- stringstream 解析
- 多行输入

## 字符串遍历
```cpp
/*
【模板名】字符串遍历
页眉：模块名=字符串 | 页码=____ | 触发词=遍历/统计
题面触发词：统计字符、逐字符处理
适用数据范围：|s|≤1e6
时间复杂度：O(n)
空间复杂度：O(1)
你只需要改这里：
- 统计逻辑
常见错误：
- 忘记处理空串
最小样例：
输入:
abca
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    int cnt = 0;
    for (char c : s) if (c == 'a') cnt++;
    cout << cnt << "\n";
    return 0;
}
```

## split（按空格/分隔符）
```cpp
/*
【模板名】split（按分隔符）
页眉：模块名=字符串 | 页码=____ | 触发词=拆分/分隔
题面触发词：分割字符串
适用数据范围：|s|≤1e6
时间复杂度：O(n)
空间复杂度：O(n)
你只需要改这里：
- 分隔符
常见错误：
- 连续分隔符处理
最小样例：
输入:
a,b,,c
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> split(const string &s, char delim) {
    vector<string> out;
    string cur;
    for (char c : s) {
        if (c == delim) {
            out.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    out.push_back(cur);
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    auto parts = split(s, ',');
    cout << parts.size() << "\n";
    return 0;
}
```

## replace（子串替换）
```cpp
/*
【模板名】replace（子串替换）
页眉：模块名=字符串 | 页码=____ | 触发词=替换/查找
题面触发词：替换所有子串
适用数据范围：|s|≤1e6
时间复杂度：O(n*m)
空间复杂度：O(n)
你只需要改这里：
- 旧子串与新子串
常见错误：
- 死循环（替换结果包含旧串）
最小样例：
输入:
abcabc
abc x
输出:
xx
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, oldp, np;
    if (!(cin >> s)) return 0;
    cin >> oldp >> np;
    string out;
    for (size_t i = 0; i < s.size();) {
        if (s.compare(i, oldp.size(), oldp) == 0) {
            out += np;
            i += oldp.size();
        } else {
            out += s[i++];
        }
    }
    cout << out << "\n";
    return 0;
}
```

## 大小写转换
```cpp
/*
【模板名】大小写转换
页眉：模块名=字符串 | 页码=____ | 触发词=大小写
题面触发词：大小写转换
适用数据范围：|s|≤1e6
时间复杂度：O(n)
空间复杂度：O(1)
你只需要改这里：
- 转换方向
常见错误：
- 忘记类型转换
最小样例：
输入:
AbC
输出:
abc
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    for (char &c : s) c = (char)tolower(c);
    cout << s << "\n";
    return 0;
}
```

## KMP
{{include:templates/cpp/kmp.cpp}}

## 字符串哈希
{{include:templates/cpp/string_hash.cpp}}

## trie（简版）
```cpp
/*
【模板名】trie 简版
页眉：模块名=字符串 | 页码=____ | 触发词=前缀/字典树
题面触发词：前缀统计、字典树
适用数据范围：总字符数≤2e5
时间复杂度：插入/查询 O(长度)
空间复杂度：O(总字符数)
你只需要改这里：
- 字符范围
常见错误：
- 节点数组大小不够
最小样例：
输入:
3
ab
abc
ab
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int nxt[26];
    int cnt;
    Node() { memset(nxt, -1, sizeof(nxt)); cnt = 0; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<Node> trie(1);
    auto insert = [&](const string &s) {
        int p = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (trie[p].nxt[idx] == -1) {
                trie[p].nxt[idx] = (int)trie.size();
                trie.emplace_back();
            }
            p = trie[p].nxt[idx];
        }
        trie[p].cnt++;
    };
    auto query = [&](const string &s) {
        int p = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (trie[p].nxt[idx] == -1) return 0;
            p = trie[p].nxt[idx];
        }
        return trie[p].cnt;
    };

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        insert(words[i]);
    }
    cout << query(words[0]) << "\n";
    return 0;
}
```

## stringstream 解析混合字段
{{include:templates/cpp/stringstream_parser.cpp}}

## 多行输入处理
```cpp
/*
【模板名】多行输入处理
页眉：模块名=字符串 | 页码=____ | 触发词=多行/含空格
题面触发词：多行、含空格输入
适用数据范围：行数≤2e5
时间复杂度：O(总字符数)
空间复杂度：O(1)
你只需要改这里：
- 每行处理逻辑
常见错误：
- 忘记 getline 前的换行
最小样例：
输入:
3
hello world
abc def
gg
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
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        cnt += (int)line.size() > 0;
    }
    cout << cnt << "\n";
    return 0;
}
```
