#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 100005;
int par[N], t, n;
int br[N][3], ct1;
unordered_map<int, int> hidx;
int id;

int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  par[x] = y;
}
void solve() {
  scanf("%d", &n);
  ct1 = 0, id = 0;
  while (n--) {
    ct1++;
    scanf("%d%d%d", &br[ct1][0], &br[ct1][1], &br[ct1][2]);
    hidx[br[ct1][0]] = id++;
    hidx[br[ct1][1]] = id++;
  }

  for (int i = 0; i <= id; i++) par[i] = i;

  for (int i = 1; i <= ct1; i++) {
    if (br[i][2] == 1) unite(hidx[br[i][0]], hidx[br[i][1]]);
  }

  for (int i = 1; i <= ct1; i++) {
    if (br[i][2] == 1) continue;
    if (find(hidx[br[i][0]]) == find(hidx[br[i][1]])) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}
int main() {
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}