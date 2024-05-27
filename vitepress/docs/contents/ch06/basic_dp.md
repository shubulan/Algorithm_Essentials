# 动态规划入门
* [灵神动态规划题单](https://leetcode.cn/circle/discuss/tXLS3i/)

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

### 爬楼梯
> 考虑最后一级台阶是从谁爬上来的
* [组合总和 Ⅳ](https://leetcode.cn/problems/combination-sum-iv/)
```c++
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto x :nums) {
                if (i >= x) f[i] += f[i - x];
            }
        }
        return f[target];
    }
};
```
* [2466. 统计构造好字符串的方案数](https://leetcode.cn/problems/count-ways-to-build-good-strings/)
```c++
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto x :nums) {
                if (i >= x) f[i] += f[i - x];
            }
        }
        return f[target];
    }
};
```
* [2266. 统计打字方案数](https://leetcode.cn/problems/count-number-of-texts/description/)
```

```