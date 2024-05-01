```c++
#include <algorithm>
#include <cassert>
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

const int N = 105;
int b[N][N], st[N][N], n, m;
int dir[5] = {0, 1, 0, -1, 0};

void bfs() {
  int t = 0;
  st[1][1] = 1;
  queue<PII> que;
  que.push({1, 1});
  while (!que.empty()) {
    int sz = que.size();
    for (int i = 0; i < sz; i++) {
        PII g = que.front();
        if (g.first == n && g.second == m) {
            cout << t << endl;
            exit(0);
        }
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = g.first + dir[i];
            int y = g.second + dir[i + 1];
            if (x < 1 || y < 1 || x > n || y > m) continue;
            if (b[x][y] == 1) continue;
            if (st[x][y] == 1) continue;
            st[x][y] = 1;
            que.push({x, y});
        }
    }
    t++;
  }

}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        cin >> b[i][j];
  bfs();
  return 0;
}
```