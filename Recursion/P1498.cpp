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

#define MAX_N 5000
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char b[MAX_N + 5][MAX_N + 5];

void print(int i, int j) {
    b[i][j] = '/';
    b[i][j + 1] = '\\';
    b[i + 1][j - 1] = '/';
    b[i + 1][j] = '_';
    b[i + 1][j + 1] = '_';
    b[i + 1][j + 2] = '\\';
}

int tb[12];

void dfs(int i, int j, int n) {
    if (n == 1) {
        print(i, j);
        return;
    }
    dfs(i, j, n - 1);
    dfs(i + tb[n - 1], j - tb[n - 1], n - 1);
    dfs(i + tb[n - 1], j + tb[n - 1], n - 1);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < MAX_N; i++) {
      for (int j = 0; j < MAX_N; j++) {
          b[i][j] = ' ';
      }
  }

  tb[0] = 1; 
  for (int i = 1; i <= n; i++) tb[i] = (tb[i - 1] << 1);

  dfs(0, tb[n] - 1, n);

  for (int i = 0; i < tb[n]; i++) {
      for (int j = 0; j <= tb[n] + i; j++) {
          cout << b[i][j];
      }
      cout << endl;
  }
  return 0;
}
