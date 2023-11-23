/*************************************************************************
        > File Name: 304.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Fri 20 Nov 2020 10:23:03 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
  int x, y, step;
};

int dir[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2};
queue<node> que;
int n, m;
char mmap[200][200];

int main() {
  cin >> m >> n;
  for (int i = 5; i < n + 5; i++) {
    for (int j = 5; j < m + 5; j++) {
      cin >> mmap[i][j];
      if (mmap[i][j] == 'K') {
        que.push((node){i, j, 0});
      }
    }
  }
  while (!que.empty()) {
    node temp = que.front();
    que.pop();
    for (int i = 0; i < 8; i++) {
      int x = temp.x + dir[i][0];
      int y = temp.y + dir[i][1];
      if (mmap[x][y] == 'H') {
        cout << temp.step + 1 << endl;
        return 0;
      }
      if (mmap[x][y] == '.') {
        que.push((node){x, y, temp.step + 1});
        mmap[x][y] = 0;
      }
    }
  }
  cout << -1 << endl;

  return 0;
}
