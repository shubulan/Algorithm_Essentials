---
head:
  - - link
    - rel: stylesheet
      href: https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.5.1/katex.min.css
---
# 线性dp
> 线性 dp 指的是问题可以通过直观的一维或者二维的递推来理解和解决
## 最大子数组和模型
* [最大子数组和](https://leetcode.cn/problems/maximum-subarray/description/)
* [坏掉的项链 Broken Necklace](https://www.luogu.com.cn/problem/P1203)
    * [code](../luogu/dynamic_programming/P1203.md)

## 数字三角形模型
* [数字三角形](https://www.acwing.com/problem/content/900/)
    * [code](../acwing/acwing.898.md)
* [过河卒](https://www.luogu.com.cn/problem/P1002)
    * 数字三角形求方案数 
    * [code](../luogu/dynamic_programming/P1002)

## 最长上升子序列
* [最长上升子序列](https://www.acwing.com/problem/content/897/)
* [最长上升子序列 II](https://www.acwing.com/activity/content/problem/content/1004/)
    * [code](../acwing/acwing.895_896.md)

## 最长公共子序列
* [最长公共子序列](https://www.acwing.com/problem/content/899/)
    * [code](../acwing/acwing.902.md)

## 最短编辑距离
* [最短编辑距离](https://www.acwing.com/problem/content/904/)
    * [code](../acwing/acwing.899.md)

## 划分型dp
> 划分型 dp 最难的点在于如何想清楚分割点与状态点

* [分割字符频率相等的最少子字符串](https://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequency)

* 定义状态: $f[i]$ 表示 $f[i]$ 表示 $[0, i]$ 区间的最少分割字符串。
* 状态计算：$f[i] = max(f[t] + 1)~forall~t, [t + 1, i]$ 可以正确分割 。复杂度 $O(n^2 \times k)$,k 为验证是否正确分割的复杂度
* 初始状态：$f[0] = 1$。
* 代码实现与状态偏移调整：注意到，$[0, i]$能否正常分割也是需要判断的，所以 t 要遍历到 $-1$ 的位置，为了避免这个尴尬，需要将$f[i + 1]$ 定义为 $[0, i]$ 区间的最少分割字符串。这样，$f[0]$ 的意义就变了，变成了没有字符串时，最少分割多少字符串？显然$f[0] = 0$;
```c++
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> f(n + 1, 0x3f3f3f3f);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> h(26);
            for (int j = i - 1; j >= 0; j--) {
                int c = s[j] - 'a';
                h[c]++;
                bool flag = true;
                for (int i = 0, last = 0; i < 26; i++) {
                    if (!h[i]) continue;
                    if (last == 0) last = h[i];
                    else if (h[i] != last) {
                        flag = false;
                        break;
                    }
                }
                if (flag) f[i] = min(f[i], f[j] + 1);
            }
        }
        return f[n];
    }
};

```

* [最长前缀 Longest Prefix](https://www.luogu.com.cn/problem/P1470)
    * [code](../luogu/dynamic_programming/P1470.md)