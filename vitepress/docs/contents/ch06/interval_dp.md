## 区间dp

> 区间dp更在于代码实现


* [石子合并](https://www.acwing.com/problem/content/284/)
   * [code](../acwing/acwing.282.md)
1. 例题：矩阵链乘法     简写版公式
2. 例题：最优二叉搜索树

* [矩阵链乘法]()
```c++
#include <iostream>
#include <vector>
using namespace std;
void print_res(vector<vector<int>> &s, int i, int j) {
  if (i == j) {
    cout << "A_" << i;
    return;
  }
  cout << "(";
  print_res(s, i, s[i][j]);
  print_res(s, s[i][j] + 1, j);
  cout << ")";
}
// 区间DP标准写法
int matrix_chain_order(const vector<int> &P) {
  int n = P.size();
  vector<vector<int>> m(n, vector<int>(n));
  vector<vector<int>> s(n, vector<int>(n));
  n--;                                       // n表示有多少矩阵
  for (int i = 1; i <= n; i++) m[i][i] = 0;  // 只有一个矩阵时，不用计算
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n + 1 - l; i++) {
      int j = i + l - 1;
      for (int k = i; k < j; k++) {
        int val = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
        if (val > m[i][j]) {
          m[i][j] = val;
          s[i][j] = k;
        }
      }
    }
  }
  // 使用递归来输出最优解
  print_res(s, 1, n);
  return m[1][n];
}

int main() {
  vector<int> p{5, 10, 3, 12, 5, 50, 6};
  matrix_chain_order(p);

  return 0;
}

```


## 计数类 DP
* [整数划分](acwing/acwing.900.cpp)
* [划分数]
* [leetcode 940. 不同的子序列 II](https://leetcode.cn/problems/distinct-subsequences-ii/)[

## 数位统计 DP
* [计数问题](acwing/acwing.338.cpp)

## 状态压缩 DP
* [蒙德里安的梦想](acwing/acwing.291.cpp)
* [最短 Hamiton 路径](acwing/acwing.91.cpp)

## 树形 DP
* [没有上司的舞会](acwing/acwing.285.cpp)

[362. 选课](https://oj.haizeix.com/problem/362)
[363. Strategic_game](https://oj.haizeix.com/problem/363)


## 记忆化搜索
* [滑雪](acwing/acwing.901.cpp)

## 状态机 DP
* [leetcode: 801. 使序列递增的最小交换次数](https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/)

## 环形DP
[364. Naptime](https://oj.haizeix.com/problem/364)
[365. 环路运输](https://oj.haizeix.com/problem/365)