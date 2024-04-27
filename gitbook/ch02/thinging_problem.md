# sec 04 思维题
> 思维题没有固定套路，有的只是思考，代表类型贪心和构造题目
> 其实所有题目都是思维题目，只不过大多数思维题最后都能翻译成一种常见算法。
> 而这里的思维题，最后翻译成模拟题，没有固定套路

## 构造题
> 构造题是最锻炼思维和代码能力的一种题目，想要上分，就多刷这种题目
* [2573. 找出对应 LCP 矩阵的字符串](https://leetcode.cn/problems/find-the-string-with-lcp/)

```
class Solution {
 public:
  string findTheString(vector<vector<int>>& lcp) {
    int n = lcp.size();
    string s(n, '0');
    char c = 'a';
    while (true) {
      int i = 0;
      for (; i < n; i++)
        if (s[i] == '0') break;
      if (i == n) break;
      if (c == 'z' + 1) return "";
      for (int j = i; j < n; j++) {
        if (!lcp[i][j]) continue;
        if (s[j] != '0') return "";
        s[j] = c;
      }
      c++;
    }
    if (check(lcp, s)) return s;
    return "";
  }
  bool check(vector<vector<int>>& lcp, string& s) {
    int n = s.size();
    vector<vector<int>> llcp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (s[i] == s[j]) {
          int a = 0;
          if (i + 1 < n && j + 1 < n) a = llcp[i + 1][j + 1];
          llcp[i][j] = a + 1;
        }
        if (llcp[i][j] != lcp[i][j]) return false;
      }
    }

    return true;
  }
};
```

