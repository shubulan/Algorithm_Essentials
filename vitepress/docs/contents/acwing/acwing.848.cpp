#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
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

const int N = 100005;
int e[N], nx[N], h[N], idx;
int color[N];
int path[N], cnt;
int n, m;

int dfs(int x) {
    color[x] = 1;
    for (int i = h[x]; ~i; i = nx[i]) {
        int p = e[i];
        if (color[p] == 2) continue;
        if (color[p] == 1 || !dfs(p)) return 0;
    }
    color[x] = 2;
    path[cnt++] = x;
    return 1;
}

void add(int a, int b) {
    e[idx] = b;
    nx[idx] = h[a];
    h[a] = idx++;
}
/**
 * dfs加节点标记写法
*/
int topSort() {
  for (int i = 1; i <= n; i++) {
    if (!color[i] && !dfs(i))
        return 0;
  }
}

int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add(b, a);
  }
  if (topSort()) {
    for (int i = 0; i < n; i++) cout << path[i] << " ";
    cout << endl;
  } else {
    cout << -1 << endl;
  }


  return 0;
}