#include <algorithm>
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

const int MAX_N = 100000, MAX_M = 200000;
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct edge {
  int f, t, v;
};

edge e[MAX_M + 5];
int d[MAX_N + 5];
int n, m, s;

void solve(int s) {
  memset(d, 0x7f, sizeof(d));
  d[s] = 0;
  while (true) {
    int flag = 0;
    for (int i = 0; i < m; i++) {
      if (d[e[i].t] > d[e[i].f] + e[i].v) {
        d[e[i].t] = d[e[i].f] + e[i].v;
        flag = 1;
      }
    }
    if (!flag) break;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", d[i]);
  }
  printf("\n");
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &e[i].f, &e[i].t, &e[i].v);
  }
  solve(s);

  return 0;
}