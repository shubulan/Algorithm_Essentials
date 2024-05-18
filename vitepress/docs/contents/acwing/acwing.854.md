```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 205, inf = 0x3f3f3f3f;

int G[N][N];

void floyd(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (G[i][k] != inf && G[k][j] != inf) // 只有两边畅通时，才做松弛操作
            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    memset(G, 0x3f, sizeof G);
    for (int i = 0; i <= n; i++) G[i][i] = 0;
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      G[a][b] = min(G[a][b], c);
    }
    floyd(n);

    while (k--) {
      int a, b;
      cin >> a >> b;

      if (G[a][b] == inf) cout << "impossible" << endl;
      else cout << G[a][b] << endl;
    }


    return 0;
}
```