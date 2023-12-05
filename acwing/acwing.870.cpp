#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
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

const int N = 100005, MOD = 1e9+7;

unordered_map<int, int> mp;

void divide(int x) {
  for (int i = 2; i <= x / i; i++) {
    while (x % i == 0) {
        x /= i;
        mp[i] += 1;
    }
  }
  if (x > 1) mp[x] += 1;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    divide(x);
  }
  LL res = 1;
  for (auto &p : mp) {
    res = (res * (p.second + 1)) % MOD;
  }
  cout << res << endl;

  return 0;
}