
```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1005;

int f[N][N];
char s1[N], s2[N];
int main() {
  int n, m;
  scanf("%d%s%d%s", &n, s1 + 1, &m, s2 + 1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0) f[i][j] = j;
      else if (j == 0) f[i][j] = i;
      else {
        if (s1[i] == s2[j]) {
          f[i][j] = f[i - 1][j - 1];
        } else {
          f[i][j] = min({f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]}) + 1;
        }
      }
    }
  }
  printf("%d\n", f[n][m]);


  return 0;
}
```