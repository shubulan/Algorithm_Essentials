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

const int N = 505, inf = 0x3f3f3f3f;
int G[N][N];
int n, m;
bool st[N];
int dist[N];
int prim() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int k = -1;
    for (int j = 1; j <= n; j++) {
        if (st[j]) continue;
        if (k == -1 || dist[j] < dist[k]) k = j;
    }
    if (dist[k] == inf) return inf;
    res += dist[k];
    st[k] = true;
    for (int j = 1; j <= n; j++) {
        if (st[j]) continue;
        if (G[k][j] == inf) continue;
        dist[j] = min(dist[j], G[k][j]);
    }
  }
  return res;
}

int main() {
  cin >> n >> m;
  memset(G, 0x3f, sizeof G);
  for (int i = 0; i <= n; i++) G[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    G[a][b] = G[b][a] = min(G[a][b], c);
  }
  int res = prim();
  if (res == inf) {
    cout << "impossible" << endl;
  } else {
    cout << res << endl;
  }
  
  return 0;
}