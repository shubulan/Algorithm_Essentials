#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


const int N = 22, M = (1 << 20) + 5;

int G[N][N];
int dp[M][N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];

    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int i = 0; i < 1 << n; i++) {
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          for (int k = 0; k < n; k++) {
            if ((i ^ (1 << j)) & (1 << k))
              dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + G[k][j]);
          }
        }
      }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;


    return 0;
}