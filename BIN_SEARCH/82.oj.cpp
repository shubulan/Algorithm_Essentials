/*************************************************************************
        > File Name: 82.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Mon 02 Nov 2020 02:43:39 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, m;
int num[1000005];
long long func(long long len) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (num[i] > len) {
      sum += num[i] - len;
    }
  }
  return sum;
}

int main() {
  cin >> n >> m;
  int r = 0;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    r = max(r, num[i]);
  }

  int l = 0;
  while (l != r) {
    long long mid = (l + r + 1) / 2;
    long long s = func(mid);
    if (s >= m) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;

  return 0;
}
