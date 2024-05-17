# sec 01 基本数据结构

> 数据结构的第一部分，简单好写的数据结构
[[toc]]

## 二叉树
* [树的遍历](https://www.acwing.com/problem/content/1499/)
    * [code](./code/acwing1497)

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


## 二叉树

### 遍历


### 直径




## trie 树


## 并查集
> 模板
```c++
int p[N];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
void unite(int x, int y) {
  x = find(x), y = find(y);
  p[x] = y;
}
for (int i = 0; i <= n; i++) p[i] = i;

```
> 并查集有两种思路
* 数据结构：维护不相交的集合
* 例题：[打击犯罪](https://www.acwing.com/problem/content/description/1253/)
    * [code](./code/acwing1251.md)
* 例题：[P1551 亲戚](https://www.luogu.com.cn/problem/P1551)
    * [code](./code/P1551.md)

* 添加约束：将必须同时满足的状态放在一起
    * [AcWing 240. 食物链](https://www.acwing.com/activity/content/code/content/7207951/) 
    * 将 `X 是动物 a 时， Y 必须是什么动物` 这种约束放在一个集合里
```c++
  while (K--) {
    int d, x, y;
    cin >> d >> x >> y;
    if (x > n || x < 1 || y > n || y < 1) {
      cnt++;
      continue;
    }
    if (d == 1) { // 添加同类
      if (find(x) == find(y + n) || find(x) == find(y + 2 * n)) {
        cnt++;
        continue;
      }
      unite(x, y);
      unite(x + n, y + n);
      unite(x + 2 * n, y + 2 * n);
    } else { // 添加捕食关系
      if (find(x) == find(y) || find(x) == find(y + 2 * n)) {
        cnt++;
        continue;
      }
      unite(x, y + n);
      unite(x + n, y + 2 * n);
      unite(x + 2 * n, y);
    }
  }
  cout << cnt << endl;
```

## 哈希表
> 哈希没什么好讲的，主要说一下字符串哈希
### 哈希表的应用
* [笨拙的手指](https://www.acwing.com/problem/content/2060/)
    * [code](./code/acwing2058.md)
* [P3405 [USACO16DEC] Cities and States S](https://www.luogu.com.cn/problem/P3405)
    * [code](./code/P3405.md)

### 字符串哈希
* 字符串哈希相当于把字符串看做 base 很大的数字
* 需两个数组：p 数组存 $p^k$，h 数组存 $[1, r]$ 的字符串哈希值
* 需要一个函数：获取 $[l, r]$ 的哈希值
* 字符串哈希数组从 1 开始

模板
* 初始化
```c++
const int P = 13331;
p[0] = 1; // base ^ i 次方
for(int i = 1 ; i <= n; i++) {
    h[i] = h[i - 1] * P + str[i]; // str hash
    p[i] = p[i - 1] * P; // base ^ i  
}
```
* 获取子串哈希值
```c++
ULL get(int l, int r) { // [l, r] 的哈希值
    return h[r] - h[l - 1] * p[r - l + 1];
}
```
例题：
[3008. 找出数组中的美丽下标 II](https://leetcode.cn/problems/find-beautiful-indices-in-the-given-array-ii/description/)
```c++
class Solution {
public:
    using ULL = unsigned long long;
    const int P = 13331;
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size(), na = a.size(), nb = b.size();
        if (na > n || nb > n) return {};
        ULL ha = 0, hb = 0;
        vector<ULL> h(n + 1), p(n + 1), rb(n);
        h[0] = 0, p[0] = 1;
        for (int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }
        for (auto c : a) ha = ha * P + c;
        for (auto c : b) hb = hb * P + c;
        auto get = [&](int l, int r) -> ULL{
            return h[r] - h[l - 1] * p[r - l + 1];
        };
        vector<int> res;
        int inf = 0x3f3f3f3f;
        for (int i = n - b.size(), r = inf; i >= 0; i--) {
            ULL hj = get(i + 1, i + b.size());
            if (hj == hb) r = i;
            rb[i] = r;
        }
        for (int i = 0, lb = -inf; i <= n - a.size(); i++) {
            ULL hia = get(i + 1, i + a.size());
            ULL hib = get(i + 1, min(n, i + (int)b.size()));
            if (hib == hb) lb = i;
            if (hia == ha && (i - lb <= k || rb[i] - i <= k)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
```
#### 其他例题
* [1044. 最长重复子串](https://leetcode.cn/problems/longest-duplicate-substring/description/)
* [面试题 01.09. 字符串轮转](https://leetcode.cn/problems/string-rotation-lcci/description/)
  * [code](./leetcode_01.09),包括 字符串哈希、kmp 两个模板