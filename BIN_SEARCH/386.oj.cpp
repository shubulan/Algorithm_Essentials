/*************************************************************************
        > File Name: 386.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Mon 02 Nov 2020 11:19:59 AM CST
 ************************************************************************/

#include <algorithm>
#include <iostream>
using namespace std;
struct node {
  int idx;
  int m;
};
bool cmp(const node& a, const node& b) { return a.m < b.m; }
node wm[100005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> wm[i].m;
    wm[i].idx = i + 1;
  }
  sort(wm, wm + n, cmp);
  for (int i = 0; i < m; i++) {
    int t, f = 0, l = 0, r = n - 1;
    cin >> t;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (t == wm[mid].m) {
        f = wm[mid].idx;
        break;
      }
      if (t < wm[mid].m) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << f << endl;
  }
  return 0;
}
