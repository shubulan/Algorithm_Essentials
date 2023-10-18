#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2005;
int C[N][N];
int n, m, t, k;

void init(int n, int m) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j) {
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        C[i][j] %= k;
      }
      else 
        C[i][j] = 1;
      // cout << C[i][j] << " ";
    }
    // cout << endl;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (j <= i) C[i][j] = (C[i][j] == 0);
      if (i - 1 >= 0) C[i][j] += C[i - 1][j];
      if (j - 1 >= 0) C[i][j] += C[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0) C[i][j] -= C[i - 1][j - 1];
    }
  }
}


int main() {
  cin >> t >> k;
  init(2000, 2000);
  for (int i = 0; i < t; i++) {
    cin >> n >> m;
    cout << C[n][m] << endl;
  }
  return 0;
}