/*************************************************************************
        > File Name: 401.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Fri 20 Nov 2020 10:57:34 AM CST
 ************************************************************************/

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int num[550][550];
struct node {
  int x, y, step;
};

queue<node> que;
int dir[12][2] = {1,  2, 1,  -2, 2, 1, 2, -1, -1, 2, -1, -2,
                  -2, 1, -2, -1, 2, 2, 2, -2, -2, 2, -2, -2};

int main() {
  memset(num, -1, sizeof(num));
  que.push((node){1, 1, 0});
  num[1][1] = 0;
  while (!que.empty()) {
    node temp = que.front();
    que.pop();
    for (int i = 0; i < 12; i++) {
      int x = temp.x + dir[i][0];
      int y = temp.y + dir[i][1];
      if (x < 1 || y < 1 || x > 500 || y > 500 || num[x][y] != -1) {
        continue;
      }
      num[x][y] = temp.step + 1;
      que.push((node){x, y, num[x][y]});
    }
  }
  int n, sx, sy;
  cin >> n;
  while (n) {
    cin >> sx >> sy;
    cout << num[sx][sy] << endl;
    n--;
  }
  return 0;
}
