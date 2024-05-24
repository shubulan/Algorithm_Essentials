# 构造题
构造类题目的特点是：题目通常要求返回符合题目的一个结构，而不是一个值。我们要根据题意来把这个结构生成出来。

构造题目有点像模拟，但是往往更抽象，用的数据结构或者技巧更巧妙。

## 顺序相关
* [31. 下一个排列](https://leetcode.cn/problems/next-permutation/description/)

* [1673. 找出最具竞争力的子序列](https://leetcode.cn/problems/find-the-most-competitive-subsequence/description/)
  * 字典序与栈
::: code-group
```c++ [栈]
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int t = n - i;
            while (res.size() &&  res.size() + n > k + i && res.back() > nums[i]) res.pop_back();
            if (res.size() < k) res.push_back(nums[i]);
        }
        return res;
    }
};
```

```c++ [树状数组/线段树]

```
:::