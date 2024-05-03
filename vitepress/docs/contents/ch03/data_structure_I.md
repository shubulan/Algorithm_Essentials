# sec 01 基本数据结构

> 数据结构的第一部分，简单好写的数据结构
[[toc]]

## 堆


## trie 树


## 并查集
> 模板
```
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
    * 例题：
```

```
* 添加约束：将必须同时满足的状态放在一起
    * [AcWing 240. 食物链](https://www.acwing.com/activity/content/code/content/7207951/) 
    * 将 `X 是动物 a 时， Y 必须是什么动物` 这种约束放在一个集合里
```
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

### 字符串哈希
* 字符串哈希相当于把字符串看做 base 很大的数字
* 需两个数组：p 数组存 $p^k$，h 数组存 $[1, r]$ 的字符串哈希值
* 需要一个函数：获取 $[l, r]$ 的哈希值
* 字符串哈希数组从 1 开始

1. 模板
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
其他例题
* [1044. 最长重复子串](https://leetcode.cn/problems/longest-duplicate-substring/description/)
* [面试题 01.09. 字符串轮转](https://leetcode.cn/problems/string-rotation-lcci/description/)
  * [code](./leetcode_01.09),包括 字符串哈希、kmp 两个模板