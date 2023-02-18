/*************************************************************************
	> File Name: 223.oj_2.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Thu 07 Jan 2021 01:06:20 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
template <typename Node>
class SegmentTree{
public:    
    SegmentTree(){};
    void build(const vector<int> &arr);
    void modify(int l, int r, int x);
    Node query(int l, int r);
private:
    vector<Node> tree;
};




struct Node {
    long long val, mul = 1, add;
};


int main() {
    int n, m, a, b, c, d;

    scanf("%d%d", &n, &m);
    vector<int> arr;
    arr.push_back(0);
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        arr.push_back(tmp);

    }

    SegmentTree<Node> tree;
    tree.build(arr);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a);
        switch (a) {
            case '1': {
                scanf("%d%d%d", &b, &c, &d);
                tree.modify(b, c, d);
            } break;
            case 2: {
                scanf("%d%d", &b, &c);
                printf("%lld\n", tree.query(b, c).val);
            } break;

        }
    }



}
