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

const int N = 505, M = 100005;

int h[N], e[M], w[M], nx[M], idx;
int dis[N], st[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    nx[idx] = h[a];
    h[a] = idx++;
}

int dijkstraI() {
  dis[1] = 0;
  for (int i = 0; i < n - 1; i++) {
    int mi = -1;
    for (int i = 1; i <= n; i++) {
      if (st[i]) continue;
      if (mi == -1 || dis[i] < dis[mi]) mi = i;
    }

    st[mi] = 1;
    for (int i = h[mi]; ~i; i = nx[i]) {
      int x = e[i], c = w[i];
      dis[x] = min(dis[x], dis[mi] + c);
    }
  }
}

int main() {
  cin >> n >> m;
  memset(dis, 0x3f, sizeof dis);
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
   int a, b, c;
   cin >> a >> b >> c;
   add(a, b, c);
  }
  dijkstraI();
  if (dis[n] == 0x3f3f3f3f) cout << -1 << endl;
  else cout << dis[n] << endl;  

  return 0;
}
```