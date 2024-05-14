# 双指针

> 双指针算法是最常考的一类算法和思考方式，通常用在数组中，枚举子区间
> 双指针蕴含着贪心的思想：有两个指针 ij，分别指向数组的两个位置枚举指针 i，然后另一个指针 j 调整到合适的位置。

[[TOC]]

## 贪心思想
贪心的思想在于，i 移动过后，j 的合适位置不可能在 j 已经扫描过的地方，也就是说 j 是单调的。


## 连续分割区间段
要点：
* 枚举左端点 i，将右端点 j 移动到极限，形成区间[i, j)
* 更新答案，更新 i = j,继续遍历下一个区间
* [AcWing 803. 区间合并](https://www.acwing.com/problem/content/805/)
* 合并相交的区间
```
  for (int i = 0, j = 0; i < n; i++, i = j) { // 更新左端点为 j
    int r = arr[i].second;
    while (j < n && arr[j].first <= r) { // j 向右移动到极限
        r = max(r, arr[j].second);
        j++;
    }
    cnt++; // 更新答案
  }
```

## 滑动窗口
要点：
* **先以枚举右端点思考，因为左端点有遍历过的信息**
* 根据实现难易度选择遍历左端点还是右端点
* 以枚举右端点为思考：
    * 直接将右端点加入窗口
    * 移动左端点到窗口刚好符合要求，形成区间$[i, j]$
    * **问题在于移除左端点后，能否简单的判断区间是否符合要求**
* [799. 最长连续不重复子序列](799. 最长连续不重复子序列)

```
  unordered_map<int, int> mp;
  for (int i = 0, j = 0; j < n; j++) {
    mp[arr[j]]++;
    while (i < j && mp[arr[j]] > 1) // 保证新加入的值的个数 <= 1 即可
        mp[arr[i++]]--;
    res = max(res, j - i + 1);
  }
```
> 另一种思考方式:枚举左端点思考
> * 将右端点移动到刚好不符合的窗口，[i, j) 即为区间
> * 更新答案
> * 将左端点移除窗口
> **问题在于，移动右端点时，需要先试验能不能加入窗口。**
>   * 而能不能加入窗口，可能需要先加入才能判断
>   * 如果真的不能加入窗口，还得把它移出去
>   * 如果不加入窗口，就能判断是否能加入窗口，枚举左端点也行
```
  unordered_map<int, int> mp;
  for (int i = 0, j = 0; i < n; i++) { 
    while (j < n && mp[arr[j]] == 0) // 能加入窗口就加入
        mp[arr[j++]]++;
    res = max(res, j - i);
    mp[arr[i]]--;
  }
```

## 枚举右端点
以枚举右端点思考的原因是，左端点的移动可以利用右端点扫过的信息。对以下算法的思考与实现都有帮助
* 单调队列
* 单调栈
* 线性 DP

再附一个 0x3f 的[滑动窗口题目单](https://leetcode.cn/circle/discuss/0viNMK/)

## 对向双指针
要点：
* 两个指针从数组的两头向中间移动

代表算法：
* 回文串的判定
* [两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150)
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0, j = n - 1; i < n; i++) {
            if (numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            }
            while (i < j && numbers[i] + numbers[j] > target) {
                if (i < --j && numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1};
                }
            }
        }
        return {0, 0};
    }
};
```
* [盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/description)
```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = -0x3f3f3f3f;
        int n = height.size();
        for (int i = 0, j = n - 1; i < j; i++) {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            while (i < j && height[j] < height[i]) {
                j--;
                ans = max(ans, (j - i) * min(height[i], height[j]));
            }
        }
        return ans;
    }
};
```
* [进阶：三数之和](https://leetcode.cn/problems/3sum/description)

::: code-group
```c++ [哈希表]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> h;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (auto c:nums) h[c]++;
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            h[nums[i]]--;
            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                h[nums[j]]--;
                int x = -(nums[i] + nums[j]);
                if (x >= nums[j] && h[x] > 0) {
                    ans.push_back({nums[i], nums[j], x});
                }
                h[nums[j]]++;
            }
            h[nums[i]]++;
        }
        return ans;
    }
};
```

```c++ [两数之和]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            for (int j = i + 1, k = n - 1; j < k; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                // cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                int s = nums[j] + nums[k];
                if (s == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
                if (s < target) continue;
                while (j < k && nums[k] + nums[j] > target) {
                    k--;
                    if (j == k) break;
                    int s = nums[j] + nums[k];
                    if (s == target) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return ans;
    }
};
```
:::

## 双数组
* [在LR字符串中交换相邻字符](https://leetcode.cn/problems/swap-adjacent-in-lr-string/solutions/1/by-ac_oier-ye71/)
  * [code](./code/leetcode_777.md)