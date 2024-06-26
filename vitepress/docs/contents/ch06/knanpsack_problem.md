---
head:
  - - link
    - rel: stylesheet
      href: https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.5.1/katex.min.css
---
# 背包问题
[[toc]]

> 背包问题有很多种模型，但目标一般分为三类
> * 求最优解
> * 求方案数
> * 答案恢复


## 0-1 背包问题
> 有 $n$ 个物品，质量分别是 $w_i$，价值分别是 $v_i$。背包承重为 $W$，求背包可以装的最大价值 $Val$
> 针对 0-1 背包问题的数量级，可以有好几种做法，所以 0-1 背包问题是最经典的
### 基础版-指数型枚举
> 时间复杂度 $O(2^n)$，因此 $n \le 20$ 可以解
```c++
int rec(int i, int j) { // 从 i 开始选，背包承重还剩 j
    if (i == n) {
        return 0;
    } else if (j < w[i]) { // 不能选
        return rec(i + 1, j);
    } else { // 选不选都试试
        return max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
}
```
### 初级版-动态规划
* 状态定义：$f[i][j]$ 表示：$[0, i]$ 物品中，取出总质量 $\le j$的物品能够获得的最大价值
* 状态计算：$f[i][j] = \max(f[i-1][j],~ f([i - 1][j - w_i]) + v_i)$
* 初始状态：全是 0
* 时间复杂度：$O(nW)$

