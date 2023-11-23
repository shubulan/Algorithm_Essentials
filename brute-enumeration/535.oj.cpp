/*************************************************************************
        > File Name: 535.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Sun 15 Nov 2020 06:08:16 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int h, w, ans = 1;
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void func(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0];
    int yy = y + dir[i][1];
    if (mmap[xx][yy] == '.') {
      ans++;
      mmap[xx][yy] = 0;
      func(xx, yy);
    }
  }
}
int main() {
  cin >> h >> w;
  int sx, sy;
  for (int i = 1; i <= w; i++) {
    for (int j = 1; j <= h; j++) {
      cin >> mmap[i][j];
      if (mmap[i][j] == '@') {
        sx = i, sy = j;
      }
    }
  }
  func(sx, sy);
  cout << ans << endl;

  return 0;
}
