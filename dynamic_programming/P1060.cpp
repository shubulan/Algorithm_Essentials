#include <iostream>
using namespace std;
#define MAX_N 30000
int n, m;
int V[MAX_N + 5], W[MAX_N + 5];
int dp[30][MAX_N + 5];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> V[i] >> W[i];
    W[i] *= V[i];
  }
  // dp[i][v] 表示前i个物品，限制价格为v时，能买到的最大价值
  ///    for (int i = 1; i <= m; i++) {
  ///       for (int v = 1; v <= n; v++) {
  ///         dp[i][v] = dp[i - 1][v];
  ///    	    if (v >= V[i])
  ///    	        dp[i][v] = max(dp[i][v], dp[i - 1][v - V[i]] + W[i]);
  ///       }
  ///
  ///    }
  ///    cout << dp[m][n] << endl;
  //
  // dp[i][v]表示从物品i开始选，限制价格为v时，能买到的最大价值
  //    for (int i = m; i >= 0; i--) {
  //        for (int j = 0; j <= n; j++) {
  //            dp[i][j] = dp[i + 1][j];
  //            if (j >= V[i])
  //                dp[i][j] = max(dp[i][j], dp[i + 1][j - V[i]] + W[i]);
  //        }
  //    }
  //    cout << dp[0][n] << endl;
  //  状态定义还是1: 表示前i个物品，限制价格为j时，能买到的最大价值
  //  状态转移思想2: 之前的思想都是，我可以从谁转移而来,
  //  其实也可以逆过来：我可以转移到哪些状态
  //    for (int i = 0; i < m; i++) {
  //        for (int j = 0; j <= n; j++) {
  //            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
  //            if (j + V[i + 1] <= n)
  //                dp[i + 1][j + V[i + 1]] = max(dp[i + 1][j + V[i + 1]],
  //                dp[i][j] + W[i + 1]);
  //        }
  //    }
  //    cout << dp[m][n] << endl;
  //
  // 状态定义还是1: 表示前i个物品，限制价格为j时，能买到的最大价值
  // 最好想的是我可以从谁转移而来,以此为例来空间优化
  // 空间优化
  for (int i = 1; i <= m; i++) {
    for (int j = n; j >= V[i]; j--) {
      dp[0][j] = max(dp[0][j], dp[0][j - V[i]] + W[i]);
    }
  }
  cout << dp[0][n] << endl;

  return 0;
}