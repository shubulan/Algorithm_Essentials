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

const int N = 1005;
int arr[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
  b[x1][y1] += c;
  b[x2 + 1][y1] -= c; 
  b[x1][y2 + 1] -= c; 
  b[x2 + 1][y2 + 1] += c; 
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }

  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--) {
      insert(i, j, i, j, arr[i][j]);
    }

  while (q--) {
    int x1, x2, y1, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    insert(x1, y1, x2, y2, c);
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      cout << b[i][j] << " ";
    cout << endl;
  }
  cout << endl;

  return 0;
}