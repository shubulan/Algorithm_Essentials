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

int main() {
  int n, x;
  const int mod = 1e9 + 7;
  LL res = 0;
  cin >> n;
  unordered_map<int, int> mmap;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mmap[x]++;
  }
  for (int i = 1; i <= n; i++) {
    if (mmap[i] < 2) continue;
    int a = mmap[i];
    a = a * (a - 1) / 2;
    for (int j = 1; j <= (i / 2); j++) {
      int b = mmap[j];
      int c = mmap[i - j];
      if (b == 0 || c == 0) continue;
      int k = b * c;
      if (i == j + j) {
        k = (b * (b - 1)) / 2;
      };
      res += a * k;
      res %= mod;
    }
  }
  cout << res << endl;

  return 0;
}