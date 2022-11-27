#include <iostream>
using namespace std;
#define MAX_N 1000

int n, m;

//int dp[MAX_N + 5][MAX_N + 5];
int dp[MAX_N + 5];
int g[MAX_N + 5][MAX_N + 5];
int d[MAX_N + 5];
int w[MAX_N + 5], v[MAX_N + 5];
int ctg = 0, cnt = 0;

int main()
{
    cin >> m >> n;
    int c;
    int num = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> c;
        num = max(num, c);
        d[c]++;
        g[c][d[c]] = i;
    }
    for (int i = 1; i <= num; i++) {
        for (int j = m; j >= 0; j--) {
            //dp[i][j] = dp[i - 1][j];
            dp[j] = dp[j];
            for (int k = 1; k <= d[i]; k++) {
                if (j - w[g[i][k]] >= 0) {
                    //dp[i][j] = max(dp[i][j], dp[i - 1][j - w[g[i][k]]] + v[g[i][k]]);
                    dp[j] = max(dp[j], dp[j - w[g[i][k]]] + v[g[i][k]]);
                }

            }
        }
    }
    //cout << dp[num][m] << endl;
    cout << dp[m] << endl;
    return 0;
}
