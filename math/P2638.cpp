#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
/**
 * 本题目很有意思。
 * 容易想到F(n, a, b)表示答案，则有
 * F(n, a, b) = sumi..a(sumj..b(F(n - 1, i, j))), 其中F(0, 0, 0) = 1;
 * 最大值F(25, 25, 25) = 1 5979 6414 1996 0227 3870 5081 3504，非常大。
 * 可能有人想到得用ull来存，但是可能想不到的是还不够，得用大整数来存。
 * 此外，该题目整理后，会发现，就是对一个二维矩阵做n + 1次前缀和，
 * 所以答案可以写的很简洁。
 */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int N = 55;
vector<int> add(const vector<int>& A, const vector<int>& B) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size() || i < B.size(); i++) {
    if (i < A.size()) t += A[i];
    if (i < B.size()) t += B[i];
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) C.push_back(t);
  if (C.size() == 0) C.push_back(0);
  return C;
}
vector<int> sub(const vector<int>& A, const vector<int>& B) {
  // 必须有A > B, 不处理负数;
  vector<int> C;
  for (int i = 0; i < A.size() || i < B.size(); i++) {
    int t = 0;
    if (i < B.size()) t = B[i];
    C.push_back(A[i] - t);
  }
  for (int i = 0; i < C.size(); i++) {
    if (C[i] >= 0) continue;
    C[i] += 10;
    C[i + 1] -= 1;
  }
  while (C.size() && C.back() == 0) C.pop_back();
  return C;
}
vector<int> f[N][N];
ULL n, a, b;
vector<int> ans;
int main() {
  cin >> n >> a >> b;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= a; j++) {
      for (int k = 0; k <= b; k++) {
        if (j == 0 && k == 0)
          f[j][k] = {1};
        else {
          if (j - 1 >= 0) f[j][k] = add(f[j - 1][k], f[j][k]);
          if (k - 1 >= 0) f[j][k] = add(f[j][k - 1], f[j][k]);
          if (j - 1 >= 0 && k - 1 >= 0) f[j][k] = sub(f[j][k], f[j - 1][k - 1]);
        }
      }
    }
  }
  int s = f[a][b].size();
  for (int i = s - 1; i >= 0; i--) cout << f[a][b][i];
  cout << endl;
  return 0;
}