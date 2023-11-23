#include <cstring>
#include <iostream>
using namespace std;

const int N = 22, M = (1 << 20) + 5;

int G[N][N];
int dp[N][M];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> G[i][j];
  memset(dp, 0x3f, sizeof dp);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1 << 20; j++) {
      for (int k = 0; k < 20; k++) {
        if (j & (1 << k)) {
          dp[i][j] = min(dp[i][j], dp[k][j ^ (1 << k)] + G[k][i]);
        }
      }
    }
  }
  cout << dp[n - 1][(1 << n) - 1] << endl;

  return 0;
}
