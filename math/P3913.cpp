#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
/**
 * 主要是对行 和 列进行去重。
 * 使用unordered_set按理来说几乎是线性复杂度的，不知道为啥过不了。
 * sort一下nlogn复杂度，然后再unique能过，很奇怪
 */
const int MAX_N = 1000005;
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int R[MAX_N], C[MAX_N];
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &R[i], &C[i]);
  }
  sort(R, R + k);
  sort(C, C + k);
  LL x = unique(R, R + k) - R;
  LL y = unique(C, C + k) - C;

  LL res = (x + y) * n - x * y;
  printf("%lld\n", res);
  return 0;
}