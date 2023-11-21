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
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;
int a[N], b[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < m; j++) cin >> b[j];

  for (int i = 0, j = 0; i < n; i++, j++) {
    while (j < m && b[j] != a[i]) j++;
    if (j == m) {
      cout << "No" << endl;
      exit(0);
    }
  }
  cout << "Yes" << endl;


  return 0;
}