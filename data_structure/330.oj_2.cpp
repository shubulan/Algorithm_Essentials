/*************************************************************************
	> File Name: 330.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 05 Feb 2021 03:45:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
#define lowbit(x) (x & (-x))

long long X[2][MAX_N + 5];
int n, m;
void modify(int op, int i, int val, int n) {
    while (i <= n) {
        X[op][i] += val;
        i += lowbit(i);
    }
}
long long query(int op, int a) {
    long long ans = 0;
    while (a > 0) {
        ans += X[op][a];
        a -= lowbit(a);
    }
    return ans;
}
long long Sum(int i) {
    return (i + 1) * query(0, i) - query(1, i);
}
long long func(int a, int b) {
    return Sum(b) - Sum(a - 1);
}
int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        modify(0, i, a, n);
        modify(0, i + 1, -a, n);
        modify(1, i, i * a, n);
        modify(1, i + 1, (i + 1) * (-a), n);
    }
    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s[i] == 'C') {
            cin >> a >> b >> c; 
            modify(0, a, c, n);
            modify(0, b + 1, -c, n);
            modify(1, a, c * a, n);
            modify(1, b + 1, -c * (b + 1), n);
        } else {
            cin >> a >> b; 
            cout << func(a, b) << endl;
        }
    }





    return 0;
}
