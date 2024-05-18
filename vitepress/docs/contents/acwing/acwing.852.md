```c++
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;

int h[N], e[N], nx[N], w[N], idx;
int dist[N];
int cnt[N];
bool st[N];
int n, m;
bool spfa() {
//   memset(dist, 0x3f, sizeof dist); // 无需初始化，默认为 0 即可
  queue<int> que;
  // 将所有点都放入队列中。因为负环不一定从0能到达
  // 此时 dist 的含义变成了：以节点 i 为终点的最短路径长度，无论起始点。
  for (int i = 1; i <= n; i++) {
    que.push(i);
    st[i] = true;
  }
  while (que.size()) {
    int x = que.front();
    que.pop();
    st[x] = false;
    for (int i = h[x]; ~i; i = nx[i]) {
      int p = e[i], c = w[i];
      if (dist[x] + c < dist[p]) {
        if (!st[p]) { // 处理重边的情况
          que.push(p);
          st[p] = true;
        }
        dist[p] = dist[x] + c;
        cnt[p] = cnt[x] + 1; // 计算到节点 p 的最短路径的边数
        if (cnt[p] >= n) return true; // 最短路径边超过 n 条，说明点有 n + 1 个。说明必然存在负权回路。
      }
    }
  }
  return false;
}

void add(int a, int b, int c) {
  e[idx] = b;
  w[idx] = c;
  nx[idx] = h[a];
  h[a] = idx++;
}


int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }

  cout << (spfa() ? "Yes" : "No") << endl;

  return 0;
}
```