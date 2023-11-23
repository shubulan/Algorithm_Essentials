/*************************************************************************
        > File Name: 541.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Mon 23 Nov 2020 04:45:09 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, m, arr[2][20][20], ans[2][100000], cnt[2];
void func(int id, int now, int cost) {
  if (now == n) {
    ans[id][cnt[id]++] = cost;
  }
  for (int i = now + 1; i <= n; i++) {
    if (arr[id][now][i] != 0) {
      func(id, i, cost + arr[id][now][i]);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    arr[0][a][b] = arr[0][b][a] = c;
    arr[1][a][b] = arr[1][b][a] = d;
  }
  func(0, 1, 0);
  func(1, 1, 0);
  int fin = 2100000000;
  for (int i = 0; i < cnt[0]; i++) {
    if (fin < ans[0][i]) {
      continue;
    }
    for (int j = 0; j < cnt[1]; j++) {
      if (ans[0][i] == ans[1][j]) {
        fin = ans[0][i];
      }
    }
  }
  if (fin == 2100000000) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << fin << endl;

  return 0;
}
