
LIS 问题有多重做法，而且多重做法背后是不同思路，之后再补充
* 二分优化
* 线段树

:::code-group
```c++ [最长公共子序列]
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;
int a[N], f[N];

int main()
{
    int n, res = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }

    cout << res << endl;
    return 0;
}
```

```c++ [最长公共子序列II]
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000005;

int arr[N], f[N];
int up[N];
int n, res = 1;

int main() {
  cin >> n;
  memset(up, 0x3f, sizeof up);
  for (int i = 0; i < n; i++) cin >> arr[i];
  f[0] = 1, up[0] = 0;
  up[1] = arr[0];
  for (int i = 1; i < n; i++) {
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (up[mid] < arr[i]) l = mid;
      else r = mid - 1;
    }
    f[i] = r + 1;
    up[r + 1] = min(up[r + 1], arr[i]);
    res = max(res, f[i]);
  }
  cout << res << endl;
  return 0;

}
```
:::