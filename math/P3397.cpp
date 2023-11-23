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
const int MAX_N = 1005;
int a[MAX_N][MAX_N];
int n, m;
void insert(int x1, int y1, int x2, int y2, int c) {
  /**
   * 看清题意，是否需要取模，int能否放下数组。
   */
  a[x1][y1] += c;
  a[x1][y2 + 1] -= c;
  a[x2 + 1][y1] -= c;
  a[x2 + 1][y2 + 1] += c;
}
void sum() {
  /*
  需要自己改范围
  */
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    insert(a, b, c, d, 1);
  }
  sum();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}