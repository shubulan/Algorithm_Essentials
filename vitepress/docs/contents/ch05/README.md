# ch05 数学 I

> 常用的数学技巧

## 质数
> 素数判定

> 分解质因数

> 筛质数

## 约数
> 求约束

> 约数个数

> 约数之和

> 最大公约数
* gcd 函数
```c++
int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

int gcd(vector<int>& nums) {
    int r = 0;
    for (auto x : nums) r = gcd(r, x);
    return r;
}

```
> 最小公倍数

## 拓展欧几里得:裴蜀定理

* [检查「好数组」](https://leetcode.cn/problems/check-if-it-is-a-good-array/description/)
```c++
class Solution {
 public:
  bool isGoodArray(vector<int>& nums) {
    for (int i = 0, a = 0; i < nums.size(); i++) {
      a = gcd(a, nums[i]);
      if (a == 1) return true;
    }
    return false;
  }
};
```
## 欧拉函数
> phi(n) = [1, n]中，与n互素的数的个数。
> 作为对比：约数数量是 [1, n]中，可以整除 n 的数的个数。

## 快速幂
> 模板

## 逆元
> 费马小定理

> 拓展欧几里得

## 中国剩余定理
> 同余方程组的公式解


## 组合数
> 组合数I

> [组合数II](https://www.acwing.com/problem/content/888/)
数量级变大
[code](../acwing/acwing.886.md)

> 组合数III

> 组合数IV

## 容斥原理
> 容斥原理在求所有集合的并的大小的时候，比较有用，常用数论中的计数问题
> 和 最小公倍数、质数等关系较大
\[
\left| \bigcup_{i=1}^{n} A_i \right| = \sum_{i=1}^{n} \left| A_i \right| - \sum_{1 \leq i < j \leq n} \left| A_i \cap A_j \right| + \sum_{1 \leq i < j < k \leq n} \left| A_i \cap A_j \cap A_k \right| - \ldots + (-1)^{n+1} \left| A_1 \cap A_2 \cap \ldots \cap A_n \right|
\]
* [3116. 单面值组合的第 K 小金额](https://leetcode.cn/problems/kth-smallest-amount-with-single-denomination-combination/description/)
* 求 最小公倍数的技巧
* 状压 dp 预处理集合的最小公倍数技巧
* 计算二级制位 1 的个数 `__builtin_popcount(x)`
* 二分答案
```c++
class Solution {
public:
    using LL = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        LL l = 0, r = (LL)ranges::min(coins) * k;
        int n = coins.size();
        vector<LL> lcms(1 << n);
        lcms[0] = 1;
        for (int i = 0; i < n; i++) { // 状压 dp 求所有集合的 lcm
            int bit = 1 << i;
            for (int mask = 0; mask < (1 << i); mask++) {
                lcms[mask | bit] = lcm(lcms[mask], coins[i]);
            }
        }
        while (l < r) {
            LL mid = (l + r) / 2;
            LL cnt = 0;
            for (int i = 1; i < (1 << n); i++) {
                cnt += __builtin_popcount(i) % 2 ? mid / lcms[i] : -mid / lcms[i];
            }

            if (cnt >= k) r = mid;
            else l = mid + 1;
        }

        return r;
    }
};
```


## 博弈论

### 公平组合游戏-Nim游戏
> 谁在最后无法操作了，谁输
* [NIM游戏](https://www.acwing.com/problem/content/893/)
    * [code](../acwing/acwing.891.md)

### 其他博弈
> 谁在最后得的分值高，谁输

> 所以这类问题需要优化选择顺序，使各自的分值最高

解决思路有以下几种：
* 决策树深搜
    * 每一个节点，枚举自己可能的选择，然后让 A 的分值最大
    * 该 B 选择时，同理需要让 B 的分值最大
    * 例题: [1690. 石子游戏 VII](https://leetcode.cn/problems/stone-game-vii/description/)
```c++
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int i = 0, j = stones.size() - 1, n = stones.size();
        vector<int> psum(n + 1);
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) psum[i + 1] = psum[i] + stones[i];

        function<int(int, int)> dfs = [&](int i, int j) {
            if (i == j) {
                return 0;
            }
            if (dp[i][j]) return dp[i][j];

            int l = -dfs(i + 1, j) + psum[j + 1] - psum[i + 1];
            int r = -dfs(i, j - 1) + psum[j] - psum[i];

            return dp[i][j] = max(l, r);
        };
        return dfs(i, j);
    }

};
```
* 贪心
    * A B 双方均按照一定的顺序选择，就是最优
    * 例题：[1686. 石子游戏 VI](https://leetcode.cn/problems/stone-game-vi/description/)
```c++
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = aliceValues[i] + bobValues[i];
        }
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return c[a] > c[b];
        });

        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) diff -= bobValues[idx[i]];
            else diff += aliceValues[idx[i]];
        }

        return (diff > 0) - (diff < 0); // -, 0, + 映射成 -1， 0， 1
    }
};
```
