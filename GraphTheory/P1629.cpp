#include <algorithm>
#include <climits>
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
const int N = 1005;
int d[N][N];
int n, m;
LL res;
int dis[N];
struct edge {
  int nd, w;
};
vector<edge> G1[N], G2[N];

void warshall_floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min((LL)d[i][k] + (LL)d[k][j], (LL)d[i][j]);
      }
    }
  }
}

void dijistra(vector<edge> G[N]) {
  memset(dis, 0x7f, sizeof dis);
  priority_queue<PII, vector<PII>, greater<PII>> que;
  que.push({0, 1});
  while (!que.empty()) {
    PII nd = que.top();
    que.pop();
    int x = nd.second, y = nd.first;
    if (dis[x] < y) continue;
    dis[x] = y;
    for (int i = 0; i < G[x].size(); i++) {
      int z = G[x][i].nd, w = G[x][i].w;
      if (dis[z] > dis[x] + w) {
        dis[z] = dis[x] + w;
        que.push({dis[z], z});
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    G1[a].push_back({b, c});
    G2[b].push_back({a, c});
  }
  dijistra(G1);
  for (int i = 2; i <= n; i++) res += dis[i];
  dijistra(G2);
  for (int i = 2; i <= n; i++) res += dis[i];
  printf("%lld\n", res);

  return 0;
}