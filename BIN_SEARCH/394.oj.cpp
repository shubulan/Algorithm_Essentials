/*************************************************************************
        > File Name: 394.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Mon 02 Nov 2020 10:00:10 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int ll, n, m, num[50005], tl;
int func(int d) {
  int cnt = 0, last = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (num[i] - last < d) {
      cnt++;
    } else {
      last = num[i];
    }
  }
  return cnt;
}
int bin_search() {
  int l = tl, r = ll;
  while (l != r) {
    int mid = (l + r + 1) / 2;
    int s = func(mid);
    if (s <= m) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return r;
}
int main() {
  cin >> ll >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    if (i == 1) {
      tl = num[1] - num[0];
    } else {
      tl = min(num[i] - num[i - 1], tl);
    }
  }
  num[n + 1] = ll;

  cout << bin_search() << endl;

  return 0;
}
