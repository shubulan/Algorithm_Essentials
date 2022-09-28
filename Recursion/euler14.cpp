/*************************************************************************
	> File Name: euler14.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Thu 29 Oct 2020 09:22:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int num[10000000];
int func(long long n) {
    if (n == 1) return 1; 
    if (n < 10000000 && num[n]) return num[n];
    int t;
    if (n % 2 == 0) {
        t = func(n / 2) + 1;
    } else {
        t = func(3 * n + 1) + 1;
    }
    if (n < 10000000) {
        num[n] = t;
    }
    return t;
}

int main() {
    int ans = 0, seq = 0;
    for (int i = 2; i <= 1000000; i++) {
        int t = func(i);
        if (seq < t) {
            ans = i;
            seq = t; 
        }
    }
    cout << ans << " : " << seq << endl;
    return 0;
}
