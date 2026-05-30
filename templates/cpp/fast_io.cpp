/*
【模板名】快读快写
页眉：模块名=基础模板 | 页码=____ | 触发词=大输入/卡常
题面触发词：输入很大、IO 成为瓶颈
适用数据范围：数据总量≥1e6
时间复杂度：O(n)
空间复杂度：O(1)
你只需要改这里：
- 读入类型与输出内容
常见错误：
- 忘记处理负数
最小样例：
输入:
3
1 2 3
输出:
6
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FastScanner {
    static const int BUFSIZE = 1 << 20;
    int idx, size;
    char buf[BUFSIZE];
    FastScanner() : idx(0), size(0) {}

    inline char read() {
        if (idx >= size) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }

    bool nextLong(ll &out) {
        char c = read();
        if (!c) return false;
        while (c != '-' && (c < '0' || c > '9')) {
            c = read();
            if (!c) return false;
        }
        ll sign = 1;
        if (c == '-') { sign = -1; c = read(); }
        ll val = 0;
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = read();
        }
        out = val * sign;
        return true;
    }

    bool nextString(string &s) {
        char c = read();
        if (!c) return false;
        while (isspace((unsigned char)c)) {
            c = read();
            if (!c) return false;
        }
        s.clear();
        while (c && !isspace((unsigned char)c)) {
            s.push_back(c);
            c = read();
        }
        return true;
    }
};

struct FastOutput {
    static const int BUFSIZE = 1 << 20;
    int idx;
    char buf[BUFSIZE];
    FastOutput() : idx(0) {}
    ~FastOutput() { flush(); }

    void flush() {
        if (idx) {
            fwrite(buf, 1, idx, stdout);
            idx = 0;
        }
    }

    void pushChar(char c) {
        if (idx >= BUFSIZE) flush();
        buf[idx++] = c;
    }

    void writeLong(ll x, char end = '\n') {
        if (x == 0) {
            pushChar('0');
            pushChar(end);
            return;
        }
        if (x < 0) { pushChar('-'); x = -x; }
        char s[32];
        int n = 0;
        while (x > 0) { s[n++] = char('0' + x % 10); x /= 10; }
        for (int i = n - 1; i >= 0; i--) pushChar(s[i]);
        pushChar(end);
    }
};

int main() {
    FastScanner fs;
    FastOutput fo;

    ll n;
    if (!fs.nextLong(n)) return 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        fs.nextLong(x);
        sum += x;
    }
    fo.writeLong(sum);
    return 0;
}
