# 线段树与树状数组

# 线段树

## 一、问题背景
---
积性函数的区间的修改与查询，

1. 单点修改，区间查询（基础版）
2. 区间修改，区间查询（进阶版）
3. 单点查询，单点查询（用不着线段树，就是数组）
4. 区间修改，单点查询（第二种情况的特例）

### 树形结构
* 树的节点，代表集合

* 树的边，代表关系

### 存储方式：
正常计算是2n，但要是用完全二叉树来存储的话，得开到4n
完全二叉树：要开4n空间



## 二、基础版线段树

1. 线段树是对于一维序列的维护结构
2. 采用的是分治的思想，将总区间分割成等大小的左右两个区间，直到区间中只剩下一个节点
3. 线段树的叶子节点，代表了原序列中的单个位置的值
4. 如果采用完全二叉树结构的话，至少要开辟**$4n$**个存储空间
5. 修改的时间复杂度是$log(n)$
6. 当面对区间(长度为x)修改时，基础版的线段树效率(xlog(n))上还不如直接在源区间(x)上修改
7. 区间查询的时间复杂度是$log(n)$，思考题。
8. 只适用于单点修改，区间查询。面对区间修改时，慢的多

[oj222. 练习题1：线段树模板(一)](https://oj.haizeix.com/problem/222)[源码](./data_structure/1.HZOJ222.cpp)



## 三、进阶版线段树 区间修改 懒标记 
1. 优化掉l,r
2. 可以用区间更新，区间查询
3. 增加懒标记，达到更新区间的目的
4. 懒标记是需要向下下沉的
5. 标记下沉发生在递归之前，向上更新发生在具有修改操作的递归之后
6. 实现起来比较复杂，使用该数据结构之前，请先考虑其他区间修改的办法，比如：差分。如果确定要用，做好认真调试的准备。

* [223. 练习题2：线段树模板(二)](https://oj.haizeix.com/problem/223)[源码](./data_structure/223.oj.cpp)
* [6358. 更新数组后处理求和查询](https://leetcode.cn/problems/handling-sum-queries-after-update/description/)[源码](./data_structure/leetcode.6358.cpp)

## 四、线段树模板提炼
1. 提炼出模板
2. 考验模板：通过模板把那几个题目都过掉。
* [普通线段树]()
* [懒标记线段树]()

# 树状数组

1. $lowbit(i)$函数

   lowbit(8) = 8;

   lowbit(6) = 2;

   lowbit(x) = x & (-x)
2. 查询：向前统计 i - lowbit(i)
3. 更新：更新单点，向后更新i + lowbit(i)

树状数组解决的问题，是前缀和，所以注意，做题时把问题转换成前缀和问题

4. 高效的前缀和数组，理解了之后，可以忘掉它，只记得前缀和即可


## 题目
例题

* [#329. 弱化的整数问题](https://oj.haizeix.com/problem/329) [源码](./data_structure/329.oj.cpp)
* [#330. 加强的整数问题](https://oj.haizeix.com/problem/330)[源码](./data_structure/330.oj.cpp)


训练：

* [#331. Lost_cows](https://oj.haizeix.com/problem/331)[源码](./data_structure/331.oj.cpp)
1. 思考的问题1：答案唯一么？唯一
2. 从后往前，记录哪些编号被占用了。
3. 对于索引标记数组的前缀和技巧
4. 树状数组+二分

* [332 买票](https://oj.haizeix.com/problem/332)[源码](./data_structure/332.oj.cpp)
1. 与上道题只差1点点
2. 每个人都有编号，最后一个插入的，知道自己前面有几个人，所以能推算出自己的编号
* [328 楼兰图腾](https://oj.haizeix.com/problem/328)[源码](./data_structure/2.HZOJ328-60.cpp)
* [333 最大子段和](https://oj.haizeix.com/problem/333)[源码](./data_structure/333_2.oj.cpp)
  > 线段树中比较有难度的题


