::: code-group
```c++ [动态规划]
class Solution {
public:
    int ans = INT_MIN, now = 0;
    int maxSubArray(vector<int>& nums) {
        /**动态规划sum表示以该数结尾的最大连续和,我们要找到其中最大的*/
        for(int i = 0; i<nums.size();i++){
            now = max(now + nums[i], nums[i]);
            ans = max(ans, now);
        }

        return ans;
    }
};
```
```c++ [分治]
class Solution {
public:
    array<int, 4> merge(vector<int>& a, int l, int r) {
        if (l == r) {
            return {a[l], a[l], a[r], a[l]};
        }
        int mid = (l + r) / 2;
        auto ansl = merge(a, l, mid);
        auto ansr = merge(a, mid + 1, r);
        array<int, 4> ans;
        ans[0] = max({ansl[0], ansr[0], ansl[2] + ansr[1]});
        ans[1] = max(ansl[1], ansl[3] + ansr[1]);
        ans[2] = max(ansr[2], ansr[3] + ansl[2]);
        ans[3] = ansl[3] + ansr[3];
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1)[0];
    }
};

```

:::