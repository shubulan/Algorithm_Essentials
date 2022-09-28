/*************************************************************************
	> File Name: 16.euler.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 13 Nov 2020 03:59:05 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int ans, num[1005] = {1, 1}, mid[1005] = {1, 2};
int sss[1005];
void mul(int a[], int b[]) {
    memset(sss, 0, sizeof(int) * 1005);
    cout << "before mul\n";
    for (int i = a[0]; i >= 1; i--) {
        cout << a[i];
    }
    cout << endl;
    sss[0] = a[0] + b[0] - 1; 
    for (int i = 1; i <= a[0]; i++) {
        for (int j = 1; j <= b[0]; j++) {
            sss[i + j - 1] += a[i] * b[j];;
        }
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
    cout << "after mul\n";
    for (int i = a[0]; i >= 1; i--) {
        cout << a[i];
    }
    cout << endl;
}
int main() {
    int n = 1000; 
    while (n != 1) {
        cout << "n = " << n << endl;
        if (!(n % 2)) {
            cout << "self mul\n";
            mul(mid, mid);
        } else {
            cout << "self and ans mul\n";
            mul(num, mid);
            mul(mid, mid);
            n = n - 1;
        }
        n /= 2;
    }
    mul(num, mid);
    for (int i = 1; i <= num[0]; i++) {
        ans += num[i];
    }
    cout << ans << endl;
    return 0;
}
