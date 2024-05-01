/*************************************************************************
        > File Name: 527.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Fri 20 Nov 2020 05:10:11 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
  int x, y, step, d;
};
int n, m, d, mark[105][105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];

int main() {
  cin >> n >> m >> d;
  for (int i = 1; i <= n; i++) {
    cin >> &mmap[i][1];
  }
  queue<node> que;
  que.push((node){1, 1, 0, d});
  for (int i = 0; i <= d; i++) {
    mark[1][1][i] = 1;
  }
  while (!que.empty()) {
    node temp = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      for (int j = 2; j <= temp.d; j++) {
        int x = temp.x + dir[i][0] * j;
        int y = temp.y + dir[i][1] * j;
        if (x < 1 || y < 1 || x > n || y > m) {
          break;
        }
        if (x == n && y == m) {
          cout << temp.step + 1 << endl;
          return 0;
        }
        if (mmap[x][y] == 'P' && mark[x][y][temp.d - j] == 0) {
          que.push((node){x, y, temp.step + 1, temp.d - j});
          mark[x][y][temp.d - j] = 1;
        }
      }
      int x = temp.x + dir[i][0];
      int y = temp.y + dir[i][1];
      if (x == n && y == m) {
        cout << temp.step + 1 << endl;
        return 0;
      }
      if (mmap[x][y] == 'P' && mark[x][y][temp.d] == 0) {
        que.push((node){x, y, temp.step + 1, temp.d});
        mark[x][y][temp.d] = 1;
      }
    }
  }
  cout << "impossible" << endl;

  return 0;
}
