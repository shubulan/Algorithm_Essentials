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

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 10005;
int a[N];
int main() {
  int l, r, h;
  while (cin >> l >> h >> r) {
    for (int i = l; i < r; i++) {
      a[i] = max(a[i], h);
    }
  }
  int b = 0;
  for (int i = 0; i <= 1000; i++) {
    if (a[i] != b) {
      printf("%d %d ", i, a[i]);
      b = a[i];
    }
  }

  return 0;
}