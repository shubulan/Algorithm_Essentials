#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1505, M = 50005;
struct edge{
  int nf, nd, w;
} edges[M];

int degree[N], lon[N];
int n, m;

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    if (v == 1) continue;
    scanf("%d%d%d", &u, &v, &w);
    edges[i].nf = u;
    edges[i].nd = v;
    edges[i].w = -w;
    // G[u].push_back({v, w});
    // degree[v]++;
  }
  // fill(lon, lon + n + 5, INT_MIN);
  fill(lon, lon + n + 5, INT_MAX);
  // queue<int> que;
  // que.push(1);
  // lon[1] = 0;
  // while (!que.empty()) {
  //   int nd = que.front(); que.pop();
  //   for (int i = 0; i < G[nd].size(); i++) {
  //     int ndd = G[nd][i].nd, w = G[nd][i].w;
  //     if (lon[ndd] < lon[nd]+ w) {
  //       lon[ndd] = lon[nd] + w;
  //       que.push(ndd);
  //     }
  //   }
  // }
  lon[1] = 0;
  while (true) {
    int flag = 1;
    for (int i = 0; i < m; i++) {
      int f = edges[i].nf, t = edges[i].nd, w = edges[i].w;
      if (lon[t] <= lon[f] + w) continue;
      flag = 0;
      lon[t] = lon[f] + w;
    }

    if (flag) break;
  }
  if (lon[n] == INT_MAX) {
    printf("%d\n", -1);
  } else {
    printf("%d\n", -lon[n]);
  }
  


  return 0;
}
