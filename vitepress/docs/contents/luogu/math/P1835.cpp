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

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAX_N = 50005;
uint primes[MAX_N];
int cnt;
void init(uint n) {
  for (int i = 2; i <= n; i++) {
    if (!primes[i]) primes[++cnt] = i;
    for (int j = 1; primes[j] <= n / i; j++) {
      primes[primes[j] * i] = 1;
      if (i % primes[j] == 0) break;
    }
  }
}

int l, r;
uint ans[1000005];
int ct2;
int main() {
  cin >> l >> r;
  // 复杂度 为 sqrt(r) + logr x loglogr
  init(uint(sqrt(r) + 5));
  for (uint i = 1; i <= cnt && primes[i] * primes[i] <= r; i++) {
    for (uint j = l / primes[i] * primes[i]; j <= r; j += primes[i]) {
      if (j < l || primes[i] == j) continue;
      ans[j - l] = 1;
    }
  }
  for (uint i = 0; i <= r - l; i++) {
    if (i + l == 0 || i + l == 1) continue;
    if (!ans[i]) ct2++;
  }
  cout << ct2 << endl;
  return 0;
}