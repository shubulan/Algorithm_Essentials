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
const int N = 1000005;
PII a[N];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a, a + n, [](PII &l, PII &r) { return l.second < r.second; });
  int ct = 0, res = 0;
  for (int i = 0; i < n; i++) {
    if (ct <= a[i].first) {
      res++;
      ct = a[i].second;
    }
  }
  printf("%d\n", res);

  return 0;
}