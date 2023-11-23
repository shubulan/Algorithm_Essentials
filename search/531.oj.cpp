/*************************************************************************
        > File Name: 531.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Fri 20 Nov 2020 08:53:46 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
  int staus, step;
};
int n, num2[22] = {1}, check[2200000], num[22];
void init() {
  for (int i = 1; i <= 21; i++) {
    num2[i] = num2[i - 1] << 1;
  }
}

int main() {
  init();
  cin >> n;
  int start = 0;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      start += num2[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++) {
      int t2;
      cin >> t2;
      num[i] += num2[t2];
    }
  }
  queue<node> que;
  que.push((node){start, 0});
  check[start] = 1;
  while (!que.empty()) {
    node temp = que.front();
    que.pop();
    if (temp.staus == 8) {
      cout << temp.step << endl;
      return 0;
    }
    for (int i = 1; i <= n; i++) {
      if ((temp.staus & num2[i])) {
        continue;
      }
      int status = temp.staus & (~num[i]);
      status |= num2[i];
      if (!check[status]) {
        check[status] = 1;
        que.push((node){status, temp.step + 1});
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
