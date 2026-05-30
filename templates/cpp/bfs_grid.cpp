/*
【模板名】网格 BFS（最短步数）
页眉：模块名=BFS | 页码=____ | 触发词=网格/最短路/等权
题面触发词：网格最短步数、每步代价相同
适用数据范围：n,m≤2000
时间复杂度：O(nm)
空间复杂度：O(nm)
你只需要改这里：
- 起点终点字符
- 4/8 方向
常见错误：
- 忘记标记访问
最小样例：
输入:
3 3
S..
.#.
..T
输出:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    // 改这里：网格行列大小
    // 读入网格
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    queue<pair<int,int>> q;
    // dist = -1 表示未访问
    vector<vector<int>> dist(n, vector<int>(m, -1));
    int sx = -1, sy = -1, tx = -1, ty = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 找起点/终点
            if (g[i][j] == 'S') { sx = i; sy = j; }
            if (g[i][j] == 'T') { tx = i; ty = j; }
        }
    }
    // 从起点开始 BFS
    q.push({sx, sy});
    dist[sx][sy] = 0;
    // 改这里：4 方向或 8 方向
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            // 边界和墙判断
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    // 若不可达，dist 为 -1
    cout << dist[tx][ty] << "\n";
    return 0;
}
