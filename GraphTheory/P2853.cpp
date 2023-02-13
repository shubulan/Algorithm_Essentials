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
const int N = 1005, K = 105;
vector<int> G[N];
int used[N], vis[N];
int cows[K];
int k, n, m, res;

void bfs(int s) {
  fill(vis, vis + n + 5, 0);
  queue<int> que;
  que.push(s);
  vis[s] = 1;
  while (!que.empty()) {
    int nd = que.front(); que.pop();
    used[nd]++;
    for (int i = 0; i < G[nd].size(); i++) {
      int ndd = G[nd][i];
      if (vis[ndd]) continue;
      vis[ndd] = 1;
      que.push(ndd);
    }
  }
}
int main() {
  scanf("%d%d%d", &k, &n, &m);
  for (int i = 0; i < k; i++) scanf("%d", &cows[i]);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
  }
  for (int i = 0; i < k; i++) {
    bfs(cows[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (used[i] == k) res++;
  }
  printf("%d\n", res);

  return 0;
}