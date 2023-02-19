# GYL_刷题笔记

> 知识点分类来自[洛谷官方题单](https://www.luogu.com.cn/training/list)
## 入门
  > 学习新语言时可以用来练习语法
  > 练习语法时，基础算法部分也可用
1. 顺序结构
2. 分支结构
3. 循环结构
4. 数组
5. 字符串
6. 函数与结构体
## 基础算法
1. [模拟与高精度](simulation_and_high_precision.md)
2. [排序](sort.md)
3. [暴力枚举](violent_enumeration.md)
4. [递推与递归](recursion.md)
5. [贪心](greedy.md)
6. [二分查找与二分答案](binary_search.md)
7. [搜索](search.md)
## 数据结构 一
1. [线性表](linear_table.md)
2. [二叉树](bin_tree.md)
3. [集合](set_theroy.md)
4. [图的基本应用](graphy_theroy_1.md)
5. 补充
   1. [字符串相关算法](string.md)

## 数学 一
1. [基础数学问题](basic_math.md)

## 中级算法
1. [前缀和与差分](preSumAndDiff.md)
2. [线性复杂度优化、离散化](linearAndDiscret.md)
3. [分治]
4. [倍增](times_inc.md)
5. [搜索的剪枝策略](search2.md)

## 数据结构 二
1. [二叉堆与st表](st_table.md)
2. [线段树与树状数组](line_tree.md)
3. 

## 图论
1. [基础树上问题]
2. [最短路问题](shortest_path.md)
3. [最小生成树](smallest_span_tree.md)
4. [连通性问题]
5. [二分图](bin_graph.md)



## 动态规划
> 动态规划极其难想。给一个全新的动态规划问题，一般人很难想出来。
> 所以还是尽快接触各种经典动态规划问题，多思考、证明、记忆才是王道。
1. [动态规划引入](dynamic_program_1.md)
2. [线性]
3. [区间与环形]
4. [树上与图上]
5. [状态压缩](./state_compression.md)
6. 补充
   1. [计数类]
   2. [数位统计]

## 数学 二
1. [整数与除数](integer_division.md)
2. [组合数学与计数](number_of_combination.md)
3. [概率与统计]()
4. [补充](other_math.md)

## 个人补充
> 综合应用: 主要是一些思维题，用到上面较多的知识点综合，
>  来源于：洛谷、leetcode、acwing

### 前缀和、单调性、二分 
[1124. 表现良好的最长时间段](https://leetcode.cn/problems/longest-well-performing-interval)

### 字符串哈希、二分
[acwing 1460. 我在哪？](blue_bridge/3_bi_search/acwing1460.cpp)

### 排序 + 二分
> 给到一个数组，数组内容的顺序不重要时考虑
>
* [2563. 统计公平数对的数目](https://leetcode.cn/problems/count-the-number-of-fair-pairs/)


### 位运算 哈希表
[2564. 子字符串异或查询](https://leetcode.cn/problems/substring-xor-queries/)

### 前后缀分解 + 双指针
> 对于子序列匹配问题，枚举大序列，比枚举小序列要容易一些
[2565. 最少得分子序列](https://leetcode.cn/problems/subsequence-with-the-minimum-score/description/)

### 二维前缀和 二维预处理
> 常见的二维预处理技巧
[1139. 最大的以 1 为边界的正方形](https://leetcode.cn/problems/largest-1-bordered-square/description/)

### 记忆化搜索 双指针 位运算
[6365. 将整数减少到零需要的最少操作数](https://leetcode.cn/problems/minimum-operations-to-reduce-an-integer-to-0/)

### 构造 + 思维题
[6363. 找出对应 LCP 矩阵的字符串](https://leetcode.cn/problems/find-the-string-with-lcp/description/)