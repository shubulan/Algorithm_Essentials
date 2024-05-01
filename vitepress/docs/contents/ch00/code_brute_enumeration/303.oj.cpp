/*************************************************************************
        > File Name: 303.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Wed 18 Nov 2020 07:17:17 PM CST
 ************************************************************************/

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
int n, m, num[1005][1005];
char mmap[1005][1005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct node {
  int x, y, step;
};
queue<node> que;
int main() {
  cin >> n >> m;
  memset(num, -1, sizeof(num));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mmap[i][j];
      if (mmap[i][j] == '1') {
        que.push(((node){i, j, 0}));
        num[i][j] = 0;
      }
    }
  }
  while (!que.empty()) {
    node temp = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int x = temp.x + dir[i][0];
      int y = temp.y + dir[i][1];
      if (x < 0 || y < 0 || x >= n || y >= m || num[x][y] != -1) {
        continue;
      }
      num[x][y] = temp.step + 1;
      que.push((node){x, y, temp.step + 1});
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j != 0) {
        cout << " ";
      }
      cout << num[i][j];
    }
    cout << endl;
  }

  return 0;
}
