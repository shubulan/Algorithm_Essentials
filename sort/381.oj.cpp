/*************************************************************************
        > File Name: 381.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Mon 02 Nov 2020 10:57:03 AM CST
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct node {
  string name;
  int esco;
  int csco;
  char gb;
  char ws;
  int lw;
  int idx;
  int jxj;
};
void getjxj(node &a) {
  a.jxj = 0;
  if (a.esco > 80 && a.lw > 0) a.jxj += 8000;
  if (a.esco > 85 && a.csco > 80) a.jxj += 4000;
  if (a.esco > 90) a.jxj += 2000;
  if (a.esco > 85 && a.ws == 'Y') a.jxj += 1000;
  if (a.csco > 80 && a.gb == 'Y') a.jxj += 850;
}
bool cmp(const node &a, const node &b) {
  if (a.jxj == b.jxj) {
    return a.idx < b.idx;
  }
  return a.jxj > b.jxj;
}

node stu[105];
int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> stu[i].name >> stu[i].esco >> stu[i].csco >> stu[i].gb >>
        stu[i].ws >> stu[i].lw;
    stu[i].idx = i;
    getjxj(stu[i]);
    sum += stu[i].jxj;
  }
  sort(stu, stu + n, cmp);
  cout << stu[0].name << endl;
  cout << stu[0].jxj << endl;
  cout << sum << endl;
  return 0;
}
