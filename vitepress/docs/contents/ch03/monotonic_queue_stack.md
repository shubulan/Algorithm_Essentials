# sec 02 单调队列与单调栈

## 单调栈与单调队列
> 单调栈与单调队列是非常好的一种双指针优化，通常将 $O(n^2)$ 复杂度降低到 $O(n)$


### 单调栈
> 单调栈有两种思路，都要熟悉
实现要点：
* 只要满足思路，就可以使用单调栈
* 具体实现要依情况而定，可能存索引，可能存数字，还可能存pair
* 思路1：枚举 i ，求 i 左边最近的比我大的数，下面的题目作为模板
* [84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/description/)
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size(), ans = 0;
        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            while (st.size() && heights[st.top()] >= heights[i]) st.pop();
            int b = -1;
            if (st.size()) b = st.top();
            left[i] = b;
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && heights[st.top()] >= heights[i]) st.pop();
            int e = n;
            if (st.size()) e = st.top();
            ans = max(ans, (e - left[i] - 1) * heights[i]);
            st.push(i);
        }

        return ans;
    }
};
```


* 思路2：枚举 i，如果 i 左边的连续一些数永远不会与右边的数进行配对，那么可以将这些数去掉。剩下的数刚好是单调的。
* 下面的题目作为模板
* [3113. 边界元素是最大值的子数组数目](https://leetcode.cn/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/)
```
class Solution {
public:
    unordered_map<int, vector<int>> mmap;
    long long numberOfSubarrays(vector<int>& nums) {
        using PII = pair<int, int>;
        stack<PII> st;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (st.size() && st.top().first < nums[i]) {
                st.pop();
            }
            if (st.size() && st.top().first == nums[i]) {
                st.top().second++;
            } else {
                st.push({nums[i], 1});
            }
            res += st.top().second;
            
        }
        return res;
    }

};
```


### 单调队列
> 单调队列一般用于求固定右端点的区间最大值，基本是一个滑动窗口的题目
* 枚举右端点 j ，
* 视情况将 j 加入队列，将左端点 i 移出队列。
* 两个动作顺序可反，需要看情况
* 视情况更新答案
> 题目遇到再补充