/*************************************************************************
        > File Name: 331.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Tue 12 Jan 2021 06:33:30 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 80000
int c[MAX_N + 5];
#define lowbit(x) (x & -x)
void add(int i, int x, int n) {
  while (i <= n) {
    c[i] += x;
    i += lowbit(i);
  }
  return;
}
int query(int i) {
  int sum = 0;
  while (i) {
    sum += c[i];
    i -= lowbit(i);
  }
  return sum;
}
int binary_search(int n, int x) {
  int head = 1, tail = n, mid;
  while (head < tail) {
    mid = (head + tail) >> 1;
    if (query(mid) < x) {
      head = mid + 1;
    } else {
      tail = mid;
    }
  }
  return tail;
}

int arr[MAX_N + 5];
int n;
void solve() {
  for (int i = n; i >= 1; --i) {
    arr[i] = binary_search(n, arr[i] + 1);
    add(arr[i], -1, n);
  }
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    add(i, 1, n);
  }
  solve();
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}
