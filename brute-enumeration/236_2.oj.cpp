/*************************************************************************
	> File Name: 236_2.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Sun 15 Nov 2020 03:28:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, m, num[15];
void p() {
    for (int i = 1; i <= m; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
    return ;
}

void func(int s, int deep) {
    if (deep > m) {
        return ;
    } 
    for (int i = s; i <= n; i++) {
        num[deep] = i; 
        if (deep == m) {
            p();
        }
        deep++;
        func(i + 1, deep);
        deep--;
    }
}

int main() {
    cin >> n >> m;
    func(1, 1);
    return 0;
}
