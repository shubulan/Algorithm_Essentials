# ch05 数学 I

> 常用的数学技巧
## 进制
* [双进制回文数](https://pe-cn.github.io/36/)
   * 前导零问题
   * [code](../luogu/math/basic/33.euler.md)

* [P1143 进制转换](https://www.luogu.com.cn/problem/P1143)
    * 2 到 16进制相互转换
    * [code](../luogu/math/P1143.md)

* [P1017 [NOIP2000 提高组] 进制转换](https://www.luogu.com.cn/problem/P1469)
    * 负进制转换
    * [code](../luogu/math/P1017.md)

## 乘法原理
* [安全系统](https://www.luogu.com.cn/problem/P2638)
  * 前缀和、大整数
  * [code](../luogu/P2638.md)

## 位运算
* [P1100 高低位交换](https://www.luogu.com.cn/problem/P1100)
    * [code](../luogu/math/P1100.md)
* [P1469 找筷子](https://www.luogu.com.cn/problem/P1469)
    * [code](../luogu/math/P1469.md)

## 计数问题
> 往往排序后更好解决
* [P1866 编号](https://www.luogu.com.cn/problem/P1866)
    * [code](../luogu/math/P1866.md)

* [P3913 车的攻击](https://www.luogu.com.cn/problem/P3913)
    * [code](../luogu/math/P3913.md)

## 质数
> 素数判定

> 分解质因数

> 筛质数
* [P3383 【模板】线性筛素数](https://www.luogu.com.cn/problem/P3383)
    * [code](../luogu/math/P3383.md)

## 筛法
* [P1621 集合](https://www.luogu.com.cn/problem/P1621)
    * [code](../luogu/set/P1621.md)

## 约数
> 求约数
```c++
// 求约数模板
vector<int> get_divisors(intn) {
    vector<int> res;
    for (int i = 1; i <= n / i; i++) {
        if (n % i) continue;
        res.push_back(i);
        if (i != n / i) res.push_back(n / i);
    }
    return res;
}
```
* [消去数字的分数](https://pe-cn.github.io/33/)
   * [code](../luogu/math/basic/36.euler.md)
* [P1403 \[AHOI2005\]约数研究](https://www.luogu.com.cn/problem/P3383)
    * [code](../luogu/math/P1403.md)
* [优质数对的总数 II](https://leetcode.cn/problems/find-the-number-of-good-pairs-ii/description/)
    * [code](./code/leetcode100321.md)
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
* [P2660 zzc 种田](https://www.luogu.com.cn/problem/P2660)
    * [code](../luogu/math/P2660.md)

* [P1572 计算分数](https://www.luogu.com.cn/problem/P1572)
    * [code](../luogu/math/P1572.md)

> 最小公倍数
* [P1029 \[NOIP2001 普及组\] 最大公约数和最小公倍数问题](https://www.luogu.com.cn/problem/P1029)
    * [code](../luogu/math/P1029.md)

* [P4057 \[Code+#1\]晨跑](https://www.luogu.com.cn/problem/P4057)
    * [code](../luogu/math/P4057.md)

* [P2651 添加括号III](https://www.luogu.com.cn/problem/P2651)
    * [code](../luogu/math/P2651.md)

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
> [组合数I]
    * [code](../acwing/acwing.885.md)
* 打表，杨辉三角递推
```c++
//可以打表
// f[i][j] == C(j, i)，表示i个里面挑j个
int f[2000][2000];
//利用公式打标，只能计算2000x2000的数，多了不行。
for (int i = 0; i <= n; i++) {
  for (int j = 0; j <= i; j++) {
    if (!j) a[i][j] = 1;
    else a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % mod;
  }
}
```

> [组合数II](https://www.acwing.com/problem/content/888/)
* 数量级变大，通过逆元来求 C(m, n) = n ! / (m! * (n-m)!)
* 求逆元用快速幂
[code](../acwing/acwing.886.md)

> 组合数III
> 当 mod 会变化时，没有固定的逆元了，因此用卢卡斯定理
* [code](../acwing/acwing.887.md)

> 组合数IV
> 不取模了，要具体值。使用大整数算法。
* [code](../acwing/acwing.888.md)
* [P3807 【模板】卢卡斯定理/Lucas 定理](https://www.luogu.com.cn/problem/P3807)
    *[code](../luogu/math/P3807.md)

## 卡特兰数
* [栈](https://www.luogu.com.cn/problem/P1044)
    * [code](../luogu/Recursion/P1044.md)

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
