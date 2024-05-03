
::: code-group
```c++ [字符串哈希搜索]
typedef unsigned long long ULL;
class Solution {
 public:
  bool isFlipedString(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    s1 += s1;
    int n = s1.size();
    vector<ULL> h(n + 1), p(n + 1);
    ULL base = 13131;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
      h[i] = h[i - 1] * base + (s1[i - 1]);
      p[i] = p[i - 1] * base;
    }
    ULL cp = 0;
    for (int i = 0; i < s2.size(); i++) {
      cp = cp * base + s2[i];
    }
    int len = s2.size();
    for (int i = len; i <= n; i++) {
      ULL hp = h[i] - h[i - len] * p[len];
      if (hp == cp) return true;
    }
    return false;
  }
};
```

```c++ [字符串哈希比较]
class Solution {
public:
    using ULL = unsigned long long;
    const int P = 13331;

    bool isFlipedString(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n != m) return false;
        if (n == 0) return true;
        vector<ULL> p(n + 1), h(n + 1), h2(n + 1);
        p[0] = 1;
        auto get = [&](vector<ULL> &h, int l, int r) {
            return h[r] - h[l - 1] * p[r - l + 1];
        };
        for (int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * P + s1[i - 1];
            h2[i] = h2[i - 1] * P + s2[i - 1];
            p[i] = p[i - 1] * P;
        }
    
        for (int i = 0; i < n; i++) {
            if (h[n - i - 1] == get(h2, i + 2, n) && get(h, n - i, n) == h2[i + 1]) return true;
        }
        return false;
    }
};
```

```c++ [kmp搜索]
typedef unsigned long long ULL;
class Solution {
public:
    int kmp(const string& s, const string& p) {
        int n = s.size(), m = p.size();
        if (n == m) return s == p ? 0 : -1;
        if (n < m) return -1;
        if (m == 0) return 0; // p 为空，返回 0
        vector<int> nxt(m);
        int j = -1;
        nxt[0] = j;
        for (int i = 1; i < m; i++) {
            while (j != -1 && p[i] != p[j + 1]) j = nxt[j];
            if (p[i] == p[j + 1]) j++;
            nxt[i] = j;
        }
        for (int i = 0, j = -1; i < n; i++) {
            while (j != -1 && s[i] != p[j + 1]) j = nxt[j];
            if (s[i] == p[j + 1]) j++;

            if (j == m - 1) {
                /* 从下一个位置继续匹配 */
                // cout << i - n + 1 << " ";
                // j = nxt[j];
                /* 返回答案 */
                return i - m + 1;
            }
        }
        return -1;
    }
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        s1 += s1;
        int pos = kmp(s1, s2);
        return pos != -1;
    }
};
```
:::
