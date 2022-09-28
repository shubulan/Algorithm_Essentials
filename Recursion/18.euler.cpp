/*************************************************************************
	> File Name: 18.euler.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 30 Oct 2020 07:35:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int dp[20][20];
int main() {
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
        }
    }
    //for (int i = 1; i <= 15; i++) {
    //    for (int j = 1; j <= i; j++) {
    //        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + dp[i][j];
    //    }
    //}
    //int ans = -1;

    //for (int i = 1; i <= 15; i++) {
    //    ans = max(ans, dp[15][i]);
    //}
    //cout << ans << endl;
    for (int i = 15; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i+1][j+1], dp[i+1][j]) + dp[i][j];
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}
