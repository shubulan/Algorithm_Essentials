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
int n;
const int N = 1000005;
int a[N], b[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) b[i] = i;
  stable_sort(b + 1, b + n + 1, [](int l, int r) { return a[l] < a[r]; });
  LL res = 0, s = 0;
  for (int i = 1; i <= n; i++) {
    printf("%d ", b[i]);
    res += s;
    s += a[b[i]];
  }
  printf("\n%.2f\n", (double)res / n);

  return 0;
}