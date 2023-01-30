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
/**
 * 区间合并模板题
*/
using namespace std;
typedef long long LL;
typedef pair<long long, long long> PII;
const int N = 20005;
int a[N], b[N];
LL n, res;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    res += b[i] - a[i];
    if (i < n - 1 && a[i + 1] < b[i]) 
      res -= b[i] - a[i + 1];
  }
  printf("%d\n", res);

  return 0;
}