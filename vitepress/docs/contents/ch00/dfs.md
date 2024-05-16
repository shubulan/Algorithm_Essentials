# 深度优先：回溯与递归
> 深度优先搜索往往与回溯问题与递归问题结合在一起
> 其本质上是：循环枚举，指数型枚举、递归型枚举、全排列型枚举，这些放在后面讲

## 判断可行选择
[n-皇后问题](https://www.acwing.com/problem/content/845/)
* 假设 8x8 的棋盘，一种解为[0, 0, 2, 3, 4, 5, 6, 7],表示 第一行 放 0 位置，第二行放 0 位置， 第三行放 2 位置，依次类推，那么这相当于一个 8 重循环。只需要在在最内层循环验证答案即可。
* 考虑到不能有在同一个位置的行，所以也可以看作是 [0, 1, 2, 3, 4, 5, 6, 7] 的全排列，然后在最后一行验证答案
* 如果再考虑一些剪枝技巧，效率还是蛮高
* [code](../acwing/acwing.843.md)

## 枚举所有路径
* [单词搜索](https://leetcode.cn/problems/word-search-ii/description/?envType=study-plan-v2&envId=top-interview-150)
* 这题相当暴力
* 带限制的搜索
::: code-group
```c++ [暴力]
class Solution {
public:
    int n, m;
    vector<string> res;
    string cur;
    set<string> w;
    vector<vector<int>> vs;
    vector<vector<char>>* pb;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();
        pb = &board;
        vs.resize(n);
        for (auto &v : vs) v.resize(m);
        w.insert(words.begin(), words.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, 0);
            }
        }
        return res;
    }
    void dfs(int x, int y, int wc) {
        
        // cout << cur << endl;
        if (wc == 10) {
            return;
        }
        vector<vector<char>>& board = *pb;
        cur += board[x][y];
        vs[x][y] = true;
        if (w.count(cur)) {
            res.push_back(cur);
            w.erase(cur);
        }
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vs[nx][ny]) continue;
            dfs(nx, ny, wc + 1);
        }
        cur.pop_back();
        vs[x][y] = false;
    }

};
```
```c++ [trie 树]
class Solution {
public:
    int n, m;
    vector<string> res;
    string cur;
    vector<vector<int>> vs;
    vector<vector<char>>* pb;
    struct Node {
        bool flag = {0};
        Node *children[26] = {0};
    };
    Node root;
    void add(string s) {
        Node *p = &root;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (!p->children[idx]) {
                p->children[idx] = new Node;
            }
            p = p->children[idx];
        }
        p->flag = true;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();
        pb = &board;
        vs.resize(n);
        for (auto &v : vs) v.resize(m);
        for (auto &s : words) add(s);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, &root);
            }
        }
        return res;
    }
    void dfs(int x, int y, Node *p) {
        vector<vector<char>>& board = *pb;
        int idx = board[x][y] - 'a';
        if (!p->children[idx]) return;
        Node *cp = p->children[idx];
        cur += board[x][y];
        vs[x][y] = true;
        if (cp->flag) {
            res.push_back(cur);
            cp->flag = false;
        }
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vs[nx][ny]) continue;
            dfs(nx, ny, cp);
        }
        cur.pop_back();
        vs[x][y] = false;
    }

};
```
:::



## 其他练习

* [1718. 构建字典序最大的可行序列](https://leetcode.cn/problems/construct-the-lexicographically-largest-valid-sequence/description/)
```
class Solution {
public:
    vector<int> res;
    vector<int> vis;
    vector<int> constructDistancedSequence(int n) {
        res.resize(2 * (n - 1) + 1);
        vis.resize(n + 1);
        dfs(0);
        return res;
    }
    bool dfs(int idx) {
        int n = vis.size() - 1;
        if (idx == res.size()) return true;
        for (int i = n; i > 0; i--) {
            if (vis[i]) continue;
            if (i == 1) {
                res[idx] = i;
            } else {
                if (idx + i >= res.size() || res[idx + i]) continue;
                res[idx] = i;
                res[idx + i] = i;
            }
            vis[i] = true;
            int nx = idx + 1;
            while (nx < res.size() && res[nx]) nx++;
            if (dfs(nx)) return true;
            if (i == 1)
                res[idx] = 0;
            else {
                res[idx] = 0;
                res[idx + i] = 0;
            }
            vis[i] = false;
        }
        return false;
    }
};

```