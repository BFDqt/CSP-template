# 07 数据结构模板
页眉：模块名=数据结构 | 页码=____ | 触发词=区间/最值/查询
翻页索引：
- 树状数组
- 线段树
- 单调栈/单调队列
- Sparse Table
- 堆/priority_queue
- set lower_bound/upper_bound
- 什么时候用 set/map/priority_queue

## 树状数组（Fenwick）
{{include:templates/cpp/fenwick.cpp}}

## 线段树（区间和 + 区间加）
{{include:templates/cpp/segment_tree.cpp}}

## 单调栈（求每个元素左侧更小）
```cpp
/*
【模板名】单调栈（前一个更小）
页眉：模块名=数据结构 | 页码=____ | 触发词=单调栈/最近更小
题面触发词：最近更小/更大、下一个更小
适用数据范围：n≤2e5
时间复杂度：O(n)
空间复杂度：O(n)
你只需要改这里：
- 比较方向（更小/更大）
常见错误：
- 栈为空时访问 top
最小样例：
输入:
5
2 1 4 3 5
输出:
0 0 2 2 4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> ans(n + 1, 0);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        ans[i] = st.empty() ? 0 : st.back();
        st.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}
```

## 单调队列（滑动窗口最大值）
```cpp
/*
【模板名】单调队列（窗口最大值）
页眉：模块名=数据结构 | 页码=____ | 触发词=滑动窗口/区间最值
题面触发词：滑动窗口最大值/最小值
适用数据范围：n≤2e5
时间复杂度：O(n)
空间复杂度：O(n)
你只需要改这里：
- 比较方向（最大/最小）
常见错误：
- 忘记弹出窗口外元素
最小样例：
输入:
8 3
1 3 -1 -3 5 3 6 7
输出:
3 3 5 5 6 7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) {
            if (i >= k) cout << " ";
            cout << a[dq.front()];
        }
    }
    cout << "\n";
    return 0;
}
```

## Sparse Table（RMQ 最小值）
```cpp
/*
【模板名】Sparse Table
页眉：模块名=数据结构 | 页码=____ | 触发词=RMQ/静态区间最值
题面触发词：静态区间最小/最大值
适用数据范围：n≤2e5, q≤2e5
时间复杂度：预处理 O(n log n)，查询 O(1)
空间复杂度：O(n log n)
你只需要改这里：
- min/max
常见错误：
- log 预处理
最小样例：
输入:
5 2
1 3 2 5 4
1 3
2 5
输出:
1
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int K = 0;
    while ((1 << K) <= n) K++;
    vector<vector<ll>> st(K, vector<ll>(n + 1));
    vector<int> lg(n + 1, 0);
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++) st[0][i] = a[i];
    for (int k = 1; k < K; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int k = lg[r - l + 1];
        ll ans = min(st[k][l], st[k][r - (1 << k) + 1]);
        cout << ans << "\n";
    }
    return 0;
}
```

## 堆（priority_queue）
```cpp
/*
【模板名】堆（优先队列）
页眉：模块名=数据结构 | 页码=____ | 触发词=取最小/最大
题面触发词：取最小值/最大值、实时最值
适用数据范围：n≤2e5
时间复杂度：插入/取顶 O(log n)
空间复杂度：O(n)
你只需要改这里：
- 大根堆或小根堆
常见错误：
- greater 用错
最小样例：
输入:
3
5 1 2
输出:
1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        pq.push(x);
    }
    cout << pq.top() << "\n";
    return 0;
}
```

## set 的 lower_bound/upper_bound
```cpp
/*
【模板名】set 查找最接近
页眉：模块名=数据结构 | 页码=____ | 触发词=前驱/后继
题面触发词：前驱/后继、最近元素
适用数据范围：n≤2e5
时间复杂度：O(log n)
空间复杂度：O(n)
你只需要改这里：
- 输出规则
常见错误：
- 迭代器越界
最小样例：
输入:
5 2
1 3 5 7 9
6
4
输出:
7
5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        s.insert(x);
    }
    while (q--) {
        ll x; cin >> x;
        auto it = s.lower_bound(x);
        if (it == s.end()) cout << "NONE\n";
        else cout << *it << "\n";
    }
    return 0;
}
```

## 什么时候用 set / map / priority_queue
- set：需要有序去重、找前驱后继。
- map：需要有序键值映射。
- priority_queue：反复取当前最小/最大值。
