#include <algorithm>
#include <climits>
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

int st[505] = {0};
int n, res;

void dfs(int n, int x) {
  if (n == 0) {
    st[x] = 1;
    return;
  }
  for (int i = 1; i <= n; i++) {
    dfs(n - i, i * (n - i) + x);
  }
}
int main() {
  cin >> n;
  dfs(n, 0);

  for (int i = 0; i <= 500; i++) {
    res += (st[i] == 1);
  }
  cout << res << endl;

  return 0;
}