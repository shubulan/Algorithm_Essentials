/*************************************************************************
        > File Name: 390.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Mon 02 Nov 2020 01:38:20 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, m;
int X[100005];
int func(int d) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += X[i] / d;
  }
  return sum;
}
int main() {
  cin >> n >> m;
  int r = 0;
  for (int i = 0; i < n; i++) {
    cin >> X[i];
    r = max(r, X[i]);
  }
  int l = 0;
  while (l != r) {
    int mid = (l + r + 1) / 2;
    int s = func(mid);
    if (s >= m) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;

  return 0;
}
