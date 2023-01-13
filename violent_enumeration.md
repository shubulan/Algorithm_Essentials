
# 暴力枚举
枚举也是需要技巧的
[洛谷题单](https://www.luogu.com.cn/training/108#problems)
## 常规枚举
[矩形枚举](brute-enumeration\P2241.cpp)

## 指数型枚举

模板题
* [P2809](brute-enumeration\P2089.cpp)

## 全排列
  全排列有两种方式实现，一种是dfs，一种是用c++标准库next_permutation.
  获取全排列的复杂度就有n!如果用next_permutation，需要再乘以n。
  10!就已经到300w的量级了。所以数据量不会大一般就1~10.

模板题
* [P1706](brute-enumeration\P1706.cpp)


## 组合枚举
组合不同于全排列，是无序的。
dfs实现与全排列的实现有所不同。
也可以使用next_permutation来实现。这个思想就很接近二进制枚举了，而且速度不慢

模板题
* [P1157](brute-enumeration\P1157.cpp)
* [P1036](brute-enumeration\P1036.cpp)

## 转换维度的枚举
* [P3799](brute-enumeration\P3799.cpp)

## 二进制枚举