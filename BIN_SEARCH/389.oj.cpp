/*************************************************************************
	> File Name: 389.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Mon 02 Nov 2020 01:13:32 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int id[100005];
int func(int n) {
    int cnt = 1;
    int last = 0;
    for (int i = 1; i < m; i++) {
        if (id[i] - id[last] < n) continue;
        cnt++;
        last = i;
    }
    return cnt;
}

int main() {
    cin >> m >> n;
    int l = 1, r = 0;
    for (int i = 0; i < m; i++) {
        cin >> id[i];
        r = max(r, id[i]);
    }
    sort(id, id + m);
    while (l != r) {
        int mid = (l + r + 1) / 2;
        if (func(mid) >= n) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
    

    return 0;
}
