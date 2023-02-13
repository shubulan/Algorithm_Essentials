#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 5005, M = 400005;
struct {
  int nd, nx, w;
} e[M];
int cnt;
int head[N];
void insert(int a, int b, int w) {
  e[++cnt].nd = b;
  e[cnt].nx = head[a];
  e[cnt].w = w;
  head[a] = cnt;
}
int n, m;

int vis[N];
int mincost[N];
const string Prime() {
  fill(mincost, mincost + N, INT_MAX);
  
  int res = 0;
  mincost[1] = 0;
  while (true) {
    int v = -1;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      if (v == -1 || mincost[i] < mincost[v]) v = i;
    }
    if (v == -1) break;
    if (mincost[v] == INT_MAX) return "orz";
    vis[v] = 1;
    res += mincost[v];
    mincost[v] = 0;
    for (int i = head[v]; i; i = e[i].nx) {
      mincost[e[i].nd] = min(e[i].w, mincost[e[i].nd]);
    }
  }
  return to_string(res);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    insert(a, b, w);
    insert(b, a, w);
  }
  printf("%s\n", Prime().c_str());

  return 0;
}