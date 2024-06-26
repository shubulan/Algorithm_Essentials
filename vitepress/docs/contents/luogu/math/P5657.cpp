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
typedef unsigned long long ULL;
typedef pair<int, int> PII;
ULL n, k;
int main() {
  cin >> n >> k;
  // k ^= k / 2;
  // while (n--) cout << ((k >> n) & 1);
  // cout << endl;

  for (ULL i = 0, t = n - 1; i < n; i++, t--) {
    ULL x = (ULL)1 << t;
    if (k < x) {
      cout << "0";
    } else {
      cout << "1";
      k -= x;
      k = x - (k + 1);
    }
  }
  cout << endl;
  return 0;
}
