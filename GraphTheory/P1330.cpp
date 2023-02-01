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

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 10005;
int n, m;
vector<int> G[N];
int color[N];
int c1, c2, res;
bool dfs(int b, int c) {
  int iv = c == 1 ? -1 : 1;
  color[b] = c;
  if (c == 1) c1++;
  else c2++;
  for (int i = 0; i < G[b].size(); i++) {
    if (color[G[b][i]] == c) return false;
    if (color[G[b][i]] == 0 && !dfs(G[b][i], iv)) return false;
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
    c1 = c2 = 0;
    if (color[i] != 0) continue;
    if (!dfs(i, 1)) {
      flag = 1;
      break;
    }
    res += min(c1, c2);
  }
  if (flag) printf("Impossible\n");
  else printf("%d\n", res);

  return 0;
}
