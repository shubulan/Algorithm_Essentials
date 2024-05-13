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
const int MAX_N = 6005;
struct {
  int nd, ne;
} e[MAX_N];
int head[MAX_N];  // 每个节点的临界边起点
int cnt = 0;
void insert(int from, int to) {
  cnt++;
  e[cnt].nd = to;
  e[cnt].ne = head[from];
  head[from] = cnt;
}

int v[MAX_N];
int dp[MAX_N][2];
int n;

void dfs(int x) {
  // printf("calc %d\n", x);
  int b = head[x];

  dp[x][1] = v[x];
  for (int i = b; i != 0; i = e[i].ne) {
    int nd = e[i].nd;
    if (dp[nd][0] == 1e7) {
      dfs(nd);
    }
    dp[x][1] += dp[nd][0];
  }

  dp[x][0] = 0;
  for (int i = b; i != 0; i = e[i].ne) {
    int nd = e[i].nd;
    // printf("nd %d\n", nd);
    dp[x][0] += max(dp[nd][0], dp[nd][1]);
  }
  // printf("%d %d %d\n", x, dp[x][1], dp[x][0]);
  // printf("calc %d over\n", x);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = 1e7;
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    insert(b, a);
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (dp[i][0] == 1e7) {
      dfs(i);
    }
    res = max(dp[i][0], res);
    res = max(dp[i][1], res);
  }
  printf("%d\n", res);
  return 0;
}