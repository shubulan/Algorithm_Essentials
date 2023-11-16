

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

int arr[N], n;

void qsort(int* arr, int l, int r) {
  if (l >= r) return;
  int x = arr[l + r >> 1], i = l - 1, j = r + 1;
  while (i < j) {
    do i++; while(arr[i] < x);
    do j--; while (arr[j] > x);
    if (i < j) swap(arr[i], arr[j]);
  }
  qsort(arr, l, j); // 代码到这里，j 位置保证 <= x。保证[l, j] <= x
                    // 此外，保证了 j != r, 保证 [l, j] != [l, r] 不会导致死循环 
  qsort(arr, j + 1, r);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  
  qsort(arr, 0, n - 1);
  
  for (int i = 0 ; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}