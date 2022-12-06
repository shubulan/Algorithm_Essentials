#include <iostream>
using namespace std;
#define MAX_N 400
int dp[MAX_N + 5][MAX_N + 5];
int V, W, n;

int main() {
    cin >> V >> W >> n;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        for (int j = V; j >= a; j--) {
            for (int k = W; k >= b; k--) {
                dp[j][k] = max(dp[j - a][k - b] + c, dp[j][k]);
            }
        }
    }
    cout << dp[V][W] << endl;
    return 0;
}

