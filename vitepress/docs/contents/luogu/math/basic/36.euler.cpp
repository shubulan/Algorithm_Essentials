/*************************************************************************
	> File Name: 36.euler.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 06 Nov 2020 09:19:31 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int func(int x, int n) {
    int raw = x, t = 0;
    while (x) {
        t = t * n + x % n;
        x /= n;
    }
    return t == raw;
}

int main() {
    long long ans = 0;
    for (int i = 1; i < 1000000; i++) {
        if (func(i, 10) && func(i, 2)) {
            cout << i << endl;
            ans += i;
        }
    }
    cout << ans << endl;

    return 0;
}
