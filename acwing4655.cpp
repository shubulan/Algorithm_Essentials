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
const int N = 100005;
int n, m;
LL arr[N];
int d[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i]);
  }
  scanf("%d", &m);
  int x = m;
  while (x--) {
    int l, r;
    scanf("%d%d", &l, &r);
    d[l] += 1;
    d[r + 1] -= 1;
  }
  LL s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++) {
    d[i] += d[i - 1];
    s1 += d[i] * arr[i];
  }
  sort(d + 1, d + n + 1);
  sort(arr + 1, arr + n + 1);
  for (int i = 1; i <= n; i++) {
    s2 += d[i] * arr[i];
  }

  printf("%lld\n", s2 - s1);

  return 0;
}
