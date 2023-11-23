/*************************************************************************
        > File Name: 34.euler.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Fri 06 Nov 2020 09:41:11 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int num[10];
void init() {
  num[0] = 1;
  for (int i = 1; i < 10; i++) {
    num[i] = num[i - 1] * i;
  }
}
int check(int n) {
  int raw = n, t = 0;
  while (n) {
    t += num[n % 10];
    n /= 10;
  }
  return raw == t;
}
int main() {
  init();
  int ans = 0;
  for (int i = 10; i < 1000000; i++) {
    if (check(i)) {
      ans += i;
      cout << i << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
