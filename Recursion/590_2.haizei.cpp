/*************************************************************************
        > File Name: 590.haizei.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Fri 30 Oct 2020 08:12:07 PM CST
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int tree[1005][1005];
int dp1[1005][1005];  // 上往下
int dp2[1005][1005];  // 下往上
int ans[1005][1005];
int mmax[1005][2];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      scanf("%d", &tree[i][j]);
      dp1[i][j] = max(dp1[i - 1][j - 1], dp1[i - 1][j]) + tree[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
      dp2[i][j] = max(dp2[i + 1][j + 1], dp2[i + 1][j]) + tree[i][j];
      ans[i][j] = dp1[i][j] + dp2[i][j] - tree[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    int m2 = 0, m1 = 0, cnt = 0;
    for (int j = 1; j <= i; j++) {
      if (ans[i][j] > m1) {
        m2 = m1;
        m1 = ans[i][j];
        cnt = j;
      } else if (m2 < ans[i][j]) {
        m2 = ans[i][j];
      }
    }
    mmax[i][0] = cnt;  // 最大值的坐标
    mmax[i][1] = m2;   // 次大值
  }
  printf("cacl done\n");
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 1 && b == 1) {  // ban掉1，不可通行
      printf("-1\n");
    } else if (mmax[a][0] == b) {  // ban掉的位置是能够获得最大值的位置
      printf("%d\n", mmax[a][1]);  // 输出次大值
    } else {
      printf("%d\n", dp2[1][1]);
    }
  }
  return 0;
}
