/*************************************************************************
	> File Name: 393.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Mon 02 Nov 2020 02:09:29 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
double num[100005], tr;
int func(double len) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += num[i] / len;
    }
    return sum;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }
    double l = 0.0, r = tr;
    while (r - l > 0.00001) {
        double mid = (r + l) / 2;
        int s = func(mid);
        if (s >= m) {
            l = mid; 
        } else {
            r = mid;
        }
    }
    
    printf("%.2lf\n", (int)(l * 100) / 100.0);

    return 0;
}
