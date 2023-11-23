/*************************************************************************
        > File Name: 237.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Sun 15 Nov 2020 03:41:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, num[10], mark[10], cnt;
void p() {
  for (int i = 0; i < n; i++) {
    if (i) {
      cout << " ";
    }
    cout << num[i];
  }
  cout << endl;
}

void func(int left) {
  if (left == 0) {
    p();
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (mark[i] == 1) continue;
    mark[i] = 1;

    num[cnt] = i;
    cnt++;
    func(left - 1);
    mark[i] = 0;
    cnt--;
  }
}
int main() {
  cin >> n;
  func(n);  // 胜几个数
  return 0;
}
