#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int mod = 1e9 + 7, N = 200005;

int qmi(int a, int b, int p) {
  int res = 1;
  while (b) {
    if (b & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    b >>= 1;
  }
  return res;
}

int fact[N], invfact[N];
int main() {
  int n;
  cin >> n;
  fact[0] = invfact[0] = 1;
  for (int i = 1; i <= 2 * n; i++) {
    fact[i] = (LL)fact[i - 1] * i % mod;
    invfact[i] = qmi(fact[i], mod - 2, mod);
  }
  
  // C2n n C2n n -1;
  cout << (LL)fact[2 * n] * invfact[n] % mod * invfact[n] % mod * qmi(n + 1, mod - 2, mod) % mod << endl;
  
  return 0;
}