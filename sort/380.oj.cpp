/*************************************************************************
        > File Name: 380.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Mon 02 Nov 2020 10:38:30 AM CST
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct node {
  int num;
  string s;
};
int n;
node cad[105];
bool cmp(const node &a, const node &b) {
  if (a.s.size() == b.s.size()) {
    return a.s > b.s;
  }
  return a.s.size() > b.s.size();
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> cad[i].s;
    cad[i].num = i;
  }
  sort(cad + 1, cad + n + 1, cmp);
  cout << cad[1].num << endl << cad[1].s << endl;
  return 0;
}
