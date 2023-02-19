/*
思路：
因为不知道字符串是什么，所以肯定想通过lcp数组把s给构造出来。
然后在构造的过程中判断是否有矛盾。如果有矛盾，返回空串。如果没矛盾，返回构造出的字符串。

lcp[i][j] 表示分别从i, j开始，正好有lcp[i][j]个字符是相等的。

考虑第一行
由于需要最小的字符串，所以s[0] 肯定为a。
lcp[0][j]如果大于0，那么至少说明s[j]一定也是'a'。至于lcp[0][j]有多大，后面连续的相等的字符是什么，不好说。
lcp[0][j]如果等于0，那么说明s[j]一定不可以等于'a',具体是多少，也不好说，可能是'b'，但绝不可能是'a'。
  这里可能会想到把其他的都填'b'，但是这种感觉是没道理的。

这里，我们可以确定一部分位置一定是a我们可以继续往下迭代，找到下一个未确定的位置k,再考虑第k行
考虑第k行
目前知道s[k]一定是一个未定义的值。不妨设他为b，那么，和第一行一样
lcp[k][j] 如果大于0，s[j] 一定等于'b'。(不能是a,就设置为下一个字符喽)
lcp[k][j] 如果等于0，其还是不能确定，但一定不是'b'

这里可以继续迭代，发现只要字符管够，后面一定能够把s填完。
当然字符是不够的，最多到'Z',那就返回空串。

按照以上思路依次确定的字符串，理论上是可以的，但是不一定满足原来的lcp表。
因为lcp[i][j]的大小，我们并没有考虑。按照上面的过程，lcp[i][j]只有等于0和大于0的区别。
因此，需要再验证一遍。

证明：s是最小的串
我们是从a往后写的，所以一定是最小的。

*/

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '0');
        char c = 'a';
        while (true) {
            int i = 0;
            for (; i < n; i++) if (s[i] == '0') break;
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
    bool check(vector<vector<int>>& lcp, string &s) {
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