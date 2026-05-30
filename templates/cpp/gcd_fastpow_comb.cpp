/*
【模板名】gcd/lcm/快速幂/组合数
页眉：模块名=数学 | 页码=____ | 触发词=gcd/快速幂/组合数
题面触发词：最大公约数、最小公倍数、幂、组合数
适用数据范围：int64，组合数需模为质数
时间复杂度：O(log n) 或 O(n)
空间复杂度：O(n)
你只需要改这里：
- 模数 mod
- 组合数上限
常见错误：
- mod 不是质数仍用费马逆元
最小样例：
输入:
5 2 1000000007
输出:
10
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

ll modpow(ll a, ll e, ll mod) {
    // 快速幂：a^e % mod
    ll r = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

struct Comb {
    ll mod;
    vector<ll> fact, invfact;
    void init(int n, ll m) {
        mod = m;
        fact.assign(n + 1, 1);
        invfact.assign(n + 1, 1);
        // 阶乘
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
        // 费马逆元（要求 mod 为质数）
        invfact[n] = modpow(fact[n], mod - 2, mod);
        for (int i = n; i >= 1; i--) invfact[i - 1] = invfact[i] * i % mod;
    }
    ll C(int n, int k) {
        if (k < 0 || k > n) return 0;
        // 组合数 C(n,k)
        return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    ll mod;
    if (!(cin >> n >> k >> mod)) return 0;
    // 改这里：n 为上限，k 为选取数，mod 需为质数
    Comb comb;
    comb.init(n, mod);
    cout << comb.C(n, k) << "\n";
    return 0;
}
