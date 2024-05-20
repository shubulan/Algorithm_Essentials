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
const int MAX_N = 100000005;
int primes[MAX_N];
int p;
int n, q;
void init() {
  for (int i = 2; i <= n; i++) {
    if (!primes[i]) primes[++p] = i;
    for (int j = 1; primes[j] <= n / i; j++) {
      primes[primes[j] * i] = 1;
      if (i % primes[j] == 0) break;
    }
  }
}

int main() {
  scanf("%d%d", &n, &q);
  init();
  int idx;
  while (q--) {
    scanf("%d", &idx);
    printf("%d\n", primes[idx]);
  }

  return 0;
}