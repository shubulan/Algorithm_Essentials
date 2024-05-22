# 最短路

## BFS

* [走迷宫](https://www.acwing.com/problem/content/846/)
    * [code](../acwing/acwing.844.md)
* [八数码](https://www.acwing.com/problem/content/847/)
    * [八数码](../acwing/acwing.845.md)
### 较难的应用
* [P1144 最短路计数](https://www.luogu.com.cn/problem/P1144)
    * [code](../luogu/GraphTheory/P1144.md)

## dijkstra 算法
> 模板

要点：
* 不需要 vs 数组，只需要 dis 数组
```c++
void dijkstra() {
  memset(dis, 0x3f, sizeof dis);
  priority_queue<PII, vector<PII>, greater<PII>> heap;
  heap.push({0, 1});
  while (heap.size()) {
    PII nd = heap.top();
    heap.pop();
    int ww = nd.first, x = nd.second;
    if (dis[x] <= ww) continue;
    for (int i = h[x]; ~i; i = nx[i]) {
      int j = e[i], nw = w[i];
      if (nw + ww < dis[j]) {
        dis[j] = nw + ww;
        heap.push({nw + ww, j});
      }
    }
  }
}
```
* [【模板】单源最短路径（弱化版）](https://www.luogu.com.cn/problem/P3371)
* [【模板】单源最短路径（标准版）](https://www.luogu.com.cn/problem/P4779)
    * [code](../luogu/GraphTheory/P4779.md)

### 应用题
* [dijkstra 求最短路I](https://www.acwing.com/problem/content/851/)
    * [dijkstra 求最短路I](../acwing/acwing.849.md)
* [dijkstra 求最短路II](https://www.acwing.com/problem/content/852/)
    * [dijkstra 求最短路II](../acwing/acwing.850.md)
* [P1629 邮递员送信](https://www.luogu.com.cn/problem/P1629)
    * [code](../luogu/GraphTheory/P1629.md)
* [3112. 访问消失节点的最少时间](https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes/description/)
```c++
class Solution {
public:
    using PII = pair<int, int>;
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<vector<int>>> G(n, vector<vector<int>>());
        for (int i = 0; i < edges.size(); i++) {
            vector<int> &e = edges[i];
            G[e[0]].push_back({e[1], e[2]});
            G[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> dist(n, 0x3f3f3f3f);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.push({0, 0});
        while (q.size()) {
            auto [t, x] = q.top(); q.pop();
            if (dist[x] <= t) continue;
            dist[x] = t;
            for (int i = 0; i < G[x].size(); i++) {
                int a = G[x][i][0], b = G[x][i][1], c = G[x][i][2];
                if (t + b >= disappear[a]) continue;
                if (t + b < dist[a]) {
                    q.push({t + b, a});
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (dist[i] == 0x3f3f3f3f) dist[i] = -1;
        return dist;
    }
};
```

## bellman-ford/spfa
> 原理：遍历所有边，如果该边可以优化一条路径，就优化该路径
### bellman-ford
* [有边数限制的最短路](https://www.acwing.com/problem/content/855/)
    * [code](../acwing/acwing.853.md)

### spfa
> 队列优化版：如果更新了该路径，就放入队列中
* [spfa 求最短路](https://www.acwing.com/problem/content/853/)
    * [code](../acwing/acwing.851.md)
* [spfa 判断负环](https://www.acwing.com/problem/content/854/)
    * 虚拟起点
    * 计算某一终点的的最短路径长度，如果超过 n 那么说明有负环
    * [code](../acwing/acwing.852.md)

## floyd-warshall
> 集合上的动态规划算法
```c++
const int N = 205, inf = 0x3f3f3f3f;
int G[N][N];
void floyd(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (G[i][k] != inf && G[k][j] != inf) // 只有两边畅通时，才做松弛操作
            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }
}
```
* [模板：Floyd 求最短路](https://www.acwing.com/problem/content/856/)
    * [code](../acwing/acwing.854.md)

### 应用
* [P1119 灾后重建](https://www.luogu.com.cn/problem/P1119)
    * [code](../luogu/GraphTheory/P1119.md)

## 最长路
> 正权变负权，使用 bellman-ford 算法
* [P1807 最长路](https://www.luogu.com.cn/problem/P1807)
    * [code](../luogu/GraphTheory/P1807.md)
