---
head:
  - - link
    - rel: stylesheet
      href: https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.5.1/katex.min.css
---
# sec 01 线段树与树状数组

## 一、问题背景
积性函数的区间的修改与查询，
1. 单点修改，区间查询（基础版）
2. 区间修改，区间查询（进阶版）
本质上是分治算法，将两段相邻区间进行归并

## 二、存储方式：
正常计算是2n，但要是用完全二叉树来存储的话，得开到 $4n$
完全二叉树：要开4n空间

## 三、基础版线段树
* 在 $O(log(n))$ 的时间复杂度下，
  * 求 $[s, t]$ 的最小值
  * 给定 $i$ 和 $x$, 把 $a_i$ 改为 $x$

[oj222. 练习题1：线段树模板(一)](https://oj.haizeix.com/problem/222)
  * [code](./data_structure/1.HZOJ222.md)

### 应用
* [物块放置查询](https://leetcode.cn/problems/block-placement-queries/description/)
  * [code](./data_structure/leetcode_100314.md)

## 四、进阶版线段树 区间修改 懒标记 
1. 优化掉l,r
2. 可以用区间更新，区间查询
3. 增加懒标记，达到更新区间的目的
4. 懒标记是需要向下下沉的
5. 标记下沉发生在递归之前，向上更新发生在具有修改操作的递归之后
6. 实现起来比较复杂，使用该数据结构之前，请先考虑其他区间修改的办法，比如：差分。如果确定要用，做好认真调试的准备。

* [223. 练习题2：线段树模板(二)](https://oj.haizeix.com/problem/223)
  * [源码](./data_structure/223.oj.md)

* [2569. 更新数组后处理求和查询](https://leetcode.cn/problems/handling-sum-queries-after-update/description/)
  * [code](./data_structure/leetcode2569.md)


## 树状数组

1. $lowbit$ 函数
```c++
int lowbit(x) { return x & (-x); }

2. 查询：向下统计
```c++
while (i) {
  
  i -= lowbit(i);
}
3. 修改：向上修改
```c++
while (i <= n) {

  i += lowbit(i);
}
```
* [#329. 弱化的整数问题](https://oj.haizeix.com/problem/329)
  * [源码](./data_structure/329.oj.md)
* [#330. 加强的整数问题](https://oj.haizeix.com/problem/330)
  * [源码](./data_structure/330.oj.md)

* [#331. Lost_cows](https://oj.haizeix.com/problem/331)
  * [源码](./data_structure/331.oj.md)
  * 树状数组 + 二分

* [332 买票](https://oj.haizeix.com/problem/332)
  * [源码](./data_structure/332.oj.md)
    1. 与上道题只差1点点
    2. 每个人都有编号，最后一个插入的，知道自己前面有几个人，所以能推算出自己的编号
* [328 楼兰图腾](https://oj.haizeix.com/problem/328)
  * [源码](./data_structure/2.HZOJ328-60.md)

* [333 最大子段和](https://oj.haizeix.com/problem/333)
  * [源码](./data_structure/333_2.oj.md)
  > 线段树中比较有难度的题
