#include <algorithm>
#include <cassert>
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

const int N = 100005;
int a[N], b[N];
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < m; j++) cin >> b[j];
  for (int i = 0, j = m - 1; i < n; i++) {
    while (j >= 0 && a[i] + b[j] > x) j--;
    if (a[i] + b[j] == x) {
      cout << i << " " << j << endl;
      break;
    }
  }

  return 0;
}