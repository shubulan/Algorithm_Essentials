/*************************************************************************
        > File Name: 400.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Fri 20 Nov 2020 10:43:54 AM CST
 ************************************************************************/

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct node {
  int x, y, step;
};
int dir[12][2] = {2, 2, 2, -2, -2, 2, -2, -2, 1,  2, 1,  -2,
                  2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1};
queue<node> que;
int mark[550][550];

int main() {
  int n1, m1, n2, m2;
  cin >> n1 >> m1 >> n2 >> m2;
  que.push((node){n1, m1, 0});
  mark[n1][m1] = 1;
  while (!que.empty()) {
    node temp = que.front();
    que.pop();
    for (int i = 0; i < 12; i++) {
      int x = temp.x + dir[i][0];
      int y = temp.y + dir[i][1];
      if (x < 1 || y < 1 || x > 500 || y > 500 || mark[x][y]) {
        continue;
      }
      if (x == 1 && y == 1) {
        cout << temp.step + 1 << endl;
      }
      mark[x][y] = 1;
      que.push((node){x, y, temp.step + 1});
    }
  }
  memset(mark, 0, sizeof(mark));
  que.push((node){n2, m2, 0});
  mark[n2][m2] = 1;
  while (!que.empty()) {
    node temp = que.front();
    que.pop();
    for (int i = 0; i < 12; i++) {
      int x = temp.x + dir[i][0];
      int y = temp.y + dir[i][1];
      if (x < 1 || y < 1 || x > 500 || y > 500 || mark[x][y]) {
        continue;
      }
      if (x == 1 && y == 1) {
        cout << temp.step + 1 << endl;
      }
      mark[x][y] = 1;
      que.push((node){x, y, temp.step + 1});
    }
  }

  return 0;
}
