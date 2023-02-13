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
const int N = 1000006;
int cnt[N], used[N];
int n, m, mod = 100003;
vector<int> G[N];
void bfs(int s) {
  used[s] = 1;
  cnt[s] = 1;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int x = que.front(); que.pop();
    for (int i = 0; i < G[x].size(); i++) {
      int nd = G[x][i];
      if (!used[nd]) {
        que.push(nd);
        used[nd] = used[x] + 1;
      }
      if (used[x] + 1 == used[nd]) {
        cnt[nd] = (cnt[x] + cnt[nd]) % mod;
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bfs(1);
  for (int i = 1; i <= n; i++) printf("%d\n", cnt[i]);

  return 0;
}