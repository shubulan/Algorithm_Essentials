# sec 01 线段树

## 一、问题背景
积性函数的区间的修改与查询，
1. 单点修改，区间查询（基础版）
2. 区间修改，区间查询（进阶版）
本质上是分治算法，将两段相邻区间进行归并

## 二、存储方式：
正常计算是2n，但要是用完全二叉树来存储的话，得开到4n
完全二叉树：要开4n空间

## 三、基础版线段树

1. 线段树是对于一维序列的维护结构
2. 采用的是分治的思想，将总区间分割成等大小的左右两个区间，直到区间中只剩下一个节点
3. 线段树的叶子节点，代表了原序列中的单个位置的值
4. 如果采用完全二叉树结构的话，至少要开辟**$4n$**个存储空间
5. 修改的时间复杂度是$log(n)$
6. 当面对区间(长度为x)修改时，基础版的线段树效率(xlog(n))上还不如直接在源区间(x)上修改
7. 区间查询的时间复杂度是$log(n)$，思考题。
8. 只适用于单点修改，区间查询。面对区间修改时，慢的多

[oj222. 练习题1：线段树模板(一)](https://oj.haizeix.com/problem/222)
```
#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const int N = 10000;
int arr[N + 5];

class SegmentTree {
  /**
   * 维护最大值的线段树
   */
 public:
  void init() { _build_tree(1, 0, _n, arr); }

  SegmentTree(int n) : _n(n), tree((n + 2) << 2) {}
  void modify(int idx, int val) { _modify(1, 0, _n, idx, val); }
  int query(int L, int R) { return _query(1, 0, _n, L, R); }

 private:
  void _build_tree(int root, int L, int R,
                   const vector<int>& arr = vector<int>()) {
    if (L == R) {
      if (arr.size()) {
        tree[root] = arr[L];
      }
      return;
    }
    int mid = (L + R) >> 1;
    _build_tree(root * 2, L, mid, arr);
    _build_tree(root * 2 + 1, mid + 1, R, arr);
    _update(root);
    return;
  }
  void _build_tree(int root, int L, int R, int* arr = nullptr) {
    if (L == R) {
      if (arr) {
        tree[root] = arr[L];
      }
      return;
    }
    int mid = (L + R) >> 1;
    _build_tree(root * 2, L, mid, arr);
    _build_tree(root * 2 + 1, mid + 1, R, arr);
    _update(root);
    return;
  }

  void _modify(int root, int rl, int rr, int idx, int val) {
    if (rl == rr) {
      tree[root] = val;
      return;
    }
    int mid = (rl + rr) >> 1;
    if (idx <= mid) {
      _modify(root << 1, rl, mid, idx, val);
    } else {
      _modify(root << 1 | 1, mid + 1, rr, idx, val);
    }
    _update(root);
    return;
  }

  int _query(int root, int rl, int rr, int L, int R) {
    if (rl >= L && rr <= R) {
      return tree[root];
    }
    int ans = INT_MIN;
    int mid = (rl + rr) >> 1;
    if (mid >= L) {
      ans = max(ans, _query(root << 1, rl, mid, L, R));
    }
    if (mid < R) {
      ans = max(ans, _query(root << 1 | 1, mid + 1, rr, L, R));
    }
    return ans;
  }
  void _update(int root) {
    tree[root] = max(tree[root << 1], tree[root << 1 | 1]);
    return;
  }
  // default [0, n] root is 1;
  int _n;
  vector<int> tree;
};

int main() {
  int n, m, a, b, c;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
  }
  // 为什么根节点是1？因为使用完全二叉树，好计算孩子坐标
  SegmentTree sg(n);
  sg.init();
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    switch (a) {
      case 1:
        sg.modify(b, c);
        break;
      case 2: {
        if (b > c) {
          cout << "-2147483648" << endl;
          break;
        }
        printf("%d\n", sg.query(b, c));
      } break;
    }
  }
  return 0;
}

```


## 四、进阶版线段树 区间修改 懒标记 
1. 优化掉l,r
2. 可以用区间更新，区间查询
3. 增加懒标记，达到更新区间的目的
4. 懒标记是需要向下下沉的
5. 标记下沉发生在递归之前，向上更新发生在具有修改操作的递归之后
6. 实现起来比较复杂，使用该数据结构之前，请先考虑其他区间修改的办法，比如：差分。如果确定要用，做好认真调试的准备。

* [223. 练习题2：线段树模板(二)](https://oj.haizeix.com/problem/223)[源码](./data_structure/223.oj.cpp)
* [2569. 更新数组后处理求和查询](https://leetcode.cn/problems/handling-sum-queries-after-update/description/)
```
#define define_mid int mid = (l + r) >> 1;
const int MAX_N = 100000;

struct {
  long long sum, tag;
} tree[MAX_N << 2];
long long arr[MAX_N + 5];

void update(int ind) {
  tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
  return;
}
void down(long long ind, long long l, long long r) {
  if (tree[ind].tag % 2) {
    define_mid;
    tree[ind << 1].sum = (mid - l + 1) - tree[ind << 1].sum;
    tree[ind << 1].tag += 1;
    tree[ind << 1 | 1].sum = (r - mid) - tree[ind << 1 | 1].sum;
    tree[ind << 1 | 1].tag += 1;
    tree[ind].tag = 0;
  } else {
    tree[ind].tag = 0;
  }
  return;
}
void build_tree(long long ind, long long l, long long r) {
  if (l == r) {
    tree[ind].sum = arr[l];
    return;
  }
  define_mid;
  build_tree(ind << 1, l, mid);
  build_tree(ind << 1 | 1, mid + 1, r);
  update(ind);
  return;
}
void modify(long long ind, long long l, long long r, long long x, long long y,
            long long val) {
  if (x <= l && r <= y) {
    tree[ind].sum = r - l + 1 - tree[ind].sum;
    tree[ind].tag += 1;
    return;
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
  return;
}
long long query(long long ind, long long l, long long r, long long x,
                long long y) {
  if (x <= l && r <= y) {
    return tree[ind].sum;
  }
  down(ind, l, r);
  define_mid;
  long long ans = 0;
  if (mid >= x) {
    ans += query(ind << 1, l, mid, x, y);
  }
  if (mid < y) {
    ans += query(ind << 1 | 1, mid + 1, r, x, y);
  }
  return ans;
}

class Solution {
 public:
  vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2,
                                vector<vector<int>>& queries) {
    int n = nums1.size();
    vector<long long> resv;
    memset(tree, 0, sizeof tree);
    for (int i = 0; i < n; i++) {
      arr[i] = nums1[i];
    }
    long long res = 0;
    for (int i = 0; i < n; i++) res += nums2[i];
    build_tree(1, 0, n - 1);
    for (auto& vec : queries) {
      int op = vec[0], l = vec[1], r = vec[2];
      if (op == 1) {
        modify(1, 0, n - 1, l, r, 1);
      } else if (op == 2) {
        long long x = query(1, 0, n - 1, 0, n - 1);
        res += x * l;
        // cout << x << endl;
      } else {
        resv.push_back(res);
      }
    }
    return resv;
  }
};
```