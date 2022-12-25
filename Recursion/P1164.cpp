#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int dp[10005];

int main() {
  int n, m;
  cin >> n >> m;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    for (int j = m; j - a >= 0; j--) {
      dp[j] += dp[j - a];
    }
  }
  cout << dp[m] << endl;

  return 0;
}