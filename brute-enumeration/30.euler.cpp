/*************************************************************************
	> File Name: 30.euler.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 06 Nov 2020 09:35:20 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int num[10];
void init() {
    for (int i = 1; i <= 9; i++) {
        int t = i;
        for (int j = 1; j < 5; j++) {
            t *= i;
        }
        num[i] = t; 
    }
}
int check(int x) {
    int raw = x, t = 0;
    while (x) {
        t += num[x % 10];
        x /= 10;
    }
    return raw == t;
}
int main() {
    int ans = 0;
    init();
    for (int i = 10; i < 1000000; i++) {
        if (check(i)) {
            ans += i;
            cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
