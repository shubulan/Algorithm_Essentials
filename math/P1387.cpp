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
const int MAX_N = 105;
int a[MAX_N][MAX_N];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  // 动态规划 复杂度是n2。实际上n3次方就够，直接用前缀和
  int res = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     scanf("%d", &a[i][j]);
  //     if (a[i][j] == 1)
  //       a[i][j] = a[i][j] + min(a[i - 1][j],
  //                   min(a[i - 1][j - 1], a[i][j - 1]));
  //     if (a[i][j] > res) res = a[i][j];
  //   }
  // }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
      for (int k = 1; k <= min(i, j); k++) {
        int s = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
        if (s == k * k) {
          res = max(k, res);
        }
      }
    }
  }
  printf("%d\n", res);

  return 0;
}