# ch10 计算几何

## 计算几何入门

### 叉积
>  给定两个有向线段：$p_0p_1$， $p_0p_2$，叉积是他们张成的平行四边形的面积

公式1：$p_1 \times p_2 = x_1y_2 - x_2y_1 = -p_1 \times p_2$
公式2：$p_1 \times p_2 = |p_1| \times |p2| \times sin\theta$

作用：
* 顺时针判定：叉积为正，$p_2$在$p_1$逆时针，为负，$p_2$在$p_1$
* 共线(平行)判定：叉积为 0

### 点积

公式1： $p_1 \cdot p_2 = x_1 \times x_2 + y_1 \times y_2$
公式2： $p_1 \cdot p_2 = |p_1| \times |p2| \times cos\theta$

作用：判断两条线段是否垂直。如果垂直，点积为 0

### 点在线段上

判断：叉积为 0 并且 横纵坐标在线段范围内


### 问题1：顺时针判定
> 给定两个有向线段：$p_0p_1$， $p_0p_2$，相对于他们的公共端点 $p_0$ 来说，$p_0p_1$ 是否在$p_0p_2$ 的顺时针方向？

使用叉积立刻得出结果


### 问题2：左转判定
> 给定两个有向线段：$p_0p_1$， $p_1p_2$，如果沿着 $p_0p_1$ 前进，再沿着 $p_1p_2$前进，在$p_1$点处是否需要左转？

同样使用叉积计算：$(p_1 - p_0) \times (p_2 - p_1)$ 结果为正，需要左转，结果为负需要右转，结果为0，一条直线


### 问题3：线段相交
> 给定两个有向线段：$p_0p_1$， $p_2p_3$，是否相交

判定：
* 计算四个叉积, 并判断：((d1 > 0 and d2 < 0) or (d1 < 0 and d2 >0)) and ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 >0))
  * d1 = directdon(p3, p4, p1)
  * d2 = direction(p3, p4, p2)
  * d3 = direction(p1, p2, p3)
  * d4 = direction(p1, p2, p4)
* 或者，点在直线上

### 矩形判定：
方式1：三个角垂直
方式2：两个交垂直 + 一对边相等
方式3：一个角垂直 + 两对边相等,但是可以计算出第四个点，方式三 + 哈希表最容易

这里封装了几个函数，以后可以参考：
* 判断垂直
* 求矩形面积
* 向量求和
```c++
// 方式一
class Solution {
public:
    vector<vector<int>> *pt;
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        pt = &points;
        double ans = 1000000000000000;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) 
                for (int k = j + 1; k < n; k++)
                    for (int p = k + 1; p < n; p++) {
                        if (isVertical(i, j, k) && isVertical(p, j, k) && isVertical(j, i, p)) {
                            ans = min(ans, recAera(i, j, k));
                        }
                        if (isVertical(i, j, p) && isVertical(k, j, p) && isVertical(j, i, k)) {
                            ans = min(ans, recAera(i, j, p));
                        }
                        if (isVertical(i, p, k) && isVertical(j, p, k) && isVertical(k, i, j)) {
                            ans = min(ans, recAera(i, p, k));
                        }
                    }
        }
        return ans > 100000000000000 ? 0.0 : ans;
    }
    bool isVertical(int i, int j, int k) {
        vector<vector<int>> &points = *pt;
        int x1 = points[j][0] - points[i][0];
        int y1 = points[j][1] - points[i][1];
        int x2 = points[k][0] - points[i][0];
        int y2 = points[k][1] - points[i][1];
        
        return x1 * x2 + y1 * y2 == 0;
    }
    double recAera(int i, int j, int k) {
        vector<vector<int>> &points = *pt;
        int x1 = points[j][0] - points[i][0];
        int y1 = points[j][1] - points[i][1];
        int x2 = points[k][0] - points[i][0];
        int y2 = points[k][1] - points[i][1];
        return abs(x1 * y2 - x2 * y1);
    }
};

方式三
class Solution {
public:
    vector<vector<int>> *pt;
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        pt = &points;
        unordered_set<int> pt;
        for (auto &vec: points) {
            int x = vec[0], y = vec[1];
            pt.insert(x * 10000 + y);
        }
        double ans = 1000000000000000;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) 
                for (int k = j + 1; k < n; k++) {
                    if (isVertical(i, j, k)) {
                        vector<int> tp = addVec(i, j, k);
                        if (pt.count(tp[0] * 10000 + tp[1]))
                            ans = min(ans, recAera(i, j, k));
                    }
                    if (isVertical(j, i, k)) {
                        vector<int> tp = addVec(j, i, k);
                        if (pt.count(tp[0] * 10000 + tp[1]))
                            ans = min(ans, recAera(i, j, k));
                    }
                    if (isVertical(k, i, j)) {
                        vector<int> tp = addVec(k, i, j);
                        if (pt.count(tp[0] * 10000 + tp[1]))
                            ans = min(ans, recAera(i, j, k));
                    }
                }

        }
        return ans > 100000000000000 ? 0.0 : ans;
    }

    vector<int> addVec(int i, int j, int k) {
        vector<vector<int>> &points = *pt;
        vector<int> res(2);
        res[0] = points[j][0] + points[k][0] - points[i][0];
        res[1] = points[j][1] + points[k][1] - points[i][1];
        return res;
    }
};

```

### 矩形重合判定
* [Blocked Billboard B](https://www.luogu.com.cn/problem/P4122)
    * [code](./code/P4122.md)



## 直线
* [P2789 直线交点数](https://www.luogu.com.cn/problem/P2789)
    * [code](../luogu/math/P2789.md)