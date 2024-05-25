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

## 

* [399. 小明吃饭](https://oj.haizeix.com/problem/399)
    * [code](./code_brute_enumeration/399.oj.md)

* [304. 骑士风度的牛](https://oj.haizeix.com/problem/304)
    * 不同的方向数组
    * [code](./code_brute_enumeration/304.oj.md)

* [398. 马的遍历](https://oj.haizeix.com/problem/398)
    * 求所有点的最短路径
    * [code](./code_brute_enumeration/398.oj.md)

* [400. 奇怪的象棋游戏](https://oj.haizeix.com/problem/400)  
    * [code](./code_brute_enumeration/400.oj.md)

* [401. 奇怪的象棋游戏升级版](https://oj.haizeix.com/problem/401) 
    * 反向搜索，求所有* 点的最短路径
    * [code](./code_brute_enumeration/401.oj.md)

* [303. 矩阵距离一](https://oj.haizeix.com/problem/303)
    * 反向搜索，多源
    * [code](./code_brute_enumeration/303.oj.md)

* [305. 乳草的入侵](https://oj.haizeix.com/problem/305)
    * 搜素终止条件、层序遍历
    * [code](./code_brute_enumeration/305.oj.md)
* [529. 龙与虫](https://oj.haizeix.com/problem/529)
    * 终止条件轻微变化
    * [code](./code_brute_enumeration/529.oj.md)

* [527. 飞跃原野](https://oj.haizeix.com/problem/527)
    * 难度较高的最短路问题，状态与操作复杂
    * [code](./code_brute_enumeration/527.oj.md)

[LCP 63. 弹珠游戏](https://leetcode.cn/problems/EXvqDp/)
    * 疯狂卡常数的一道搜索题