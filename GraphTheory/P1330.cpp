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
typedef pair<int, int> PII;
const int N = 10005;
int n, m;
vector<int> G[N];
int color[N], ct[3], res;
bool dfs(int x, int c) {
  color[x] = c;
  ct[c]++;
  int vc = -c + 3;
  for (int i = 0; i < G[x].size(); i++) {
    int nd = G[x][i];
    if (color[nd] == c) return false;
    if (!color[nd] && !dfs(nd, vc)) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    ct[2] = ct[1] = 0;
    if (color[i]) continue;
    if (!dfs(i, 1)) {
      flag = 1;
      break;
    }
    res += min(ct[1], ct[2]);
  }
  if (flag)
    printf("Impossible\n");
  else
    printf("%d\n", res);

  return 0;
}
