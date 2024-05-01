#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
LL exgcd(LL a, LL b, LL &x, LL& y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int d = exgcd(b, a % b, y, x);
  y -= (a / b)*x;
  return d;
}
int main() {
  int n;
  LL a1, m1;
  cin >> n;
  n--;
  cin >> m1 >> a1;
  while (n--) {
    LL a2, m2;
    cin >> m2 >> a2;
    LL k1, k2;
    int d = exgcd(m1, m2, k1, k2);
    if ((a2 - a1) % d) {
      cout << -1;
      return 0;
    }
    k1 *= (a2 - a1) / d;
    LL t = m2 / d;
    k1 = (k1 % t + t) % t;
    a1 = k1 * m1 + a1;
    m1 = abs(m1 * t);
  }
  cout << (a1 % m1 + m1) % m1 << endl;
  
  return 0;
}