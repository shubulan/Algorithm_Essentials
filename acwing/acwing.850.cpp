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

const int N = 150005;

int h[N], e[N], w[N], nx[N], idx;
int dis[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
  e[idx] = b;
  w[idx] = c;
  nx[idx] = h[a];
  h[a] = idx++;
}

void dijkstraII() {
  memset(dis, 0x3f, sizeof dis);
  priority_queue<PII, vector<PII>, greater<PII>> que;
  que.push({0, 1});
  dis[1] = 0;

  while (!que.empty()) {
    PII x = que.top();
    que.pop();

    int ver = x.second, d = x.first;

    if (st[ver]) continue;
    st[ver] = 1;

    for (int i = h[ver]; ~i; i = nx[i]) {
      int p = e[i], c = w[i];
    //   if (st[p]) continue;
      if (d + c < dis[p]) {
        dis[p] = d + c;
        que.push({dis[p], p});
      }
    }
  }

}

int main() {
  cin >> n >> m;

  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
   int a, b, c;
   scanf("%d%d%d", &a, &b, &c);
//    cin >> a >> b >> c;
   add(a, b, c);
  }
  dijkstraII();
//   if (dis[n] == 0x3f3f3f3f) cout << -1 << endl;
//   else cout << dis[n] << endl;  
  if (dis[n] == 0x3f3f3f3f) printf("-1\n");
  else printf("%d\n", dis[n]);
  return 0;
}