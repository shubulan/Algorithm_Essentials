/*************************************************************************
        > File Name: 530.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Fri 20 Nov 2020 08:02:12 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
  int x, y;
};
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m;

int main() {
  cin >> n >> m;
  queue<node> que;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mmap[i][j];
      if (mmap[i][j] == '*') {
        mmap[i][j] = '.';
        que.push((node){i, j});
      }
    }
  }
  int t;
  string str;
  cin >> t;
  while (t--) {
    cin >> str;
    int d;
    switch (str[0]) {
      case 'N':
        d = 3;
        break;
      case 'S':
        d = 1;
        break;
      case 'W':
        d = 2;
        break;
      case 'E':
        d = 0;
        break;
      default:
        d = 0;
        break;
    }
    int check[55][55] = {0};
    int sz = que.size();
    for (int i = 0; i < sz; i++) {
      node temp = que.front();

      que.pop();
      for (int j = 1; 1; j++) {
        int x = temp.x + dir[d][0] * j;
        int y = temp.y + dir[d][1] * j;
        if (mmap[x][y] != '.') {
          break;
        }
        if (check[x][y] == 0) {
          que.push((node){x, y});
          check[x][y] = 1;
        }
      }
    }
  }
  while (!que.empty()) {
    int x = que.front().x;
    int y = que.front().y;
    que.pop();
    mmap[x][y] = '*';
  }
  for (int i = 1; i <= n; i++) {
    cout << &mmap[i][1] << endl;
  }

  return 0;
}
