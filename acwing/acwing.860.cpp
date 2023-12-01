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
int h[N], e[N * 2], nx[N * 2], idx;
int cor[N], n, m;
void add(int a, int b) {
    e[idx] = b;
    nx[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int x, int c) {
    cor[x] = c;
    int nc = 3 - c;
    for (int i = h[x]; ~i; i = nx[i]) {
        int p = e[i];
        if (cor[p] == nc) continue;
        if (cor[p] == c) return false;
        if (!dfs(p, nc)) return false;
    }
    return true;
}

bool bi_colored() {
  for (int i = 1; i <= n; i++) {
    if (!cor[i]) {
        if (!dfs(i, 1)) return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }
  if (bi_colored()) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}