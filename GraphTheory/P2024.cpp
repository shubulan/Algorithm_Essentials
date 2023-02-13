#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 150000 + 10;

int par[N], rak[N];
int n, k, ans;
void init(int n) {
  for (int i = 0; i < n; i++) par[i] = i, rak[i] = 0;
}
int find(int a) {
  return a == par[a] ?  a : par[a] = find(par[a]);
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rak[x] < rak[y]) par[x] = y;
  else {
    par[y] = x;
    if (rak[x] == rak[y]) rak[x]++;
  }
}
bool same(int a, int b) {
  return find(a) == find(b);
}

int main() {
  scanf("%d%d", &n, &k);
  init(n * 3 + 5);
  for (int i = 0; i < k; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (b < 1 || b > n || c < 1 || c > n) {
      ans++;
      continue;
    }
    if (a == 1) {
      if (same(b, c + n) || same(b, c + 2 * n)) {
        ans++;
        continue;
      }
      unite(b, c);
      unite(b + n, c + n);
      unite(b + 2 * n, c + 2 * n);
    } else if (a == 2) {
      if (same(b, c) || same(b, c + 2 * n)) {
        ans++;
        continue;
      }
      unite(b, c + n);
      unite(b + n, c + 2 * n);
      unite(b + 2 * n, c);
    }
  }
  printf("%d\n", ans);

  return 0;
}