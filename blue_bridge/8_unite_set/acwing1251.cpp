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
const int N = 20005;
int par[N], rak[N];
int n, m;
void init() {
  for (int i = 0; i <= n; i++) par[i] = i;
}
int find(int a) {
  return a == par[a] ? a : par[a] = find(par[a]);
}
bool same(int a, int b) {
  return find(a) == find(b);
}
void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (rak[a] < rak[b]) {
    par[a] = b;
  } else {
    par[b] = a;
    if (rak[a] == rak[b]) rak[a]++;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    unite(a, b);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (same(a, b)) printf("Yes\n");
    else printf("No\n");
  }

  return 0;
}