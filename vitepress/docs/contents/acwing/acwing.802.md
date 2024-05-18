```c++
#include <algorithm>
#include <cassert>
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

const int N = 100005;

int b[N * 3], cnt = 1;
PII a[N], q[N];
int d[N * 3];
int get(int x) {
  int l = 1, r = cnt - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (b[mid] == x) {
      return mid;
    } else if (b[mid] > x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}
int main() {
  int n, m;
  cin >> n >> m;
  b[0] = -0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    b[cnt++] = a[i].first;
  }
  for (int i = 0; i < m; i++) {
    cin >> q[i].first >> q[i].second;
    b[cnt++] = q[i].first;
    b[cnt++] = q[i].second;
  }

  sort(b, b + cnt);
  int *p = unique(b + 1, b + cnt);
  cnt = p - b;

  for (int i = 0; i < n; i++) {
    d[get(a[i].first)] += a[i].second;
  }

  for (int i = 1; i <= cnt; i++) {
    d[i] += d[i - 1];
  }

  for (int j = 0; j < m; j++) {
    cout << d[get(q[j].second)] - d[get(q[j].first) - 1] << endl;
  }

  return 0;
}
```