---
head:
  - - link
    - rel: stylesheet
      href: https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.5.1/katex.min.css
---
# sec02 二分搜索

[[toc]]

## 二分查找值
要点：
* 区间是 $[l, r]$ 只要 $l \le r$, 数组中就有值需要我们判断
```c++
while (l <= r) {
  int mid = (l + r) / 2;
  if (arr[mid] == target) return mid;
  else if (arr[mid] < target) l = mid + 1;
  else r = mid - 1;
}
return false
```
### 应用
* [P1918 保龄球](https://www.luogu.com.cn/problem/P1918)
  * [code](../luogu/P1918.md)

## 二分答案与范围查找：upper_bound 与 lower_bound
> 使用场景：
> 1. 假定一个解，并判断是否可行
> 2. 最大化最小值
> 3. 最大化平均值

要点：
* 模型：问题抽象成 
  * 在数组 $[1, 1, 1, 1, 0, 0, 0, 0]$ 中找**最后一个** 1：upper_bound
  * 在数组 $[0, 0, 0, 0, 0, 1, 1, 1]$ 中找**第一个** 1: lower_bound
* 一般用到这种模型的问题，也叫**二分答案**
* 二分有很多种写法，这里只写一种
* upper_bound 和 lower_bound 不可以相互相互转换，因此两种写法都要记忆
* **真正做题时，有可能会有边界检查问题，这个无法避免**
* [数的范围](https://www.acwing.com/problem/content/791/)
  * [code](../acwing/acwing.789.md)
::: code-group
```c++ [找最后一个1]
// [1, 1, 1, 1, 0, 0, 0, 0] 找最后一个 1： upper_bound
while (l < r) {
  // 需要 + 1，保证只有两个值时，mid == 第二个值，否则会死循环
  // 考虑 [1, 0] 这种情况
  int mid = (l + r + 1) >> 1; 
  if (check(mid)) l = mid;
  else r = mid - 1;
}
```
```c++ [找第一个 1]
// [ 0, 0, 0, 0, 0, 1, 1, 1] 找第一个 1: lower_bound
while (l < r) {
  int mid = (l + r) >> 1;
  if (check(mid)) r = mid;
  else l = mid - 1;
}
```
:::

### stl 用法： lower_bound/upper_bound
作用：stl 函数在一个有序数组中找数的位置非常方便, 但是如果要自定义比较函数，就会比较麻烦。因此需要自定义比较函数时，还是手写二分比较好。

要点：
  * 使用起来容易蒙，记住接口 `xxxx_bound(it1, it2, key)`, 以及下面的说法
    * 迭代器是 c++ 经典的尾后模式，即前开后闭区间
    * lower_bound 找到可以插入 key 而不影响整体顺序的的第一个位置
    * upper_bound 找到可以插入 key 而不影响整体顺序的最后一个位置
* 例题：[2563. 统计公平数对的数目](https://leetcode.cn/problems/count-the-number-of-fair-pairs/)
```c++
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            auto it1 = lower_bound(nums.begin() + i + 1, nums.end(), lower - x);
            auto it2 = upper_bound(nums.begin() + i + 1, nums.end(), upper - x);
            res += it2 - it1;
        }
        return res;
    }
};
```
* 例题：[1671. 得到山形数组的最少删除次数](https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array/) 
  * 使用二分优化的最长上升子序列问题
```c++
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1), g(n, 1);
        vector<int> len(n + 1, 0x3f3f3f3f);
        len[0] = 0;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(len.begin(), len.end(), nums[i]);
            *it = min(*it, nums[i]);
            f[i] = it - len.begin();
        }
        int ans = 0x3f3f3f3f;
        fill(len.begin(), len.end(), 0x3f3f3f3f);
        len[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(len.begin(), len.end(), nums[i]);
            *it = min(*it, nums[i]);
            g[i] = it - len.begin();
            if (g[i] > 1 && f[i] > 1)
                ans = min(ans, n - f[i] - g[i] + 1);
        }
        return ans;
    }
};
```

### map 的 lower_bound/upper_bound
作用：
  * 能在一边插入删除，一边二分查找很有用

* [【深基17.例5】木材仓库](https://www.luogu.com.cn/problem/P5250)
  [code](../luogu/P5250.md)
  * 例题：[1488. 避免洪水泛滥](https://leetcode.cn/problems/avoid-flood-in-the-city/description/) 使用 set 边插入/移除，边二分
```c++
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> poolday;
        set<int> dry;
        int n = rains.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            if (rains[i]) {
                if (poolday.count(rains[i])) {
                    auto it = dry.lower_bound(poolday[rains[i]]);
                    if (it == dry.end()) return {};
                    res[*it] = rains[i];
                    dry.erase(it);
                }
                poolday[rains[i]] = i;
            } else {
                dry.insert(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!rains[i] && res[i] == -1) res[i] = 1;
        }
        return res;
    }
};
```

## 浮点数二分
要点：
 * 用的不多，注意循环条件是精度，写起来比较简答
* [数的三次方根](https://www.acwing.com/problem/content/792/)
  * [code](../acwing/acwing.790.md)
```c++
while (r - l > 1e-6) {
  double mid = (l + r) / 2;
  // 逼近答案即可
}
```
* 例题：[切绳子](https://oj.haizeix.com/problem/393)
  * 浮点数的二分答案
```c++
#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
double num[100005], tr;
int func(double len) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += num[i] / len;
  }
  return sum;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    tr = max(tr, num[i]);
  }
  double l = 0.0, r = tr;
  while (r - l > 0.00001) {
    double mid = (r + l) / 2;
    int s = func(mid);
    if (s >= m) {
      l = mid;
    } else {
      r = mid;
    }
  }

  printf("%.2lf\n", (int)(l * 100) / 100.0);

  return 0;
}
```

## 三分查找
要点：
 * 极其少见
 * 需要证明凸函数
 * [2448. 使数组相等的最小开销](https://leetcode.cn/problems/minimum-cost-to-make-array-equal/description/)
  * 可以证明它是一个凸函数
  * 三分查找写法参考
```c++
class Solution {
public:
    using LL = long long;
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        auto [itl, itr] = minmax_element(nums.cbegin(), nums.cend());
        int l = *itl, r = *itr;

        function<LL(int)> f = [&](int m) -> LL {
            LL res = 0;
            for (int i = 0; i < n; i++)
                res += abs(nums[i] - m) * (LL) cost[i];
            return res;
        };

        while (l < r) {
            int delta = (r - l) / 3;
            int midl = l + delta, midr = r - delta;
            if (f(midl) > f(midr)) l = midl + 1;
            else r = midr - 1;
        }
        return f(l);

    }
};
```

## 其他例题
### 二分答案
* [伐木](https://oj.haizeix.com/problem/82)
  * [code](./code_binary_search/82.oj)

* [吃瓜群众升级版](https://oj.haizeix.com/problem/387)
  * [code](./code_binary_search/387.oj.md)

* [暴躁的程序猿](https://oj.haizeix.com/problem/389)
  * [code](./code_binary_search/389.oj.md)

* [原木切割](https://oj.haizeix.com/problem/390)
  * [code](./code_binary_search/390.oj.md)

* [数列分段](https://oj.haizeix.com/problem/391)
  * [code](./code_binary_search/391.oj.md)

* [跳石头](https://oj.haizeix.com/problem/394)
  * [code](./code_binary_search/394.oj.md)

* [复制书稿](https://oj.haizeix.com/problem/395)
  * [code](./code_binary_search/395.oj.md)

### 最小化最大值

* [我在哪？](https://www.acwing.com/problem/content/1462/)
  * [code](./code_binary_search/acwing1460)

### 最大化平均值：浮点二分答案
* [最大化平均值](https://blog.csdn.net/karry_zzj/article/details/70232097)
```c++

bool C(double x) {
  for (int i = 0; i < n; i++) {
    y[i] = v[i] - x * w[i];
  }
  sort(y, y + n);
}

void solve() {
  double lb = 0, ub = inf;
  for (int i = 0; i < 100; i++) {
    double mid = (lb + ub) / 2;
    if (C(mid)) lb = mid;
    else ub = mid;
  }
}

```

### 二分查找值
* [吃瓜群众](https://oj.haizeix.com/problem/386)
  * [code](./code_binary_search/386.oj.md)




