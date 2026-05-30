# 01 C++ 生存手册
页眉：模块名=C++ 生存 | 页码=____ | 触发词=输入输出/STL/常见错误
翻页索引：
- C++17 最小程序
- 输入输出与快读快写
- 字符串与 stringstream
- STL 容器速查
- 常见编译/运行错误

## C++17 最小程序
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: 读入、计算、输出
    return 0;
}
```

## 输入输出（基础）
- 读整数/字符串：`cin >> x;`
- 输出换行：`cout << x << "\n";`
- 多组数据：`while (cin >> x) { ... }`

## 卡常快读快写
- 需要极限 IO 时，直接用模板：
{{include:templates/cpp/fast_io.cpp}}

## getline 与 cin 混用
- 先读完 `cin` 后加一行：`cin.ignore(numeric_limits<streamsize>::max(), '\n');`
- 再使用 `getline`。

## 字符串读写常见坑
- 空行：`getline` 可能读到空串。
- 末尾空格：`stringstream` 会自动忽略连续空格。
- 大小写：使用 `tolower/ toupper`。

## stringstream 模板
{{include:templates/cpp/stringstream_parser.cpp}}

## STL 容器速查（什么时候用/怎么声明/怎么遍历/怎么增删查）
### vector
- 用途：顺序数组，可随机访问。
- 声明：`vector<ll> a(n, 0);`
- 遍历：`for (ll x : a) {}` 或下标。
- 增删：`push_back`、`pop_back`。

### map / unordered_map
- 用途：键值映射。`map` 有序，`unordered_map` 更快但不稳定。
- 声明：`map<string, ll> mp;`
- 遍历：`for (auto &kv : mp) {}`
- 增删查：`mp[key] = val; mp.erase(key); mp.count(key);`

### set / unordered_set
- 用途：去重、查找。
- 声明：`set<ll> s;`
- 遍历：`for (ll x : s) {}`
- 增删查：`insert`、`erase`、`count`。

### queue / stack / deque
- queue：先进先出，BFS。
- stack：后进先出，括号匹配/DFS。
- deque：双端队列，单调队列常用。

### priority_queue
- 大根堆：`priority_queue<ll> pq;`
- 小根堆：`priority_queue<ll, vector<ll>, greater<ll>> pq;`

### pair / tuple
- pair：`pair<ll,ll> p = {a,b};`
- tuple：`tuple<ll,ll,ll> t = {a,b,c};`

### lambda 排序
```cpp
sort(a.begin(), a.end(), [](const Node &x, const Node &y){
    return x.key < y.key;
});
```

### 二维数组 / vector
```cpp
vector<vector<ll>> a(n, vector<ll>(m, 0));
```

### long long / __int128
- 大整数：用 `__int128` 做中间计算。
- 输出需手写转换函数。

### double 精度
- 比较：`fabs(a - b) < 1e-9`。
- 输出：`cout << fixed << setprecision(6);`

## 常见编译错误（CE）
- 缺少 `;` 或 `}`。
- 变量名重复或未声明。
- 模板尖括号 `>>` 不匹配（老编译器）。

## 常见运行错误（RE）
- 数组越界。
- 空队列 `front()`。
- 递归太深导致栈溢出。
- 除以 0。

## 常见 WA 原因
- 下标从 0/1 混用。
- 多组数据未清空容器。
- 输出格式多空格/少换行。
- 溢出使用 int。

## 容器示例模板
{{include:templates/cpp/vector_map_set.cpp}}
