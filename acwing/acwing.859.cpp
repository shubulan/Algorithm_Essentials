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

const int N = 100005, M = 200010, INF = 0x3f3f3f3f;

int p[N];
int n, m;
struct Edge {
  int a, b, w;
  bool operator<(const Edge &W) const {
    return w < W.w;
  }
};

Edge edges[M];

int find(int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  p[x] = y;
}


int kruskal() {
  for (int i = 0; i <= n; i++) p[i] = i;
  sort(edges, edges + m);
  int res = 0, cnt = 0;
  for (int i = 0; i < m; i++) {
    int a = edges[i].a, b = edges[i].b, c = edges[i].w;
    a = find(a);
    b = find(b);
    if (a != b) {
      // unite(a, b);
      p[a] = b;
      res += c;
      cnt++;
    }
  }
  if (cnt == n - 1) return res;
  return INF;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    edges[i].w = c;
    edges[i].a = a;
    edges[i].b = b;
  }
  int res = kruskal();

  if (res != INF) printf("%d\n", res);
  else printf("impossible\n");

  return 0;
}