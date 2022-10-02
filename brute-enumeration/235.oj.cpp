/*************************************************************************
	> File Name: 235.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Sun 15 Nov 2020 02:35:11 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, num[15];
void init(int n) {
    for (int i = 1; i <= n; i++) {
        num[i] = i;
    }
}
void p(int deep) {
    for (int i = 1; i <= deep; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
    return ;
}

void func(int s, int deep) {
    for (int i = s; i <= n; i++) {
        num[deep] = i;
        p(deep);
        func(i + 1, deep + 1);
    }
    return ;
}

int main() {
    cin >> n;
    func(1, 1);


    return 0;
}
