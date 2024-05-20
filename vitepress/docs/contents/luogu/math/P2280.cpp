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
const int MAX_N = 5005;
int n, m, res;
int a[MAX_N][MAX_N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    a[x + 1][y + 1] = v;
  }

  for (int i = 1; i <= 5002; i++) {
    for (int j = 1; j <= 5002; j++) {
      a[i][j] += (LL)a[i - 1][j] + (LL)a[i][j - 1] - a[i - 1][j - 1];
      int dx = min(i, m), dy = min(j, m);
      res = max(res, a[i][j] - a[i - dx][j] - a[i][j - dy] + a[i - dx][j - dy]);
    }
  }
  printf("%d\n", res);

  return 0;
}