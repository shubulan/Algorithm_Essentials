/*************************************************************************
	> File Name: 32.euler.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Thu 05 Nov 2020 09:17:42 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int digit(int x) {
    return (int)floor(log10(x)) + 1;
}
int check(int x, int *num) {
    while (x) {
        if (num[x % 10] == 1) {
            return 0;
        }
        num[x % 10] = 1;
        x /= 10;
    }
    return 1;
}
int mark[10005] = {0};
int func(int i, int j, int ij) {
    int num[10] = {1};//细节，为什么0是1
    if (check(i, num) == 0) return 0;
    if (check(j, num) == 0) return 0;
    if (check(ij, num) == 0) return 0;
    return 1;    
}


int main() {
    int ans = 0; 
    for (int i = 1; i < 100; i++) {
        for (int j = 100; j < 10000; j++) {
            int a = digit(i), b = digit(j), c = digit(i * j);
            if (a + b + c == 9) {
                if (func(i, j, i * j)) {
                    if (mark[i * j] == 0) {
                        mark[i * j] = 1;
                        ans += i * j;
                        cout << i << " * " << j << " = " << i * j << endl;
                    }
                } 
            }
        }
    }
    cout << ans << endl;
    return 0;
}
