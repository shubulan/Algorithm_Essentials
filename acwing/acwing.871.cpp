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
            mp[i]++;
            x /= i;
        }
    }
    if (x > 1) mp[x]++;
}

int main() {
  int n;
  cin >> n;
  while (n--) { // n 4*10^4
    int a;
    cin >> a;
    divide(a);
  }
  
  LL res = 1;
  for (auto &pi : mp) { // ln(sqrt(2 * 10^11) = ln(4 * 10^5))
    int a = pi.first, b = pi.second;
    LL t = 1;
    while (b--) {
        t = (t * a + 1) % MOD;
    }

    res = (res * t) % MOD;
  }
  cout << res << endl;

  return 0;
}