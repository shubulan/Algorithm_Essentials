## 不常用的算法

### 高精度算法


### 离散化算法

代表题目
* [2250. 统计包含每个点的矩形数目](https://leetcode.cn/problems/count-number-of-rectangles-containing-each-point/description/)
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