# 暴力枚举
> 暴力是包括搜索的，所以这里列出了一部分，还有一部分难一点的，放在单独的搜索篇章

## [洛谷题单](https://www.luogu.com.cn/training/108)

## 简单二层循环
[欧拉计划4](http://pe-cn.github.io/4/)
[欧拉计划32](http://pe-cn.github.io/32/) 枚举边界，计算10进制数个数

[欧拉计划30](http://pe-cn.github.io/30/) 估算枚举上界
[欧拉计划34](http://pe-cn.github.io/34/) 估算枚举上界

## 指数型枚举 就是一组数中随便选，列出所有可能的选法，一般都通过递归实现
[235. 递归实现指数型枚举](https://oj.haizeix.com/problem/235)
## 组合型枚举 
[236. 递归实现组合型枚举](https://oj.haizeix.com/problem/236)
## 排列型枚举
[237. 递归实现排列型枚举](https://oj.haizeix.com/problem/237)

## 深度优先搜索 DFS
深度优先搜索与以上几种枚举方式息息相关。深度优先搜索本质上就是暴力枚举
### 搜索走地图问题
[535. 瓷砖](https://oj.haizeix.com/problem/535)  连通图的深度优先遍历
[397. 僵尸来袭](https://oj.haizeix.com/problem/397) 非连通图的深度优先遍历 ，求联通分量个数
[536. 最大黑色区域](https://oj.haizeix.com/problem/536)  求最大的连通分量
[396. 填涂颜色](https://oj.haizeix.com/problem/396)  地图涂色的技巧 ，也可以广搜，主要是涂颜色
[404. 01迷宫简易版](https://oj.haizeix.com/problem/404)  瓷砖问题的升级版
[405. 01迷宫](https://oj.haizeix.com/problem/405)  限制步数的搜索问题


## 广度优先搜索 无权无方向图的最短路问题
[399. 小明吃饭](https://oj.haizeix.com/problem/399)  
[304. 骑士风度的牛](https://oj.haizeix.com/problem/304)  不同的方向数组
[398. 马的遍历](https://oj.haizeix.com/problem/398)  求所有点的最短路径
[400. 奇怪的象棋游戏](https://oj.haizeix.com/problem/400)  
[401. 奇怪的象棋游戏升级版](https://oj.haizeix.com/problem/401) 反向搜索，求所有点的最短路径
[303. 矩阵距离一](https://oj.haizeix.com/problem/303)  反向搜索，多源

[305. 乳草的入侵](https://oj.haizeix.com/problem/305)  搜素终止条件、层序遍历
[529. 龙与虫](https://oj.haizeix.com/problem/529)  终止条件轻微变化
[527. 飞跃原野](https://oj.haizeix.com/problem/527)  难度较高的最短路问题，状态与操作复杂

[LCP 63. 弹珠游戏](https://leetcode.cn/problems/EXvqDp/) 疯狂卡常数的一道搜索题