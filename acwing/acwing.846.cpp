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
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;
int n;
int e[2 * N], nx[2 * N], h[N], idx, ans = 0x3f3f3f3f;

void add(int a, int b) {
    e[idx] = b;
    nx[idx] = h[a];
    h[a] = idx++;
}

int dfs(int x, int p) {
    int sum = 1, res = 0;

    for (int i = h[x]; ~i; i = nx[i]) {
        int ic = e[i];
        if (ic == p) continue;
        int szc = dfs(ic, x);
        sum += szc;
        res = max(res, szc);
    }
    res = max(n - sum, res);
    ans = min(res, ans);
    return sum;
}

int main() {
  cin >> n;
  memset(h, -1, sizeof h);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  dfs(1, 0);
  cout << ans << endl;

  return 0;
}