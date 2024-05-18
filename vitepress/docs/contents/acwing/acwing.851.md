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
bool st[N];

void spfa() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  queue<int> que;
  que.push(1);
  while (que.size()) {
    int x = que.front();
    que.pop();
    st[x] = false; // st 表示 x 是否在队列中
    for (int i = h[x]; ~i; i = nx[i]) {
      int p = e[i], c = w[i];
      if (dist[x] + c < dist[p]) {
        if (!st[p]) { // 处理重边的情况
          que.push(p);
          st[p] = true;
        }
        dist[p] = dist[x] + c;
      }
    }
  }
}

void add(int a, int b, int c) {
  e[idx] = b;
  w[idx] = c;
  nx[idx] = h[a];
  h[a] = idx++;
}

int n, m;
int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }
  spfa();
  if (dist[n] == 0x3f3f3f3f) cout << "impossible" << endl;
  else cout << dist[n] << endl;

  

  return 0;
}
```