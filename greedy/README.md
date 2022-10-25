# 贪心算法
> 贪心算法背后都有一个动态规划算法，可以思考一下

# 序列比较
[leetcode 870. 优势洗牌](https://leetcode.cn/problems/advantage-shuffle/)
> 如果能超过，就选能超过的最小的，如果不能超过，就选最最小的(反正超不过)

## 滑动窗口
[欧拉计划8](http://pe-cn.github.io/8/) 这个不是贪心，只是滑动窗口而已，算是模拟。题目就要求窗口。有一个坑是维护非0值
[904. 水果成篮](https://leetcode.cn/problems/fruit-into-baskets/)
> 标准的滑动窗口算法
> 枚举右指针，将内容加入窗口。如果违背窗口规则，左移指针直到符合规则,然后更新答案

## 双指针：证明思路
[6207. 统计定界子数组的数目](https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/)

## 贪心与其他问题的结合：考察证明
[AcWing 1996. 打乱字母](https://www.acwing.com/activity/content/problem/content/6501/)