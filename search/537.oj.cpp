/*************************************************************************
	> File Name: 537.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Mon 23 Nov 2020 04:29:23 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int L, c, cnt, ynum, fnum;
char num[30], ans[30];
void p() {
    for (int i = 0; i < L; i++) {
        cout << ans[i];
    }
    cout << endl;
}
int func(int s, int left, int deep) {
    if (deep == L) {
        if (ynum >= 1 && fnum >= 2) {
            p();
            cnt++;
            if (cnt == 25000) {
                return 1;
            }
        }
        return 0;
    }
    for (int i = s; i < c; i++) {
        ans[deep] = num[i];
        int f = 0;
        if (num[i] == 'a' || num[i] == 'e' || num[i] == 'i' ||  num[i] == 'o' || num[i] == 'u') {
            ynum++;
            f = 1;
        } else {
            fnum++;
        }
        if (func(i + 1,left - 1, deep + 1) == 1) {
            return 1;
        }
        if (f == 0) {
            fnum--;
        } else {
            ynum--;
        }
    }
}

int main() {
    cin >> L >> c;
    for (int i = 0; i < c; i++) {
        cin >> num[i];
    }
    sort(num, num + c);
    func(0, L, 0);



    return 0;
}
