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
int diff[2 * N], cnt;
int ori[2 * N];
unordered_map<int, int> midx;
LL n, res;

int main() {
  // scanf("%d", &n);
  // for (int i = 0; i < n; i++) {
  //   scanf("%d%d", &a[i], &b[i]);
  // }
  // sort(a, a + n);
  // sort(b, b + n);
  // for (int i = 0; i < n; i++) {
  //   res += b[i] - a[i];
  //   if (i < n - 1 && a[i + 1] < b[i]) 
  //     res -= b[i] - a[i + 1];
  // }
  // printf("%d\n", res);
  // 

  // 解法二： 离散化差分
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    ori[cnt++] = a[i];
    ori[cnt++] = b[i];
  }
  sort(ori, ori + cnt);
  for (int i = 0; i < cnt; i++) {
    midx[ori[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    diff[midx[a[i]]]++;
    diff[midx[b[i]]]--;
  }
  for (int i = 1; i < cnt; i++) {
    diff[i] += diff[i - 1];
  }
  for (int i = 0; i < cnt; i++) {
    if (!diff[i]) continue;
    int j = i;
    while (j < cnt && diff[j]) j++;
    res += ori[j] -  ori[i];
    i = j;
  }
  printf("%lld\n", res);

  return 0;
}