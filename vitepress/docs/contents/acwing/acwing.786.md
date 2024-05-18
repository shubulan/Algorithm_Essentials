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
int a[N], n, k;

int kth_num(int *arr, int l, int k, int r) {
  if (k < l || k > r) assert(false);
  if (l == r) {
    return arr[l];
  }
  int x = arr[l + r >> 1], i = l - 1, j = r + 1;
  while (i < j) {
    do i++;
    while (arr[i] < x);
    do j--;
    while (arr[j] > x);
    if (i < j) swap(arr[i], arr[j]);
  }

  if (k <= j)
    return kth_num(arr, l, k, j);
  else
    return kth_num(arr, j + 1, k, r);
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << kth_num(a, 0, k - 1, n - 1) << endl;

  return 0;
}
```