#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 50005;
LL arr[N];
LL n, k;

int main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  sort(arr, arr + n);
  LL mx = INT_MIN, l = 0, r = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && arr[j] - arr[i] <= k) j++;
    if (j - i > mx) {
      mx = j - i;
      l = i, r = j;
    }
  }
  cout << "first mx " << mx << endl;
  cout << "delete " << l << " " << r << endl;
  for (int i = l, j = r; j < n; j++) arr[i++] = arr[j];
  LL res = mx;
  mx = INT_MIN;
  n -= r - l;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && arr[j] - arr[i] <= k) j++;
    if (j - i > mx) {
      mx = j - i;
      l = i, r = j;
    }
  }
  cout << "second mx " << mx << endl;
  cout << "second " << l << " " << r << endl;
  res += mx;
  
  printf("%lld\n", res);
  return 0;
}