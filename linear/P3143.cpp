#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 50005;
int arr[N], R[N];
int n, k, res, ma;
/**
 * @brief
 * 错误思路：先找最大的区间。把最大的区间划掉。再找次大的区间。
 * 错误原因：此贪心策略错误。
 *  因为把最大的拆开，有可能再向左右继续延伸。延伸出来的两个数组长度之和，可能更大。
 *  错误代码 P3143_d.cpp
 * @return int
 */

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  sort(arr, arr + n);

  for (int i = 0, j = 1; i < n; i++) {
    while (j < n && abs(arr[j] - arr[i]) <= k) j++;
    R[j] = max(R[j], j - i);
    if (R[i] > ma) {
      ma = R[i];  // 不包括 i, 左边最长有多长？
      cout << "更新ma" << ma << " " << i << endl;
    }
    if (ma + j - i > res) {
      res = ma + j - i;
      cout << "更新res" << res << " " << i << " " << j << endl;
    }
  }
  printf("%d\n", res);
  return 0;
}