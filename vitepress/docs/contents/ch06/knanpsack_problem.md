# sec 01 背包问题

> 背包问题分为三类
> * 求最优解
> * 求方案数
> * 答案恢复
> 模型抽象为：物品体积是 $v$，价值是 $w$。背包限制了 $V$ 求背包内可以装的最大价值 $W$。

[[toc]]

## 求最优解
### 0-1 背包问题
* 状态定义：f[i][j] 表示 前 i(从 1 计数) 个物品中，取出总体积 $\le j$(有时候根据题意，也可以设置为 $=j$，公式不变) 的物品的最大价值
* 状态计算：$$f[i][j] = \max(f[i-1][j-v_i],~ f([i - 1][j - v_i]) + w_i)$$
* 初始状态：全是 0
* 时间复杂度：$O(nV)$


## 完全背包问题
* 状态定义：f[i][j]表示 前 i(从 1 计数) 个物品中，取出总体积 <= j 的物品的最大价值
* 状态计算：
$$f[i][j] = ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\max(f[i-1, j],~f[i-1, j-v_i] + w_i,~ f([i - 1, j - 2 \times v_i]) + 2 \times w_i, ...)$$
$$f[i, j + v] =  \max(f[i-1, j + v], f[i-1, j],~f[i-1, j-v_i] + 2\times w_i,~ f([i - 1, j - 2 \times v_i]) + 3 \times w_i, ...)$$
$$f[i, j + v] =  \max(f[i-1, j + v], f[i, j] + w_i)$$
$$f[i, j] =  \max(f[i-1, j], f[i, j - v] + w_i)$$
* 初始状态：全是 0
* 时间复杂度：$O(nV)$

### 完全背包问题
* 状态定义：f[i][j]表示 前 i(从 1 计数) 个物品中，取出总体积 <= j 的物品的最大价值
* 状态计算：
$f[i][j] = \max(f[i-1, j],~f[i-1, j-v_i] + w_i,~ f[i - 1, j - 2 \times v_i] + 2\times w_i, ...)$
$f[i, j - v] =~~~~~~~~~~~~~~\max(f[i-1, j - v_i],~~~~~~~~ f[i-1, j - 2\times v_i] + ~~~~~~~~w_i,...)$
$$f[i, j] =  \max(f[i - 1, j], f[i, j - v] + w_i)$$

### 多重背包问题
* 状态定义：f[i][j]表示 前 i(从 1 计数) 个物品中，取出总体积 <= j 的物品的最大价值
* 状态计算：
$f[i][j] = \max(f[i-1, j],~f[i-1, j-v_i] + w_i,~ f[i - 1, j - 2 \times v_i] + 2\times w_i, ..., f[i - 1, j - s_i\times v_i] + s_i\times w_i)$
* 时间复杂度： $O(nVs)$ n 代表物品种类数，s 代表每种数有几个

* 优化 1 二进制优化
$O(nVlog(s)))$

* 优化 2 单调队列优化



## 分组背包



## 求方案数
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

## 答案恢复
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