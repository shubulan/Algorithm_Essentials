/*************************************************************************
	> File Name: 387_2.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 27 Nov 2020 11:09:21 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int n, id;
};
int m, n;
node arr[100005];
int cmp(const node &a, const node &b) {
    return a.n < b.n;
}
int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> arr[i].n;
        arr[i].id = i;
    }
    arr[n + 1].id = 0;
    arr[n + 1].n = 2100000000;
    sort(arr + 1, arr + m + 1, cmp);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int l = 1, r = m + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid].n >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << arr[l].id << endl;
    }

    return 0;
}
