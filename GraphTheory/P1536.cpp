#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <string>

const int MAX_N = 1;
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1005;

int par[N], rak[N];

int n, m;
int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (rak[x] < rak[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rak[x] == rak[y]) rak[x]++;
  }
}

void solve() {
  memset(rak, 0, sizeof rak);
  for (int i = 1; i <= n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    unite(a, b);
  }
  int res = -1;
  for (int i = 1; i <= n; i++) {
    if (par[i] == i) res++;
  }
  printf("%d\n", res);
}
int main() {

  while (true) {
    scanf("%d", &n);
    if (n == 0) break;
    scanf("%d", &m);
    solve();
  }

  return 0;
}