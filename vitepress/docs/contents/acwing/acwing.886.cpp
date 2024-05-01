#include <iostream>
#include <cstring>
#include <algorithm>
const int N = 100005, mod = 1e9 + 7;
using namespace std;
int p[N], invp[N];
typedef long long LL;

LL qmi(LL a, int b, int p) {
  LL res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  p[0] = invp[0] = 1;
  for (int i = 1; i < N; i++) {
    p[i] = (LL)p[i - 1] * i % mod;
    invp[i] = (LL)invp[i - 1] * qmi(i, mod - 2, mod) % mod;
  }

  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << (LL)p[a] * invp[b] % mod * invp[a - b] % mod << endl;
  }
  return 0;
}