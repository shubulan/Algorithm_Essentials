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

const int N = 100005;

int arr[N], n, temp[N];

/**
 *
 * 方法一
 */
LL merge_sort(int* arr, int l, int r) {
  if (l >= r) return 0;
  LL cnt = 0;
  int mid = (l + r) >> 1;
  cnt += merge_sort(arr, l, mid);
  cnt += merge_sort(arr, mid + 1, r);
  int i = l, j = mid + 1, idx = 0;

  while (i <= mid && j <= r)
    if (arr[j] < arr[i])
      temp[idx++] = arr[j++];
    else {
      cnt += j - mid -
             1;  // 当 i 向前走的时候，说明 (mid, j) 的所有数都比 arr[i] 小
      temp[idx++] = arr[i++];
    }
  while (i <= mid) {  // 左区间剩余的数，与所有右区间的数形成逆序对
    temp[idx++] = arr[i++];
    cnt += r - mid;
  }
  while (j <= r) temp[idx++] = arr[j++];

  for (int i = l, j = 0; i <= r; i++) arr[i] = temp[j++];

  return cnt;
}
/**
 * 方法二
 */
LL merge_sort(int* arr, int l, int r) {
  if (l >= r) return 0;
  LL cnt = 0;
  int mid = (l + r) >> 1;
  cnt += merge_sort(arr, l, mid);
  cnt += merge_sort(arr, mid + 1, r);
  int i = l, j = mid + 1, idx = 0;

  while (i <= mid && j <= r)
    if (arr[j] < arr[i]) {
      cnt += mid - i + 1;  // 当 j 小的时候，[l, i) 的所有数都比 arr[i]
                           // 小，因此与[i, mid]的所有数形成逆序
      temp[idx++] = arr[j++];
    } else {
      temp[idx++] = arr[i++];
    }
  while (i <= mid) temp[idx++] = arr[i++];
  while (j <= r) temp[idx++] = arr[j++];

  for (int i = l, j = 0; i <= r; i++) arr[i] = temp[j++];

  return cnt;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << merge_sort(arr, 0, n - 1) << endl;

  return 0;
}