
```c++
#include <iostream>
#include <cstring>

using namespace std;
const int N = 305;

int a[N], s[N];
int f[N][N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
  }
  memset(f, 0x3f, sizeof f);

  for (int len = 1; len <= n; len++) {
    for (int i = 1, j = i + len - 1; j <= n ; i++, j++) {
      if (len == 1) {
        f[i][j] = 0;
        continue;
      }
      for (int m = i; m < j; m++) {
        f[i][j] = min(f[i][j], s[j] - s[i - 1] + f[i][m] + f[m + 1][j]);
      }
    }
  }
  cout << f[1][n] << endl;

  return 0;
}
```