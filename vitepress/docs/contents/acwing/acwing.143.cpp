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

const int N = 3000005;

int son[N][2], idx;

void insert(unsigned x) {
  int p = 0;
  uint res = 0;
  for (int i = 31; i >= 0; i--) {
    int u = (x >> i) & 1;
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }
}

unsigned get(unsigned x) {
  int p = 0;
  uint res = 0;
  for (int i = 31; i >= 0; i--) {
    int c = !((x >> i) & 1);
    if (son[p][c]) {
      res |= (1 << i);
      p = son[p][c];
    } else {
      p = son[p][!c];
    }
  }
  return res;
}

int main() {
  int n;
  unsigned res = 0, x;
  cin >> n;
  cin >> x;
  insert(x);
  for (int i = 1; i < n; i++) {
    cin >> x;
    res = max(res, get(x));
    insert(x);
  }
  cout << res << endl;

  return 0;
}