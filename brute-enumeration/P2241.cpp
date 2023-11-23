#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
typedef long long LL;
using namespace std;

int main() {
  LL n, m;
  cin >> n >> m;
  LL total = 0;
  LL scnt = 0;

  // total = (n * (n + 1)) / 2 * (m * (m + 1) / 2);
  // for (LL i = 1; i <= min(n, m); i++) {
  //   scnt += (n - i + 1) * (m - i + 1);
  // }

  // 解法2
  for (LL i = 0; i < n; i++) {
    for (LL j = 0; j < m; j++) {
      total += (n - i) * (m - j);
      scnt += min(n - i, m - j);
    }
  }
  cout << scnt << " " << total - scnt << endl;
  return 0;
}