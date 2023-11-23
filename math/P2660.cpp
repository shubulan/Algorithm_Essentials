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
/**
 * @brief 证明：
 *
 */
LL a, b;
LL solve(LL a, LL b) {
  if (!b) return 0;
  LL res = a / b * 4 * b;
  return res + solve(b, a % b);
}
int main() {
  cin >> a >> b;
  cout << solve(a, b) << endl;
  return 0;
}