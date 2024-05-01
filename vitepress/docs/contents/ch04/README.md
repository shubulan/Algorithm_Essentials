# ch04 搜索与图论 I

## 图论 I

### 深度优先搜索

### 广度优先搜索

### 最小生成树>不常用，放在图论 II 中

### 最短路
#### dijkstra
> 模板

要点：
* 不需要 vs 数组，只需要 dis 数组
```
void dijkstra() {
  memset(dis, 0x3f, sizeof dis);
  priority_queue<PII, vector<PII>, greater<PII>> heap;
  heap.push({0, 1});
  while (heap.size()) {
    PII nd = heap.top();
    heap.pop();
    int ww = nd.first, x = nd.second;
    if (dis[x] <= ww) continue;
    dis[x] = ww;
    for (int i = h[x]; ~i; i = nx[i]) {
      int j = e[i], nw = w[i];
      if (nw + ww < dis[j]) {
        heap.push({nw + ww, j});
      }
    }
  }
}
```
* 例题：[3112. 访问消失节点的最少时间](https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes/description/)
```
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