# 08 数学模板
页眉：模块名=数学模板 | 页码=____ | 触发词=取模/质数/组合数
翻页索引：
- gcd/lcm/快速幂/组合数
- 扩展 gcd
- 埃氏筛
- 质因数分解
- 前缀 gcd
- 浮点比较
- 分数比较
- __int128 输入输出

## gcd/lcm/快速幂/组合数
{{include:templates/cpp/gcd_fastpow_comb.cpp}}

## 扩展 gcd
```cpp
/*
【模板名】扩展 gcd
页眉：模块名=数学 | 页码=____ | 触发词=线性同余/逆元
题面触发词：ax+by=gcd(a,b)、求逆元
适用数据范围：int64
时间复杂度：O(log n)
空间复杂度：O(1)
你只需要改这里：
- 模数 m
常见错误：
- 逆元不存在（gcd!=1）
最小样例：
输入:
3 11
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, m;
    if (!(cin >> a >> m)) return 0;
    ll x, y;
    ll g = exgcd(a, m, x, y);
    if (g != 1) {
        cout << -1 << "\n";
        return 0;
    }
    x = (x % m + m) % m;
    cout << x << "\n";
    return 0;
}
```

## 埃氏筛（质数表）
```cpp
/*
【模板名】埃氏筛
页眉：模块名=数学 | 页码=____ | 触发词=质数/筛法
题面触发词：求 1..n 的质数
适用数据范围：n≤1e7
时间复杂度：O(n log log n)
空间复杂度：O(n)
你只需要改这里：
- n 的上限
常见错误：
- 1 不是质数
最小样例：
输入:
10
输出:
2 3 5 7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> is_prime(n + 1, 1);
    if (n >= 0) is_prime[0] = 0;
    if (n >= 1) is_prime[1] = 0;
    for (int i = 2; i * 1LL * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) is_prime[j] = 0;
        }
    }
    bool first = true;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << "\n";
    return 0;
}
```

## 质因数分解
```cpp
/*
【模板名】质因数分解
页眉：模块名=数学 | 页码=____ | 触发词=分解/因子
题面触发词：分解质因数、因子统计
适用数据范围：n≤1e12
时间复杂度：O(sqrt n)
空间复杂度：O(1)
你只需要改这里：
- 输出格式
常见错误：
- 忘记处理剩余大质数
最小样例：
输入:
60
输出:
2 2
3 1
5 1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    if (!(cin >> n)) return 0;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            cout << p << " " << cnt << "\n";
        }
    }
    if (n > 1) cout << n << " 1\n";
    return 0;
}
```

## 前缀 gcd
```cpp
/*
【模板名】前缀 gcd
页眉：模块名=数学 | 页码=____ | 触发词=前缀 gcd
题面触发词：前缀/后缀 gcd
适用数据范围：n≤2e5
时间复杂度：O(n log V)
空间复杂度：O(n)
你只需要改这里：
- 输出需求
常见错误：
- 0 的 gcd 处理
最小样例：
输入:
4
12 18 6 3
输出:
12 6 6 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = gcdll(pre[i - 1], a[i]);
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << pre[i];
    }
    cout << "\n";
    return 0;
}
```

## 浮点比较
```cpp
/*
【模板名】浮点比较
页眉：模块名=数学 | 页码=____ | 触发词=精度/浮点
题面触发词：浮点比较、误差
适用数据范围：double
时间复杂度：O(1)
空间复杂度：O(1)
你只需要改这里：
- eps 大小
常见错误：
- 直接用 == 比较 double
最小样例：
输入:
0.1 0.2 0.3
输出:
EQ
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    double x = a + b;
    const double eps = 1e-9;
    if (fabs(x - c) < eps) cout << "EQ\n";
    else cout << "NE\n";
    return 0;
}
```

## 分数比较（避免精度误差）
```cpp
/*
【模板名】分数比较
页眉：模块名=数学 | 页码=____ | 触发词=分数/比较大小
题面触发词：分数大小比较
适用数据范围：int64
时间复杂度：O(1)
空间复杂度：O(1)
你只需要改这里：
- 分子分母输入
常见错误：
- 直接转成 double
最小样例：
输入:
1 3
2 5
输出:
LT
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c, d;
    if (!(cin >> a >> b)) return 0;
    cin >> c >> d;
    i128 left = (i128)a * d;
    i128 right = (i128)c * b;
    if (left < right) cout << "LT\n";
    else if (left > right) cout << "GT\n";
    else cout << "EQ\n";
    return 0;
}
```

## __int128 输入输出
```cpp
/*
【模板名】__int128 输入输出
页眉：模块名=数学 | 页码=____ | 触发词=大整数
题面触发词：超大整数
适用数据范围：超过 64 位
时间复杂度：O(位数)
空间复杂度：O(1)
你只需要改这里：
- 输入来源
常见错误：
- 直接用 cout 输出 __int128
最小样例：
输入:
12345678901234567890
输出:
12345678901234567890
*/
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;

string to_string_i128(i128 x) {
    if (x == 0) return "0";
    bool neg = false;
    if (x < 0) { neg = true; x = -x; }
    string s;
    while (x > 0) {
        int d = (int)(x % 10);
        s.push_back(char('0' + d));
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    i128 x = 0;
    for (char ch : s) x = x * 10 + (ch - '0');
    cout << to_string_i128(x) << "\n";
    return 0;
}
```
