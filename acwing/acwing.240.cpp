#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 50010;
int p[N * 3];

int find(int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
  x = find(x), y = find(y);
  p[x] = y;
  return;
}

int main () {
  int n, k, res = 0;
  cin >> n >> k;
  for (int i = 0; i < 3 * n; i++) p[i] = i;

  for (int i = 0; i < k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (b < 1 || b > n || c < 1 || c > n) {
      res++;
      continue;
    }
    if (a == 1) {
      if (find(b) == find(c + n) || find(b) == find(c + 2 * n)) res++;
      else {
        unite(b, c);
        unite(b + n, c + n);
        unite(b + 2 * n, c + 2 * n);
      }
    } else {
      if (find(b) == find(c) || find(b) == find(c + 2 * n)) res++;
      else {
        unite(b, c + n);
        unite(b + n, c + 2 * n);
        unite(b + 2 * n, c);
      }
    }
  }
  cout << res << endl;
  
  return 0;
}