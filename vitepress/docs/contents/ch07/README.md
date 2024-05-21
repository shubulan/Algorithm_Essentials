# ch06 贪心算法

## 


* [1775. 通过最少操作次数使数组的和相等](https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/)
```c++
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 = 0, s2 = 0;
        for (auto x : nums1) s1 += x;
        for (auto y : nums2) s2 += y;
        if (s1 == s2) return 0;
        if (s1 > s2) std::swap(nums1, nums2);
        int diff = abs(s2 - s1);
        vector<int> vec;
        int res = 0;
        for (auto &x : nums1) if (6 - x > 0) vec.push_back(6 - x);
        for (auto &x : nums2) if (x - 1 > 0) vec.push_back(x - 1);
        sort(vec.begin(), vec.end());
        int n = vec.size();
        int i = 0;
        for (i = n - 1; i >= 0 && diff > 0; i--) {
            diff -= vec[i];
        }

        if (diff > 0) return -1;
        return n - i - 1;
    }
};

```

## 区间问题
* 活动选择问题：算法导论

## huffman 树

## 排序不等式

## 田忌赛马
* [leetcode 870. 优势洗牌](https://leetcode.cn/problems/advantage-shuffle/)
::: code-group
```c++ [multiset]
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ret(n);
        multiset<int> h;
        for (int i = 0; i < n; ++i) h.insert(nums1[i]);
        for (int i = 0; i < n; ++i) {
            auto it = h.upper_bound(nums2[i]);
            if (it == h.end()) it = h.begin();
            ret[i] = *it;
            h.erase(it);
        }
        return ret;
    }
};
```
```c++ [排序构造]
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idxs1(n), idxs2(n);
        iota(idxs1.begin(), idxs1.end(), 0);
        iota(idxs2.begin(), idxs2.end(), 0);
        sort(idxs1.begin(), idxs1.end(), [&](int a, int b) {
            return nums1[a] < nums1[b];
        });
        sort(idxs2.begin(), idxs2.end(), [&](int a, int b) {
            return nums2[a] < nums2[b];
        });
        vector<int> res(n, -1), vs(n);
        for (int i = 0, j = 0; i < n; i++, j++) {
            while (j < n && nums1[idxs1[j]] <= nums2[idxs2[i]]) j++;
            if (j == n) continue;
            res[idxs2[i]] = nums1[idxs1[j]];
            vs[idxs1[j]] = true;
        }
        for (int i = 0, j = 0; i < n; i++) {
            if (res[i] != -1) continue;
            while (j < n && vs[j]) j++;
            res[i] = nums1[j++];
        }
        return res;
    }
};

```
:::

## 绝对值不等式

## 推公式

## 脑筋急转弯
* [2567. 修改两个元素的最小分数(https://leetcode.cn/problems/minimum-score-by-changing-two-elements/solutions/)
```c++
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({nums[n - 1] - nums[2], nums[n - 3] - nums[0],
                    nums[n - 2] - nums[1]});
    }
};
```

## 思考每一个极值
* [完成所有交易的初始最少钱数](https://leetcode.cn/problems/minimum-money-required-before-transactions/description/)
```c++
class Solution {
public:
    using LL = long long;
    long long minimumMoney(vector<vector<int>>& transactions) {
        LL totCost = 0;
        for (auto & vec: transactions) {
            int a = vec[0], b = vec[1];
            if (a > b) {
                totCost += a - b;
            }
        }
        LL res = 0;
        for (auto & vec: transactions) {
            int a = vec[0], b = vec[1];
            if (a > b) {
                res = max(res, totCost - (a - b) + a);
            } else {
                res = max(res, totCost + a);
            }
        }

        return res;
    }
};
```
* [AcWing 1996. 打乱字母](https://www.acwing.com/problem/content/1998/)
    * 贪心+二分

## 思考最终状态
    * [你可以工作的最大周数](https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/description/)
```c++
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long s = 0, mx = -1;
        for (long long c : milestones) {
            s += c;
            mx = max(mx, c);
        }
        return mx <= (s - mx + 1) ? s : 2 * (s - mx) + 1;
    }
};
```

## 中位数贪心
> 这个最好列一下公式，然后分析一下公式
要点：
* 列一下公式
* 分析一下公式，画图像等
[2448. 使数组相等的最小开销](https://leetcode.cn/problems/minimum-cost-to-make-array-equal/description/)
> 将数组排序，得到当选择 x 作为目标值时，cost 是

$cost_x = (x - num_0) + (x - num_1) ... (x - num_k) + (num_{k+1} - x) + (num_{n} - x)$
显然是一个线性函数，因此极大值在顶点处。
* 将cost[i] 看作数量，就是经典的中位数贪心。当 pre_cost >= (sum_cost + 1) / 2 时，即代表找到了中位数.
* 由于 sum_cost 可能是奇数，所以要 +1.
* 中位数不需要太准确，因为毕竟把 有 cost[i] 个 nums[i]. 只要大于 一半了 nums[i] 就是中位数。
```c++
class Solution {
public:
    using LL = long long;
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        LL tot_cost = 0, cur_cost = 0, ans = 0;
        for (auto x : cost) tot_cost += x;
        for (int i = 0; i < n; i++) {
            cur_cost += cost[ids[i]];
            if (cur_cost >= (tot_cost + 1) / 2) {
                LL x = nums[ids[i]];
                for (int j = 0; j < n; j++) ans += abs(nums[j] - x) * (LL)cost[j];
                break;
            }
        }
        
        return ans;
    }
};
```

