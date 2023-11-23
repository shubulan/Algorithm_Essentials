/*************************************************************************
        > File Name: 397.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Sun 15 Nov 2020 06:28:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, m, ans, mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0];
    int yy = y + dir[i][1];
    if (mmap[xx][yy] != 0) {
      mmap[xx][yy] = 0;
      func(xx, yy);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mmap[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mmap[i][j] != 0) {
        ans++;
        mmap[i][j] = 0;
        func(i, j);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
