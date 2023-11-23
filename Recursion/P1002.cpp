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

#define MAX_N 20
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int dir[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2};
vector<vector<int>> obs;
int tx, ty;

LL arr[MAX_N + 5][MAX_N + 5];

int dfs(int x, int y) {
  if (x == 0 && y == 0) return 1;
  if (arr[x][y]) return 0;
  int res = 0;
  if (x != 0) res += dfs(x - 1, y);
  if (y != 0) res += dfs(x, y - 1);
  return res;
}

int main() {
  int a, b;

  cin >> a >> b >> tx >> ty;
  arr[tx][ty] = -1;
  for (int i = 0; i < 8; i++) {
    int xx = tx + dir[i][0];
    int yy = ty + dir[i][1];
    if (xx >= 0 && yy >= 0) arr[xx][yy] = -1;
  }
  //   cout << dfs(a, b) << endl;
  arr[0][0] = 1;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      if (arr[i][j] == -1) {
        arr[i][j] = 0;
        continue;
      }
      if (arr[i + 1][j] != -1) arr[i + 1][j] += arr[i][j];
      if (arr[i][j + 1] != -1) arr[i][j + 1] += arr[i][j];
    }
  }
  //   for (int i = 0; i <= a; i++) {
  //       for (int j = 0; j <= b; j++) {
  //           cout << arr[i][j] << " ";
  //       }
  //       cout << endl;
  //   }
  cout << arr[a][b] << endl;
  return 0;
}