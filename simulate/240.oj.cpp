/*************************************************************************
	> File Name: 240.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Sun 15 Nov 2020 02:19:22 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int num[10] = {0, 1};
char mmap[3000][3000];
void init() {
    for (int i = 2; i <= 7; i++) {
        num[i] = num[i-1] * 3;
    }
}
void func(int x, int y, int n) {
    if (n == 1) {
        mmap[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);

    return ;
}
int main() {
    init(); 
    func(1, 1, 7);
    int t;
    while (cin >> t) {
        if (t == -1) {
            break;
        }
        for (int i = 1; i <= num[t]; i++) {
            for (int j = 1; j <= num[t]; j++) {
                if (mmap[i][j] == 'X') {
                    cout << 'X';
                } else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        cout << "-" << endl;
    }

    return 0;
}
