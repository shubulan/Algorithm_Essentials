
要点：
* 三角形存在$[1, n]$ 的位置，上面是右边，左上边是左边

```
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
存储方式
7
3   8
8   1   0
2   7   4   4
4   5   2   6   5
```

```c++
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 505;
int f[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) f[i][j] += f[i - 1][j];
            else if (j == i) f[i][j] += f[i - 1][j - 1];
            else f[i][j] += max(f[i - 1][j - 1], f[i - 1][j]);
        }
    }
    
    int mx = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) mx = max(mx, f[n][i]);
    cout << mx << endl;
    return 0;
}
```