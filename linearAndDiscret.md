# 线性复杂度优化/离散化

## 双指针
> 运用某些单调性质，将O(n2)算法优化到O(n)，有两类
> 
> 一、两个指针指向两个序列
> 实现模板
> ```
> for (int i = 0, j = 0; i < n; i++) {
>    while (check(j) && check(i, j)) j++;
> 
> }
> ```

2. [P1147 连续自然数和](linear/P1147.cpp)

3. [P3143 [USACO16OPEN] Diamond Collector S](linear/P3143.cpp) 贪心陷阱

> 二、两个指针指向同一个序列
> * 特殊情况：尺取法

## 单调队列
1. [P2032 扫描](linear/P2032.cpp)
2. [P1440 求m区间内的最小值](linear/P1440.cpp)
3. [P1886 滑动窗口 /【模板】单调队列](linear/P1886.cpp)
