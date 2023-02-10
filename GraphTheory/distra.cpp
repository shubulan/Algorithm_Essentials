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
#include <climits>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 100005;
int n, m, s;
struct Edge{
    int nd, w;
};
vector<Edge> G[N];
int used[N], d[N];

void dijkstra(int s) {
    fill(used, used + N, 0);
    fill(d, d + N, INT_MAX);
    priority_queue<PII, vector<PII>, greater<PII>> que;
    que.push({0, s});
    while (!que.empty()) {
        PII node = que.top(); que.pop();
        int v = node.second, w = node.first;
        if (used[v]) continue;
        used[v] = d[v] = w;
        for (int i = 0; i < G[v].size(); i++) {
            if (used[G[v][i].nd]) continue;
            if (d[G[v][i].nd] > d[v] + G[v][i].w) {
                que.push({d[v] + G[v][i].w, G[v][i].nd});
            }
        }
    }
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    G[a].push_back({b, w});
  }
  dijkstra(s);
  for (int i = 1; i <= n; i++) {
      printf("%d ", d[i]);
  }
  printf("\n");

  return 0;
}
