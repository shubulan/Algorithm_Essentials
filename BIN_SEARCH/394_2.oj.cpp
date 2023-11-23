/*************************************************************************
        > File Name: 394_2.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Mon 02 Nov 2020 03:29:39 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, m, L;
int num[50005];
int func(int len) {
  int cnt = 0, last = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (num[i] - last < len) {
      cnt++;
    } else {
      last = num[i];
    }
  }
  return cnt;
}
int main() {
  cin >> L >> n >> m;
  int l = 2100000000, r = L;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    l = min(l, num[i] - num[i - 1]);
  }
  num[n + 1] = L;
  l = min(l, L - num[n]);
  while (l != r) {
    int mid = (l + r + 1) / 2;
    int s = func(mid);
    if (s <= m) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << r << endl;

  return 0;
}
