/*************************************************************************
	> File Name: 542.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Mon 23 Nov 2020 05:12:53 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int t, n, h, r, s[1005], scnt, e[1005], arr[1005][1005], check[1005];
int ball[1005][3];

int func(int now) {
    if (e[now] == 1) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[now][i] && check[i] == 0) {
            check[i] = 1; 
            if (func(i)) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    cin >> t;
    while (t--) {
        scnt = 0;
        cin >> n >> h >> r;
        memset(e, 0, sizeof(e));
        memset(arr, 0, sizeof(arr));
        memset(check, 0, sizeof(check));
        for (int i = 1; i <= n; i++) {
            cin >> ball[i][0] >> ball[i][1] >> ball[i][2];
            if (ball[i][2] <= r) {
                s[scnt++] = i;
            }
            if (ball[i][2] + r >= h) {
                e[i] = 1;
            }
            for (int j = 1; j < i; j++) {
                int x0 = ball[i][0] - ball[j][0];
                int y0 = ball[i][1] - ball[j][1];
                int z0 = ball[i][2] - ball[j][2];
                if (sqrt(x0 * x0 + y0 * y0 + z0 * z0) <= 2 * r) {
                    arr[i][j] = arr[j][i] = 1;
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < scnt; i++) {
            if (check[s[i]] == 0) {
                check[s[i]] = 1;
                if (func(s[i]) == 1) {
                    cout << "Yes" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            cout << "No" << endl;
        }

    }

    return 0;
}
