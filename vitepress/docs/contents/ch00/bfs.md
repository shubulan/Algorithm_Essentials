# 广度优先：无权图的最短路径
> 广度优先搜索可以实现求无权图的最短路

## [走迷宫](https://www.acwing.com/problem/content/846/)
* [code](../acwing/acwing.844.md)

## [八数码](https://www.acwing.com/problem/content/847/)
* [code](../acwing/acwing.845.md)

## [飞行棋](https://leetcode.cn/problems/snakes-and-ladders/?envType=study-plan-v2&envId=top-interview-150)
    * 长度到二维矩阵的映射
```c++
class Solution {
public:
    void get(int d, int &x, int&y, int n) {
        int row = (d - 1) / n, col = (d - 1) % n;
        x = n - 1 - row;
        y = row % 2 ? n - 1 - col : col;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dist(n * n + 1, -1);
        queue<int> que;
        que.push(1);
        dist[1] = 0;
        while (que.size()) {
            int t = que.front(); que.pop();
            for (int i = t + 1; i <= min(t + 6, n * n); i++) {
                int nt = i, x, y;
                get(nt, x, y, n);
                if (board[x][y] != -1) {
                    nt = board[x][y];
                }
                if (dist[nt] != -1) continue;
                dist[nt] = dist[t] + 1;
                que.push(nt);
            }

        }
        return dist[n * n];
    }
};
```