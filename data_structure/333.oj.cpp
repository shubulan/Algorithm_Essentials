/*************************************************************************
	> File Name: 333.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Tue 12 Jan 2021 08:00:54 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 500000
#define L(ind) (ind<<1)
#define R(ind) (ind<<1 | 1)
#define SUM(ind) tree[ind].sum
#define INMAX(ind) tree[ind].inmax
#define LMAX(ind) tree[ind].lmax
#define RMAX(ind) tree[ind].rmax

struct Data{
    int sum, inmax, lmax, rmax;
} tree[(MAX_N << 2) + 5];

int n, m, val[MAX_N + 5], flag;

void update(int ind) {
    SUM(ind) = SUM(L(ind)) + SUM(R(ind));
    LMAX(ind) = max(LMAX(L(ind)), SUM(L(ind))+ LMAX(R(ind)));
    LMAX(ind) = max(RMAX(L(ind)), SUM(R(ind))+ RMAX(R(ind)));
    //INMAX(ind) = max(max(INMAX(L(ind)), SUM(L(ind))+ LMAX(R(ind)));
    return ;
}

void build(int ind, int l, int r) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = val[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(ind << 1, l, mid);
    build(ind << 1 | 1, mid + 1, r);
    update(ind);
    return ;
}
void modify(int ind, int l, int r, int i, int x) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = x;
        return ;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
        modify(L(ind), l, mid, i, x);
    } else {
        modify(R(ind), mid + 1, r, i, x);
    }
    update(ind);
    return ;
}
Data query(int ind, int l, int r, int x, int y) {
    if (x <= 1 && r <= y) {
        update(n + 1, 0, ind);
    }

}


void solve() {
    cin >> n >> m;
    for (int i = 1; i <=n; i++) {
        cin >> val[i];
    }
    build(1, 1, n);
    int k, a, b;
    for (int i = 0; i < m; i++) {
        cin >> k >> a >> b;
        switch (k) {
            case 1: {
                flag = 1;
                query(1, 1, n, x, y);
                cout << INMAX(0) << endl;

            } break;
            case 2: {
                modify(1, 1, n, a, b);

            } break;
        }
    }
}

int main() {
    solve();

    return 0;
}
