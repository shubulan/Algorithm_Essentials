#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 40005;

int n, m;
struct edge{
  int b, w;
};
int par[N], rak[N];
vector<edge> G[N];

int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (rak[a] < rak[b]) par[a] = b;
  else {
    par[b] = a;
    if (rak[a] == rak[b]) rak[a]++;
  }
}

int color[N];

bool bfs_bi_graph(int t, int x) {
  color[t] = 1;
  queue<int> que;
  que.push(t);
  while (!que.empty()) {
    int p = que.front(); que.pop();
    int c = -color[p] + 3;
    for (int i = 0; i < G[p].size(); i++) {
      int nd = G[p][i].b, w = G[p][i].w;
      if (w <= x) continue;
      if (color[nd] == c) continue;
      else if (!color[nd]) {
        color[nd] = c;
        que.push(nd);
      } else {
        return false;
      }
    }
  }
  return true;
}

bool bi_graph(int x) { // 移除掉所有 > x的边，是否能形成二分图？
  memset(color, 0, sizeof color);
  for (int i = 1; i <= n; i++) {
    if (color[i]) continue;
    if (!bfs_bi_graph(i, x)) return false;
  }
  return true;
}
bool check(int x) {
  return bi_graph(x);
}

bool same(int x, int y) { return find(x) == find(y); }

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    // edges.push_back({a, b, w});
    G[a].push_back({b, w});
    G[b].push_back({a, w});
  }
  // sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
  //   return a.w > b.w;
  // });
  // for (int i = 1; i <= 2 * n; i++) {
  //   rak[i] = 0, par[i] = i;
  // }
  // for (int i = 0; i < edges.size(); i++) {
  //   int a = edges[i].a, b = edges[i].b, w = edges[i].w;
  //   if (same(a, b)) {
  //     printf("%d\n", w);
  //     exit(0);
  //   }
  //   unite(a, b + n);
  //   unite(a + n, b);
  // }
  // printf("0\n");
  // 方法二
  int l = 0, r = 1e9 + 10;
  while (l < r) {
    int mid = (l + r) / 2;

    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", l);


  return 0;
}