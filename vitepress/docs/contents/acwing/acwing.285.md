
```c++
#include <iostream>
#include <cstring>

using namespace std;
const int N = 6005;


int H[N], h[N], e[N], nx[N], cnt, res;
int x[N], y[N]; // x 去，y 不去

void add(int a, int b) {
  nx[cnt] = h[a];
  e[cnt] = b;
  h[a] = cnt++;
}

void dfs(int r) {
  if (x[r]) return;
  x[r] = H[r];
  for (int i = h[r]; ~i; i = nx[i]) {
    int c = e[i];
    dfs(c);
    x[r] += y[c];
    y[r] += max(y[c], x[c]);
  }
  res = max(res, x[r]);
  res = max(res, y[r]);
}

int main() {
  int n;
  cin >> n;
  memset(h, -1, sizeof h);
  for (int i = 1; i <= n; i++) cin >> H[i];
  for (int i = 0; i < n - 1; i++) {
    int l, k;
    cin >> l >> k;
    add(k, l);
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] == 0) {
      dfs(i);
    }
  }
  cout << res << endl;


  return 0;
}
```