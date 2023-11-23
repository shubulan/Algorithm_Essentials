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

#define MAX_N
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int t, n, m, p;

LL qmi(LL a, int b, int p) {
  LL res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}

LL C(int a, int b, int p) {
  LL res = 1;
  for (int i = 1, j = a; i <= b; i++, j--) {
    res = res * j % p;
    res = res * qmi(i, p - 2, p) % p;
  }
  return res % p;
}

LL lucus(int a, int b, int p) {
  if (a < p && b < p) return C(a, b, p);
  return C(a % p, b % p, p) * lucus(a / p, b / p, p) % p;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> p;
    cout << lucus(n + m, n, p) << endl;
  }

  return 0;
}
