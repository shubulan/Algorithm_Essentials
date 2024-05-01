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

const int N = 505, M = 10005, inf = 0x3f3f3f3f;
int n, m, k;
int e[M], f[M], w[M];
int dist[N];
int dist_bk[N];

void bellman_ford() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  for (int i = 0; i < k; i++) {
    memcpy(dist_bk, dist, sizeof dist_bk);
    for (int j = 0; j < m; j++) {
        int a = e[j], b = f[j], c = w[j];
        if (dist_bk[a] == inf) continue; // 方法二：自己是正无穷，不要做松弛操作
        if (dist_bk[a] + c < dist[b]) {
            dist[b] = dist_bk[a] + c;
        }
    }
  }
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    e[i] = a, f[i] = b, w[i] = c;
  }
  bellman_ford();
  // 由于边权可能为负，导致无穷大被更新的小了一点，因此采用这种方式来判断
  // 也可以考虑方法二：中间是无穷大时，就不要做松弛操作了
  // if (dist[n] > inf / 2) {
  //   cout << "impossible" << endl;
  // } else {
  //   cout << dist[n] << endl;
  // }

  // 方法二
  if (dist[n] == inf) {
    cout << "impossible" << endl;
  } else {
    cout << dist[n] << endl;
  }

  return 0;
}