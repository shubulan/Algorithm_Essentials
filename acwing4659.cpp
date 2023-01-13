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
typedef pair<int, int> PII;
const int N = 100005;
int n, m;
int arr[N][2]; 
bool check(int mid) {
    LL ct = 0;
    for (int i = 0; i < n; i++) {
        // 求大于mid的升级次数
        if (arr[i][0] <= mid) continue;
        int d = arr[i][0] - mid;
        int t = (arr[i][0] - mid) / arr[i][1];
        if (d % arr[i][1] != 0) t++;

        ct += t;
    }
    return ct >= m;
}

int main() {
  scanf("%d%d", &n, &m);
  int l = 0, r = 1e6 + 5;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &arr[i][0], &arr[i][1]);
  }
  while (l < r) {
      int mid = (l + r + 1) / 2;
      if (check(mid)) {
          l = mid;
      } else {
          r = mid - 1;
      }
  }

  LL res = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i][0] <= r) continue;
    int d = arr[i][0] - r;
    int t = d / arr[i][1];
    if (d % arr[i][1] != 0) t++;
    res += t;
    int end = arr[i][0] - arr[i][1] * (t - 1);
    sum += (LL)(arr[i][0] + end) * t / 2;
  }

  // 这个时候多加的值是r+1
  printf("%lld\n", sum - (res - m) * (r + 1));
  return 0;
}
