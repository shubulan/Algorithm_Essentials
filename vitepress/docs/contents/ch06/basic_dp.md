# 动态规划入门

## 递推问题

### 斐波那契

* [爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/)
```c++
class Solution {
public:
    // f[i] = f[i - 1] + f[i - 2];
    // f[0] = 1;
    int climbStairs(int n) {
        int f0 = 1, f1 = 1;
        for (int i = 2; i <= n; i++) {
            int t = f0 + f1;
            f0 = f1, f1 = t;
        }
        return f1;
    }
};
```
* [数楼梯](https://www.luogu.com.cn/problem/P1255)
    * [code:高精度](../luogu/Recursion/P1255.md)

* [蜜蜂路线](https://www.luogu.com.cn/problem/P2437)
    * [code](../luogu/Recursion/P2437.md)

### 数字三角形
* [过河卒](https://www.luogu.com.cn/problem/P1002)
    * [code](../luogu/dynamic_programming/P1002.md)

* [数的计算](https://www.luogu.com.cn/problem/P1028) 
    * [code](../luogu/Recursion/P1028.md) 简单线性记忆化递归和递推关系推导
