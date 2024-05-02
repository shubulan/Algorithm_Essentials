/*************************************************************************
        > File Name: 330.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Tue 12 Jan 2021 02:43:26 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
#define lowbit(x) (x & -x)
long long X[MAX_N + 5], Y[MAX_N + 5];
void add(int ind, long long a, int n) {
  int i = ind;
  while (ind <= n) {
    X[ind] += a;
    Y[ind] += i * a;
    ind += lowbit(ind);
  }
}
long long query(int ind) {
  long long sum = 0;
  int i = ind + 1;
  while (ind > 0) {
    sum += i * X[ind];
    sum -= Y[ind];
    ind -= lowbit(ind);
  }
  return sum;
}
// long long S(int i) {
//    return (i + 1) * query(0, i) - query()
//}

int main() {
  long long n, m, pre = 0, a;
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a);
    add(i, a - pre, n);
    pre = a;
  }
  char op[10];
  int x, y, z;
  for (int i = 0; i < m; i++) {
    scanf("%s", op);
    switch (op[0]) {
      case 'C': {
        scanf("%d%d%d", &x, &y, &z);
        add(x, z, n);
        add(y + 1, -z, n);
      } break;
      case 'Q': {
        scanf("%d%d", &x, &y);
        long long ans = query(y);
        ans -= query(x - 1);
        printf("%lld\n", ans);
      } break;
    }
  }

  return 0;
}
