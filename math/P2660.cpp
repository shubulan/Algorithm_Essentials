#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>

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