例题：
* [开心的金明](https://www.luogu.com.cn/problem/P1060)
    * [code](../luogu/dynamic_programming/P1060)

### 废铁版-超重物品
> 又重又不值钱，转换状态定义

* 状态定义：$f[i][j]$ 表示：$[0, i]$ 物品中，取出总价值为 $=j$ 的物品能够获得的最小重量
* 状态计算：$f[i][j] = \min(f[i-1][j],~ f([i - 1][j - v_i]) + v_i)$
* 初始状态：$f[0][0] = 0$ , 其他全是 $inf$
* 时间复杂度：$O(nV)$

### 金银版-又重又值钱
> 又重又值钱，就是个数不多
折半查找

### 其他变体
> 价值和体积一样
* [装箱问题](https://www.luogu.com.cn/problem/P1049)
    * [code](../luogu/dynamic_programming/P1049)
> 精确的获取某个价值 $v$
参考:废铁版状态定义$f[n][v] != inf$ 就是能获取
> 二维 0-1 背包
* [NASA的食物计划](https://www.luogu.com.cn/problem/P1507)
    * [code](../luogu/dynamic_programming/P1507)

### 应用
* [1262. 可被三整除的最大和](https://leetcode.cn/problems/greatest-sum-divisible-by-three/description/)
```c++
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> f1{0, -1 - 300000, -2 - 3000000};
        for (auto x : nums) {
            vector<int> f2(f1);
            for (int i = 0; i < 3; i++) {
                int idx = (f1[i] + x) % 3 + 3;
                f2[idx % 3] = max(f1[idx % 3], f1[i] + x);
            }
            f1 = std::move(f2);
        }
        return f1[0];
    }
};
```

## 完全背包问题
> 有 $n$ 种物品，每种物品都有无限多个。质量分别是 $w_i$，价值分为 $v_i$。背包承重为 $W$，求背包可以装的最大价值 $val$
* 状态定义：$f[i][j]$表示 $[0, i]$ 物品中，取出总体积 $\le j$ 的物品的最大价值
* 状态计算：
$f[i][j] = \max(f[i-1, j],~f[i-1, j-v_i] + w_i,~ f[i - 1, j - 2 \times v_i] + 2\times w_i, ...)$
$f[i, j - v_i] =~~~~~~~~~~~~~~\max(f[i-1, j - v_i],~~~~~~~~ f[i-1, j - 2\times v_i] + ~~~~~~~~w_i,...)$
$$f[i, j] =  \max(f[i - 1, j], f[i, j - v] + w_i)$$
* 初始状态：全是 0
* 时间复杂度：$O(nV)$


## 多重背包问题
* 状态定义：f[i][j]表示 前 i(从 1 计数) 个物品中，取出总体积 <= j 的物品的最大价值
* 状态计算：
$f[i][j] = \max(f[i-1, j],~f[i-1, j-v_i] + w_i,~ f[i - 1, j - 2 \times v_i] + 2\times w_i, ..., f[i - 1, j - s_i\times v_i] + s_i\times w_i)$
* 时间复杂度： $O(nVs)$ n 代表物品种类数，s 代表每种数有几个
### 初级版
> $n \le 100, w \le 100, s \le 100$

### 加大数量1
> $n \le 1000, w \le 2000, s \le 2000$


### 加大数量2
> $n \le 1000, w \le 20000, s \le 20000$

* 优化 1 二进制优化
$O(nVlog(s)))$

* 优化 2 单调队列优化



## 分组背包
* [分组背包问题](https://www.acwing.com/problem/content/9/)
    * [code](../acwing/acwing.9.md)
* [通天之分组背包](https://www.luogu.com.cn/problem/P1757)
    * [code](../luogu/dynamic_programming/P1757)

## 混合背包

## 二维费用背包

## 有依赖的背包

## 求方案数
### 0-1 背包求方案数
* [小A点菜](https://www.luogu.com.cn/problem/P1164)
    * [code](../luogu/Recursion/P1164.md) 背包计数问题
### 多重背包问题求方案数
* [2585. 获得分数的方法数](https://leetcode.cn/problems/number-of-ways-to-earn-points/description/)
要点：
* f[i][j] 表示只使用前i种题目，凑出总分值 j 有多少种方案
* 这里的递推公式：$$f[i][j] = \sum_{k=0}f[i-1][j-k * mark_i]$$
* 复杂度：$< O(n * T * count)$
* 无法用二进制优化，二进制优化只适合做 最大值，最小值问题。因为二进制优化实际上把第 i 种物品，拆成了 1， 2，4 ... 多种物品来看待。而这里求方案，只能把他看成一种：要么是 1 个，要么是 2 个 要么是 3 个。
* 还可以用滑动窗口优化

```
class Solution {
public:
    const int mod = 1e9+7;
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<int> f(target + 1);
        int n = types.size();
        f[0] = 1;
        for (auto& tp: types) {
            int cnt = tp[0], mark = tp[1];
            for (int j = target; j > 0; j--) {
                for (int k = 1; k <= min(cnt, j / mark); ++k)
                    f[j] = (f[j] + f[j - k * mark]) % mod;
            }
        }
        return f[target];
    }
};

```

### 二维0-1背包问题求方案数
* [3082. 求出所有子序列的能量和](https://leetcode.cn/problems/find-the-sum-of-the-power-of-all-subsequences/description/)
* f[i][j] 表示满足：集合大小为 i ，集合内数字之和为 j 的集合个数
```
class Solution {
public:
    typedef long long LL;
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        int mod = 1e9 + 7;
        LL res = 0;
        vector<vector<LL>> f(n + 1, vector<LL>(k + 1));
        vector<LL> te(n + 1, 1);
        for (int i = 1; i <= n; i++) te[i] = te[i - 1] * 2 % mod;
        f[0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = n; j >= 1; j--)
                for (int p = k; p >= nums[i]; p--)
                    f[j][p] = (f[j][p] + f[j - 1][p - nums[i]]) % mod;
        for (int i = 0; i <= n; i++) res = (res + te[n - i] * f[i][k]) % mod;
        return res;
    }
};
```
### 完全背包问题求方案数
* [ A+B Problem（再升级）](https://www.luogu.com.cn/problem/P1832)
    * [code](../luogu/dynamic_programming/P1832.md)

## 求具体方案：答案恢复
### 0-1 背包答案恢复
[1449. 数位成本和为目标值的最大数字](https://leetcode.cn/problems/form-largest-integer-with-digits-that-add-up-to-target/description/)
* 求和为 target 的最大集合数量。
* 尽可能大的恢复出答案
```
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int n = target;
        string res;
        vector<int> f(n + 1, -0x3f3f3f3f);
        f[0] = 0;
        for (int i = 0; i < 9; i++) {
            int u = cost[i];
            for (int j = u; j <= n; j++) {
                f[j] = max(f[j], f[j - u] + 1);
            }
        }
        if (f[n] < 0) return "0";

        for (int i = 9, j = n; i >= 1; i--) {
            int u = cost[i - 1];
            while (j >= u && f[j - u] + 1 == f[j]) {
                res += '0' + i;
                j -= u;
            }
        }
        return res;
        
        cout << f[target] << endl;
        return res;
    }
};
```

## 总结
想要快速理清背包问题的思路需要
1. 深刻理解每种背包的场景和解题思路
2. 记忆枚举顺序有助于快速敲出代码
3. 多思考初值或者边界条件