#include <algorithm>
#include <cmath>
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

const int N = 100005;
const int D = (1 << 20) + 10;
int n, m, x;
int vis[D];
int f[N], g[N];

int main() {
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    f[i] = vis[x ^ t];
    vis[t] = i;
    printf("%d\n", f[i]);
    g[i] = max(g[i - 1], f[i]);
  }
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (g[r] >= l)
      puts("yes");
    else
      puts("no");
  }

  return 0;
}
