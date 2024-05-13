# sec 05 状压dp

状态压缩 DP 有两类，一类是几何表示，一类是集合表示。集合表示的比较多

## 集合表示
* 递推公式
[3116. 单面值组合的第 K 小金额](https://leetcode.cn/problems/kth-smallest-amount-with-single-denomination-combination/description/)
计算所有子集的 最小公倍数
```
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

* 装箱问题
[1986. 完成任务的最少工作时间段](https://leetcode.cn/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/)

dp[S][j] 表示 S 集合表示的任务，最少需要多少时间段
```
class Solution {
public:
    int minSessions(vector<int> &tasks, int sessionTime) {
        int n = tasks.size();
        int m = 1 << n;
        // 预处理所有子集的子集和，复杂度 O(1+2+4+...+2^(n-1)) = O(2^n)
        vector<int> sum(m);
        for (int i = 0; i < n; ++i) { // 预处理子集和
            for (int j = 0, k = 1 << i; j < k; ++j) {
                sum[j | k] = sum[j] + tasks[i];
            }
        }
        vector<int> f(m, n);
        f[0] = 0;
        for (int s = 0; s < m; ++s) {
            // 枚举 s 的所有子集 sub，若 sub 耗时不超过 sessionTime，则将 f[s^sub]+1 转移到 f[s] 上
            for (int sub = s; sub; sub = (sub - 1) & s) { // 枚举非空子集
                if (sum[sub] <= sessionTime) {
                    f[s] = min(f[s], f[s ^ sub] + 1);
                }
            }
        }
        return f[m - 1];
    }
};
```
* 图论
[最短 Hamiton 路径](acwing/acwing.91.cpp)

## 几何表示
* [蒙德里安的梦想](acwing/acwing.291.cpp)
