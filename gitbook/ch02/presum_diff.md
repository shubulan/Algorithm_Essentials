# sec 01 前缀和与差分
[toc]

> 前缀和与差分是一类非常简单，又常考、有用的算法

## 一维前缀和
要点：
* 快速求一段区间的和
* 一般需要数组从 1 开始，因为要计算 [0, k] 区间，需要 pre_sum[k] - pre_sum[-1]，无法统一处理
* leetcode 不会给你空一位 0 出来，所以要自己映射好索引
* [2602. 使数组元素全部相等的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/) 二分 + 前缀和
```
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> psum(n + 1);
        for (int i = 1; i <= n; i++) psum[i] = psum[i - 1] + nums[i - 1]; // 构建前缀和数组
        vector<long long > res;
        for (long long c: queries) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (nums[mid] >= c) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (nums[l] < c) l++; // 特判二分边界

            // [0, l) 的和
            //   计算： l - 1 为 要求的区间上界， + 1 映射到前缀和数组，结果为 psum[l]
            //
            // [l, n) 的和
            //   计算： n - 1 为 要求的区间上界， + 1 映射到前缀和数组，结果为 psum[n]
            //         l 为下界，所以 l - 1， + 1 映射到前缀和数组，结果为 psum[l]
            //
            res.push_back(c * l - (psum[l] - psum[0]) + (psum[n] - psum[l]) - c * (n - l));
        }
        return res;
    }
};
```

## 一维差分
要点：
* 用于将一个区间的数全加一个定值 c
* 需要与前缀和结合起来，但不需要在前面留 0 
* 需要在后面留一个位置
* [2381. 字母移位 II](https://leetcode.cn/problems/shifting-letters-ii/description/)

```
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> t(n + 1);
        for (auto &p:shifts) {
            int a = p[0], b = p[1], d = p[2];
            if (d == 0) d = -1;
            t[a] += d; // 左区间 + d
            t[b + 1] -= d; // 右区间 -d
        }

        for (int i = 1; i <= n; i++) {
            t[i] += t[i - 1]; // 前缀和恢复原数组
            t[i - 1] = t[i - 1] % 26 + 26; // 防止负数
            char c = (s[i - 1] - 'a' + t[i - 1]) % 26 + 'a';
            s[i - 1] = c;
        }
        return s;

    }
};

```

## 二维前缀和
要点：
* 二维前缀和有一点容斥原理
* 二维前缀和也需要留出第一行和第一列来，因为计算需要上一行
* 实现比较简单，就搁置吧



## 二维差分
要点：
* 比较难想，需要背公式
* 仍然需要空出第一行和第一列来
* leetcode 有时候会帮你空出第一行和第一列
* [2250. 统计包含每个点的矩形数目]() 本题结合了离散化和二维差分

```
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> nums;
        nums.push_back(1); // 左下角从1 开始
        for (auto &vec: rectangles) {
            nums.push_back(vec[0]);
            nums.push_back(vec[0] + 1);
        }
        for (auto &vec: points) {
            nums.push_back(vec[0]);
        }
        sort(nums.begin(), nums.end());

        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        unordered_map<int, int> idx;
        for (int i = 0; i < nums.size(); i++) {
            idx[nums[i]] = i + 1;
        }
        int n = nums.size();
        vector<vector<int>> G(n + 5, vector<int>(105));
        for (auto& vec: rectangles) {
            // 1, 1 vec0 vec1
            int x1 = 1, y1 = 1, x2 = idx[vec[0]], y2 = vec[1]; // 计算矩阵
            // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            G[x1][y1] += 1; // + 1 -1
            G[x2 + 1][y1] -= 1;
            G[x1][y2 + 1] -= 1;
            G[x2 + 1][y2 + 1] += 1;
        }
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 100; j++) {
                G[i][j] += G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1]; // 恢复原数组
            }

        vector<int> ans;

        for (auto& vec: points) {
            int x = idx[vec[0]], y = vec[1];
            ans.push_back(G[x][y]);
        }
        return ans;
    }
};
```