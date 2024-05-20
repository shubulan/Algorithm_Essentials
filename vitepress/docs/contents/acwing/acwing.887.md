
```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

int qmi(int a, int b, int p) {
  int res = 1;
  while (b) {
    if (b & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    b >>= 1;
  }
  return res;
}

int C(int a, int b, int p) {
  int res = 1;
  for (int i = a, j = 1; j <= b; i--, j++) {
    res = (LL)res * i % p;
    res = (LL)res * qmi(j, p - 2, p) % p;
  }
  return res;
}

int lucas(LL a, LL b, int p) {
  if (a < p && b < p) return C(a, b, p);
  return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p; 
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    LL a, b, p;
    cin >> a >> b >> p;
    cout << lucas(a, b, p) << endl;
  }

  return 0;
}
```