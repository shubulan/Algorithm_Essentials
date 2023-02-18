/*************************************************************************
	> File Name: 223_2.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Sun 27 Dec 2020 10:15:15 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;
#define MAX_N 10000
#define define_mid int mid = (l + r) >> 1
struct {
    int sum, tag;
} tree[MAX_N << 2];

int arr[MAX_N + 5];
void update(int ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
    return ;
}
void build_tree(int ind, int l, int r) {
    if (l == r) {
        tree[l].sum = arr[l];
        return ;
    }
    define_mid;
    build_tree(ind << 1, l, mid);
    build_tree(ind << 1 | 1, mid + 1, r);
    update(ind);
    return ;
}

void down(int ind, int l, int r) {
    if (tree[ind].tag) {
        int val = tree[ind].tag;
        define_mid;
        tree[ind << 1].sum += val * (mid - l + 1);
        tree[ind << 1].tag += val;
        tree[ind << 1 | 1].sum += val * (r - mid);
        tree[ind << 1 | 1].tag += val;

        tree[ind].tag = 0;
    }
    return ;
}

void modify(int ind, int l, int r, int x, int y, int  val) {
    if (x <= l && r <= y) {
        tree[ind].sum += val * (r - l + 1);
        tree[ind].tag += val;
        return ;
    }
    down(ind, l, r);
    define_mid;
    if (mid >= x) {
        modify(ind << 1, l, mid, x, y, val);
    }
    if (mid < y) {
        modify(ind << 1 | 1, mid + 1, r, x, y, val);
    }
    update(ind);

    return ;
}

int query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    down(ind, l, r);
    define_mid;
    int ans = 0;
    if (mid >= x) {
        ans += query(ind << 1, l, mid, x, y);
    }
    if (mid < y) {
        ans += query(ind << 1 | 1, mid + 1, r, x, y);
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: {
                int d;
                scanf("%d", &d);
                modify(1, 1, n, b, c, d);
            } break;
            case 2: {
                if (b > c) {
                    printf("0\n");
                    break;
                }
                printf("%d\n", query(1, 1, n, b, c));
                
            } break;
        }
        
    }




    return 0;
}
