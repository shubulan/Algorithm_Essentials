```c++
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

const int N = 100005;

int arr[N], c2k[N];
int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]), arr[i] += arr[i - 1];
  if (n < 3 || arr[n] % 3) {
    printf("0\n");
    return 0;
  }

  int k = arr[n] / 3;
  for (int i = n - 1; i >= 1; i--) {
    c2k[i] = c2k[i + 1];
    if (arr[i] == 2 * k) c2k[i]++;
  }
  LL res = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == k) {
      res += c2k[i + 1];
    }
  }
  printf("%lld\n", res);
  
  return 0;
}
```