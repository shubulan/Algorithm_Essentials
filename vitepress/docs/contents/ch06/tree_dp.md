# 树形 DP

* 在子树范围内解决问题
* 把必要的结果返回给父节点

* [没有上司的舞会](../acwing/acwing.285)
* [362. 选课](https://oj.haizeix.com/problem/362)
* [363. Strategic_game](https://oj.haizeix.com/problem/363)

* [二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/)
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = -0x3f3f3f3f;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int val = root->val;
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        res = max(res, val + l + r);
        return val + max(l, r);
    }
};
```