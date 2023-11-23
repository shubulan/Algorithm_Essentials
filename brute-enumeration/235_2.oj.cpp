/*************************************************************************
        > File Name: 235_2.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Sun 15 Nov 2020 02:56:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, num[15], cnt;

void p() {
  for (int i = 0; i <= cnt; i++) {
    if (i) {
      cout << " ";
    }
    cout << num[i];
  }
  cout << endl;
}
void func(int s) {
  for (int i = s; i <= n; i++) {
    num[cnt] = i;
    p();
    cnt++;
    func(i + 1);
    cnt--;
  }
  return;
}

int main() {
  cin >> n;
  func(1);

  return 0;
}
