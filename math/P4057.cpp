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
LL gcd(LL a, LL b) {
  return b ? gcd(b, a % b) : a;
}

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