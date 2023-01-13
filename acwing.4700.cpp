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

int const N = 300000;
int dp[N + 5];


int main() {
  int n, m, sum = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      for (int j = N; j >= x; j--) {
          dp[j] = max(dp[j], dp[j - x] + x);
      }
      sum += x;
  }
  printf("%d\n", sum - dp[sum - m]);

  return 0;
}
