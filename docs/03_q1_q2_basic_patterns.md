# 03 Q1/Q2 基础模板
页眉：模块名=Q1/Q2 基础 | 页码=____ | 触发词=计数/排序/前缀和/差分/双指针
翻页索引：
- 计数
- 排序
- 前缀和 1D/2D
- 差分 1D/2D
- 双指针/滑动窗口
- 二分
- 简单贪心
- 简单 BFS
- 简单 DP
- 日期时间
- 坐标压缩

## 计数
```cpp
/*
【模板名】计数/频率统计
页眉：模块名=计数 | 页码=____ | 触发词=统计/次数/频率
题面触发词：统计次数、频率、众数、出现几次
适用数据范围：n≤2e5
时间复杂度：O(n log n)（map） / O(n)（unordered_map）
空间复杂度：O(n)
你只需要改这里：
- 读入字段类型
- 输出格式
常见错误：
- 忘记清空 map
- 用 int 导致溢出
最小样例：
输入:
5
1 2 2 3 3
输出:
1 1
2 2
3 2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    map<ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cnt[x]++;
    }
    for (auto &kv : cnt) {
        cout << kv.first << " " << kv.second << "\n";
    }
    return 0;
}
```

## 排序
```cpp
/*
【模板名】排序与排名
页眉：模块名=排序 | 页码=____ | 触发词=排序/排名/最小/最大
题面触发词：排序、排名、最小/最大、字典序
适用数据范围：n≤1e6
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 排序关键字（升序/降序）
- 输出格式
常见错误：
- 忘记稳定性
- 比较器写反
最小样例：
输入:
5
3 1 4 1 5
输出:
1 1 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
```

## 前缀和 1D
{{include:templates/cpp/prefix_sum_1d.cpp}}

## 前缀和 2D
{{include:templates/cpp/prefix_sum_2d.cpp}}

## 差分 1D
{{include:templates/cpp/difference_1d.cpp}}

## 差分 2D
{{include:templates/cpp/difference_2d.cpp}}

## 双指针 / 滑动窗口
```cpp
/*
【模板名】双指针（最短子段和 ≥ S）
页眉：模块名=双指针 | 页码=____ | 触发词=连续子段/最短/滑动窗口
题面触发词：连续子段、最短/最长满足条件
适用数据范围：n≤2e5（元素非负）
时间复杂度：O(n)
空间复杂度：O(1)
你只需要改这里：
- 条件 sum >= S
- 输出逻辑（最短/最长）
常见错误：
- 元素允许负数时不能用此模板
- 边界 n=0
最小样例：
输入:
5 7
2 3 1 2 4
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
    ll S;
    if (!(cin >> n >> S)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    int ans = n + 1;
    for (int l = 0, r = 0; r < n; r++) {
        sum += a[r];
        while (sum >= S) {
            ans = min(ans, r - l + 1);
            sum -= a[l++];
        }
    }
    if (ans == n + 1) ans = 0;
    cout << ans << "\n";
    return 0;
}
```

## 二分
{{include:templates/cpp/binary_search.cpp}}

## 简单贪心（区间选取最多）
```cpp
/*
【模板名】区间调度（最多不重叠）
页眉：模块名=贪心 | 页码=____ | 触发词=最多区间/不重叠
题面触发词：最多选择、不重叠区间、时间安排
适用数据范围：n≤2e5
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 区间结构与输入
- 输出（数量/列表）
常见错误：
- 排序按右端点
- 忘记更新 last_end
最小样例：
输入:
3
1 3
2 4
3 5
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Seg {
    ll l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<Seg> segs(n);
    for (int i = 0; i < n; i++) cin >> segs[i].l >> segs[i].r;
    sort(segs.begin(), segs.end(), [](const Seg &a, const Seg &b) {
        if (a.r != b.r) return a.r < b.r;
        return a.l < b.l;
    });

    ll last_end = LLONG_MIN / 4;
    int cnt = 0;
    for (auto &s : segs) {
        if (s.l >= last_end) {
            cnt++;
            last_end = s.r;
        }
    }
    cout << cnt << "\n";
    return 0;
}
```

## 简单 BFS（图）
{{include:templates/cpp/bfs_graph.cpp}}

## 简单 DP（方案数）
```cpp
/*
【模板名】线性 DP（爬楼梯）
页眉：模块名=简单 DP | 页码=____ | 触发词=方案数/路径数
题面触发词：方案数、路径数、走法
适用数据范围：n≤1e6
时间复杂度：O(n)
空间复杂度：O(n) 或 O(1)
你只需要改这里：
- 转移公式
- 取模大小
常见错误：
- 忘记取模
- n 很小时初始化错误
最小样例：
输入:
5
输出:
8
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    if (n == 0) {
        cout << 1 << "\n";
        return 0;
    }
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}
```

## 日期时间（日期差）
```cpp
/*
【模板名】日期转天数（用于求差）
页眉：模块名=日期时间 | 页码=____ | 触发词=日期/时间差
题面触发词：日期差、天数、时间跨度
适用数据范围：年份在合理范围内（1900~2100）
时间复杂度：O(1)
空间复杂度：O(1)
你只需要改这里：
- 日期范围和输出格式
常见错误：
- 闰年判断错误
- 月份天数表写错
最小样例：
输入:
2024 2 28
2024 3 1
输出:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

ll date_to_days(int y, int m, int d) {
    static int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    ll days = 0;
    for (int year = 1970; year < y; year++) {
        days += is_leap(year) ? 366 : 365;
    }
    for (int month = 1; month < m; month++) {
        days += mdays[month - 1];
        if (month == 2 && is_leap(y)) days += 1;
    }
    days += d - 1;
    return days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int y1, m1, d1, y2, m2, d2;
    if (!(cin >> y1 >> m1 >> d1)) return 0;
    cin >> y2 >> m2 >> d2;
    ll diff = llabs(date_to_days(y1, m1, d1) - date_to_days(y2, m2, d2));
    cout << diff << "\n";
    return 0;
}
```

## 坐标压缩
```cpp
/*
【模板名】坐标压缩
页眉：模块名=坐标压缩 | 页码=____ | 触发词=值域大/离散化
题面触发词：值域很大、只关心相对大小
适用数据范围：n≤2e5
时间复杂度：O(n log n)
空间复杂度：O(n)
你只需要改这里：
- 需要压缩的数组
- 输出压缩值或映射
常见错误：
- 忘记去重
- 用原值直接下标越界
最小样例：
输入:
5
100 10 100 50 10
输出:
2 0 2 1 0
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++) {
        int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (i) cout << " ";
        cout << id;
    }
    cout << "\n";
    return 0;
}
```
