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
#include <climits>
#include <cstring>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 205;

int dis[N][N][N];
int T[N];
int n, m;

void warshall_floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[k][i][j] = min((LL)dis[k - 1][i][k - 1] + dis[k - 1][k - 1][j], (LL)dis[k - 1][i][j]);
            }
        }
    }

}

int main() {
  scanf("%d%d", &n, &m);
  memset(dis, 0x7f, sizeof dis);
  for (int i = 0; i < n; i++) {
    scanf("%d", &T[i]);
    dis[0][i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    dis[0][a][b] = w;
    dis[0][b][a] = w;
  }
  warshall_floyd();
  int x;
  scanf("%d", &x);
  for (int i = 0; i < x; i++) {
      int a, b, t;
      scanf("%d%d%d", &a, &b, &t);
      int idx = n;
      for (int j = 0; j < n; j++) 
          if (T[j] > t) {
            idx = j;
            break;
          }
      if (a >= idx || b >= idx) printf("-1\n");
      else printf("%d\n", dis[idx][a][b] == 0x7f7f7f7f? -1 : dis[idx][a][b]);
  }

  return 0;
}
