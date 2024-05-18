#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;
struct {
  int nd, nx;
} e[N];
int head[N];
int d[N];
int cnt = 0;
void insert(int f, int t) {
  e[++cnt].nd = t;
  e[cnt].nx = head[f];
  head[f] = cnt;
}

// 正向是错误的，
// 可能存在死循环的情况
// 即使解决了死循环也是错误的
int dfs(int b) {
  d[b] = b;

  for (int i = head[b]; i; i = e[i].nx) {
    if (d[e[i].nd])
      d[b] = max(d[e[i].nd], d[b]);
    else
      d[b] = max(dfs(e[i].nd), d[b]);
  }

  return d[b];
}

void dfs(int b, int c) {
  d[b] = c;
  for (int i = head[b]; i; i = e[i].nx) {
    if (!d[e[i].nd]) dfs(e[i].nd, c);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    insert(b, a);
  }
  // 正向
  // for (int i = 1; i <= n; i++) {
  //    if (!d[i]) dfs(i);
  //    printf("%d ", d[i]);
  //}
  // 反向
  for (int i = n; i >= 1; i--) {
    if (!d[i]) dfs(i, i);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", d[i]);
  }
  printf("\n");

  return 0;
}
