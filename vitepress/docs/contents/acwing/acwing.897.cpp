#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;
int f[N][N];

int main() {
  int n, m;
  string s1, s2;
  cin >> n >> m;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s1[i] == s2[j]) f[i + 1][j + 1] = f[i][j] + 1;
      else f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
    }
  }
  cout << f[n][m] << endl;
  return 0;
}