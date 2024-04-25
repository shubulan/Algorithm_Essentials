## 不常用的算法
[toc]

### 高精度算法

### 离散化算法
* 离散化可以减小数据空间，将$-10^9~10^9$ 映射到 [1, n]
* 离散化可以用二分来查询，也可以用哈希表来查询。
* 如果用二分，可以减小一部分数据量。因为只需要将查询值二分到合适的边界即可。
* 如果用哈希，则需要把查询值也映射到边界
代表题目
* [2250. 统计包含每个点的矩形数目](https://leetcode.cn/problems/count-number-of-rectangles-containing-each-point/description/)
    * 哈希离散化
```
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
// 离散化
        vector<int> nums;
        nums.push_back(1);
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
// 离散化完成 nums 是原数组， idx 是索引映射
        vector<vector<int>> G(n + 5, vector<int>(105));
        for (auto& vec: rectangles) {
            int x1 = 1, y1 = 1, x2 = idx[vec[0]], y2 = vec[1];
            G[x1][y1] += 1;
            G[x2 + 1][y1] -= 1;
            G[x1][y2 + 1] -= 1;
            G[x2 + 1][y2 + 1] += 1;
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 100; j++) {
                G[i][j] += G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1];
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
* [2426. 满足不等式的数对数目](https://leetcode.cn/problems/number-of-pairs-satisfying-inequality/)
    * 离散化与树状数组
```class Solution {
public:
    vector<long long> tree_;
    long long query(int idx) {
        long long sum = 0;
        while (idx) {
            sum += tree_[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    void add(int idx, int x) {
        while (idx < tree_.size()) {
            tree_[idx] += x;
            idx += idx & (-idx);
        }
    }
    void initTree(int n) {
        tree_.resize(n);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        for (int i = 0; i < n; i++) nums1[i] -= nums2[i];

        // 离散化
        vector<int> dic;
        for (int i = 0; i < n; i++) dic.push_back(nums1[i]);
        sort(dic.begin(), dic.end());
        dic.erase(unique(dic.begin(), dic.end()), dic.end());

        // 树状数组
        long long res = 0;
        initTree(dic.size() + 1);
        for (int i = 0; i < n; i++) {
            int x = upper_bound(dic.begin(), dic.end(), nums1[i] + diff) - dic.begin();
            int y = lower_bound(dic.begin(), dic.end(), nums1[i]) - dic.begin() + 1;
            res += query(x);
            add(y, 1);
        }
        return res;
    }
};

```