/*************************************************************************
	> File Name: 16.euler.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 13 Nov 2020 03:59:05 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int ans, num[1005] = {1, 1}, mid[1005] = {1, 2};
int sss[1005];
void mul(int a[], int b) {
    memset(sss, 0, sizeof(int) * 1005);
    int b0 = (int)log10(b) + 1;
    sss[0] = a[0] + b0 - 1; 
    for (int i = 1; i <= a[0]; i++) {
        sss[i] += a[i] * b;;
    }
    a[0] = sss[0];
    for (int i = 1; i <= a[0]; i++) {
        if (sss[i] > 9) {
            sss[i + 1] += sss[i] / 10;
            sss[i] %= 10;
            if (i == a[0]) a[0]++;
        } 
        a[i] = sss[i]; 
    }
}
int main() {
    int n = 100; 
    while (n != 0) {
        mul(num, n);
        n--;
    }
    for (int i = 1; i <= num[0]; i++) {
        ans += num[i];
    }
    cout << ans << endl;
    return 0;
}
