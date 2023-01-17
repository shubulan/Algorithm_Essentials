#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <string>

const int mod = 1e9 + 7;
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a[55], n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int res = 1;
  for (int i = 0; i < n; i++) {
    res = ((LL)res * (a[i] - i)) % mod;
  }
  cout << res << endl;;

  return 0;
}