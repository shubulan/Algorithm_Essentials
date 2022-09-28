/*************************************************************************
	> File Name: euler4.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Thu 29 Oct 2020 07:46:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int func(int x) {
    int t = 0, raw = x;
    while (x) {
        t = t * 10 + x % 10;
        x /= 10;
    }
    return t == raw;
}
int main() {
    int ans = 0, px, py;
    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int t = i * j;
            if (t > ans && func(t)) {
                ans = t;
                px = i;
                py = j;
            }
        }
    }
    cout << ans << endl;
    cout << px << " " << py << endl;
    return 0;
}
