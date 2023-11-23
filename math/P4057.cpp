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
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

LL a, b, c, res;
int main() {
  cin >> a >> b >> c;
  LL x = gcd(a, b);
  x = a * b / x;
  res = gcd(x, c);
  res = x * c / res;
  cout << res << endl;
  return 0;
}