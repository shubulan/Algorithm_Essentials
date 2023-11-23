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

#define MAX_N 100000

int p = 1e9 + 7;
const int N = 100;
int infact[N + 5], fact[N + 5];

LL qmi(LL a, int n, int p) {
  LL res = 1;
  while (n) {
    if (n & 1) res = res * a % p;
    a = a * a % p;
    n >>= 1;
  }
  return res;
}

int main() {
  infact[0] = 1;
  fact[0] = 1;
  // nlogn 初始化
  for (int i = 1; i <= N; i++) {
    infact[i] = (LL)infact[i - 1] * qmi(i, p - 2, p) % p;
    fact[i] = (LL)fact[i - 1] * i % p;
  }
  int x = 5, y = 3;
  // O(1) 求解
  while (cin >> x >> y)
    cout << (LL)fact[x] * infact[y] % p * infact[x - y] % p << endl;

  return 0;
}
