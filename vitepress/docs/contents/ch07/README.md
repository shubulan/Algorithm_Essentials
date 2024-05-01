# ch06 贪心算法

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
```
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

