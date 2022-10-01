/*************************************************************************
	> File Name: 386.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Mon 02 Nov 2020 11:19:59 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int idx;
    int m;
};
bool cmp(const node&a, const node&b) {
    return a.m < b.m;
}
node wm[100005];
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> wm[i].m;
        wm[i].idx = i+1;
    } 
    wm[n].idx = 0;
    wm[n].m = 2100000000; # 标记位
    sort(wm, wm + n + 1, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n; 
        cin >> t;
        while (l != r) {
            int mid = (l + r) / 2;
            if (t <= wm[mid].m) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << wm[r].idx  << endl;
    }
    return 0;
}
