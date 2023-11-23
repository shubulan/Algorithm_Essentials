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

const int N = 100005, M = 500005;
int n, m, s;
struct edge {
  int t, v;
};
vector<edge> G[N];

unsigned d[N];
int vis[N];
void solve() {
  memset(d, 0xff, sizeof(d));
  d[s] = 0;
  vis[s] = 1;
  while (true) {
    int v = -1, mn = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++) {
      if (vis[i] != 1) continue;
      if (d[i] < mn) {
        v = i, mn = d[i];
      }
    }
    if (v == -1) break;
    vis[v] = 2;
    for (int i = 0; i < G[v].size(); i++) {
      if (vis[G[v][i].t] == 2) continue;
      if (d[G[v][i].t] <= d[v] + G[v][i].v) continue;
      d[G[v][i].t] = d[v] + G[v][i].v;
      vis[G[v][i].t] = 1;
    }
  }
}
void solve2() {
  fill(d, d + N, INT_MAX);
  d[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> que;
  que.push({0, s});
  while (!que.empty()) {
    PII nd = que.top();
    que.pop();
    int mn = nd.first, v = nd.second;
    if (d[v] < mn) continue;
    for (int i = 0; i < G[v].size(); i++) {
      if (d[G[v][i].t] <= d[v] + G[v][i].v) continue;
      d[G[v][i].t] = d[v] + G[v][i].v;
      que.push({d[G[v][i].t], G[v][i].t});
    }
  }
}
void print() {
  for (int i = 1; i <= n; i++) {
    printf("%u ", d[i]);
  }
  printf("\n");
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    G[a].push_back({b, c});
  }
  solve2();
  print();

  return 0;
}