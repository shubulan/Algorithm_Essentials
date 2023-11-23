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