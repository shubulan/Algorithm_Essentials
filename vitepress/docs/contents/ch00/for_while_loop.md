# 循环枚举

> 遍历是循环中最重要的思想。循环是最基础的遍历方式，往往用于线性表的遍历，俗称‘扫描一遍’


## 简单循环
* [3或5的倍数](http://pe-cn.github.io/1/)

* [偶斐波那契数](http://pe-cn.github.io/2/)

* [最大回文乘积](http://pe-cn.github.io/4/)
    * 回文数判断
    * [code](./code_brute_enumeration/4.euler.md)

## 斜向循环
* [方阵中的最大乘积](http://pe-cn.github.io/11/)
    * 方向数组
## 需要估算枚举范围
* [全数字的乘积](http://pe-cn.github.io/32/)
    * 枚举边界，计算10进制数个数
    * [code](./code_brute_enumeration/32.euler.md)

* [各位数字的五次幂](http://pe-cn.github.io/30/) 
    * 估算枚举上界
    * [code](./code_brute_enumeration/30.euler.md)

* [数字阶乘和](http://pe-cn.github.io/34/)
    * 估算枚举上界
    * [code](./code_brute_enumeration/34.euler.md)

## 字符串
### [93. 复原 IP 地址](https://leetcode.cn/problems/restore-ip-addresses/description/)
* 通过尾后位置分割数组
```c++ []
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> res;
        for (int i = 1; i <= n - 3 && i <= 3; i++) {
            for (int j = i + 1; j <= n - 2 && j - i <= 3; j++) {
                for (int k = j + 1; k <= n - 1 && k - j <= 3; k++) {
                    if (n - k > 3) continue;
                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k, n - k);
                    if (a[0] == '0' && a.size() > 1 ||
                        b[0] == '0' && b.size() > 1 ||
                        c[0] == '0' && c.size() > 1 ||
                        d[0] == '0' && d.size() > 1
                    ) continue;
                    int ia = stoi(a), ib = stoi(b), ic = stoi(c), id = stoi(d);
                    if (ia > 255 || ib > 255 || ic > 255 || id > 255) continue;
                    res.push_back(a + "." + b + "." + c + "." + d);
                }
            }
        }
        return res;
    }
};
```



### 几何
* [三角形： 小 Y 拼木棒](https://www.luogu.com.cn/problem/P3799)
    * [code](./code_brute_enumeration/P3799.md)
* [统计方形（数据加强版）](https://www.luogu.com.cn/problem/P2241)
    * [code](./code_brute_enumeration/P2241.md)