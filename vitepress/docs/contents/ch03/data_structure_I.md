---
head:
  - - link
    - rel: stylesheet
      href: https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.5.1/katex.min.css
---
# 基本数据结构

> 数据结构的第一部分，简单好写的数据结构
[[toc]]

## 二叉树
### 遍历
* [树的遍历](https://www.acwing.com/problem/content/1499/)
    * [code](./code/acwing1497)
### 直径
* [二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/description/)
```c++
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root) {
        if (!root) return -1;

        int l = dfs(root->left);
        int r = dfs(root->right);
        res = max(res, l + r + 2);

        return 1 + max(l, r);
    }
};
```
* [二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/)
```c++
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

## 栈
* 栈最好用vector实现，不要傻乎乎的非用 stack
* 匹配解析类的问题，往往需要在遍历完之后，再执行依次操作

代表例题：
* [使括号有效的最少添加](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/)
  * 可以用栈理解，没必要用栈实现
```c++
class Solution {
public:
    int minAddToMakeValid(string s) {
        int j = 0, k = 0; 
        for (auto c : s) {
            if (c == '(') {
                j++;
            } else if (c == ')') {
                if (j > 0) j--;
                else k++;
            }
        }
        return j + k;
    }
};
```
* [括号的分数](https://leetcode.cn/problems/score-of-parentheses/)
  * 栈运用题,还是比较容易写错的
```c++
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for (auto c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int tres = 0;
                while (st.top() != 0) {
                    tres += st.top(); st.pop();
                }
                st.pop();
                if (tres == 0) st.push(1);
                else st.push(tres * 2);
            }
        }
        int res = 0;
        while (st.size()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
```
* [最小栈](https://leetcode.cn/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150)
    * 栈可以同时维护其他信息
```c++
class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        min_st.push((min_st.empty() || val <  min_st.top()) ? val : min_st.top());
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
private:
    stack<int> st;
    stack<int> min_st;
};
```
* 表达式求值类
    * [逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation)
        * [code](./code/leetcode_150.md)
    * [基本计算器](https://leetcode.cn/problems/basic-calculator)
        * [code](./code/leetcode_224.md)

## 单调队列
* [P1886 滑动窗口 /【模板】单调队列](https://www.luogu.com.cn/problem/P1886)
    * [P1886 滑动窗口 /【模板】单调队列](../luogu/linear/P1886.md)
* [P2032 扫描](https://www.luogu.com.cn/problem/P2032)
    * [code](../luogu/linear/P2032.md)
* [P1440 求m区间内的最小值](https://www.luogu.com.cn/problem/P1440)
    * [code](../luogu/linear/P1440.md)



## 堆
### stl:优先队列
> 大部分场景下使用 stl 提供的优先队列即可。即使是 dijkstra 算法，也可以用重复加入的方式来解决。

* 要点：stl 中默认使用 $<$ 做比较，形成大顶堆

* 例题：[会议室 III](https://leetcode.cn/problems/meeting-rooms-iii/)
  * 需要两个堆：一个维护最小空闲编号，一个维护最早结束时间
  * 还需要根据题目来用好这两个堆，题目有一定难度
```c++
typedef long long LL;
typedef pair<LL, int> PLI;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> qid;
        priority_queue<PLI, vector<PLI>, greater<PLI>> qet;
        for (int i = 0; i < n; i++) qid.push(i);
        int res = -1;
        vector<int> cnts(n);
        for (auto& p : meetings) {
            while (qet.size() && qet.top().first <= (LL)p[0]) {
                qid.push(qet.top().second);
                qet.pop();
            }
            int x = -1;
            if (!qid.empty()) {
                x = qid.top();
                qid.pop();
                qet.push({p[1], x});
            } else {
                auto m = qet.top();
                x = m.second;
                qet.pop();
                m.first += p[1] - p[0];
                qet.push(m);
            }
            cnts[x]++;
            if (res == -1 || cnts[x] > cnts[res] || (x < res && cnts[x] == cnts[res])) res = x;
        }
        return res;
    }
};
```

### 堆排序
* [堆排序](https://www.acwing.com/problem/content/840/)
  * [code](../acwing/acwing.838.md)

### 动态更新堆
> stl的优先队列只能快速获取最小值或者最大值，但是无法更新。例如：我想将 key 为 10 的节点，更新为 12，如果是大顶堆，那么节点应该上升。这里实现一下。
* [模拟堆](https://www.acwing.com/problem/content/841/)
  * [内有模板 code](../acwing/acwing.839.md)

## 链表


## 哈希表
> 哈希没什么好讲的，可以看作一种普通数组，用于模拟题、优化之类的。这里只给出一种求字符串哈希值的技巧，该技巧可以用到求多个数的哈希值上

```c++
ULL get(string& s) {
    const int mod = 13331;
    ULL res = 1;
    for (auto x : s) {
        res = (res * x) % mod;
    }
    return res;
}
```
### 应用题
> 一些能用到哈希表的题，不难
* [笨拙的手指](https://www.acwing.com/problem/content/2060/)
    * [code](./code/acwing2058.md)
* [P3405 [USACO16DEC] Cities and States S](https://www.luogu.com.cn/problem/P3405)
    * [code](./code/P3405.md)