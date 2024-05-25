# 大整数

## 高精度加法
* [高精度加法](https://www.acwing.com/problem/content/793/)
    * [code](../acwing/acwing.791)
```c++
/**
 * A B是两个高精度正整数
 * t 是某一位的和
 * 每次循环完成后，t保存上一次加法的进位
*/
vector<int> add(const vector<int>& A, const vector<int> &B) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size() || i < B.size(); i++) {
    if (i < A.size()) t += A[i];
    if (i < B.size()) t += B[i];
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) C.push_back(t);
  return C;
}
```
## 高精度减法

* [高精度减法](https://www.acwing.com/problem/content/794/)
    * [code](../acwing/acwing.792)
```c++
vector<int> sub(const vector<int>& A, const vector<int>& B) {
  // 必须有A > B, 不处理负数;
  vector<int> C;
  for (int i = 0; i < A.size() || i < B.size(); i++) {
    int t = 0;
    if (i < B.size()) t = B[i];
    C.push_back(A[i] - t);
  }
  for (int i = 0; i < C.size(); i++) {
    if (C[i] >= 0) continue;
    C[i] += 10;
    C[i + 1] -= 1;
  }
  while (C.size() && C.back() == 0) C.pop_back();
  return C;
}
```
## 高精度加减法的应用

* [安全系统](https://www.luogu.com.cn/problem/P2638)
  * 前缀和
  * [code](../luogu/P2638)

## 高精度乘法
* [高精度乘法](https://www.acwing.com/problem/content/795/)
    * [code](../acwing/acwing.793)
```c++
/** 高精度乘以低精度
 * 考虑到b可能为0，导致结果后大量前缀0
 * 在最后将前缀0去掉
*/
vector<int> mul(vector<int>& A, int b) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size() || t; i++) {
    if (i < A.size()) t += b * A[i];
    C.push_back(t % 10);
    t /= 10;
  }
  while (C.size() > 1 && C.back() == 0) C.pop_back();
  return C;
}
```

## 高精度除法
* [高精度除法](https://www.acwing.com/problem/content/796/)
    * [code](../acwing/acwing.794.md)
```c++
vector<int> div(vector<int>& A, int b, int& r) {
  vector<int> res;
  r = 0;
  int n = A.size();
  for (int i = n - 1; i >= 0; i--) {
    r = r * 10 + A[i];
    res.push_back(r / b);
    r %= b;
  }

  reverse(res.begin(), res.end());

  while (res.size() > 1 && res.back() == 0) res.pop_back();
  return res;
}
```

## 相关题目
* [大和](http://pe-cn.github.io/13/)
  * [code](../luogu/math/high-precision/euler13.md)
* [1000位斐波那契数](http://pe-cn.github.io/25/)
  * 两个数字来回倒的编程技巧
  * [code](../luogu/math/high-precision/25.euler.md)

* [幂的数字和](http://pe-cn.github.io/16/)
  * [code](../luogu/math/high-precision/16.euler.md)

* [幂的数字和](http://pe-cn.github.io/16/)
  * [code](../luogu/math/high-precision/16.euler.md)

* [阶乘数字和](http://pe-cn.github.io/20/)
  * [code](../luogu/math/high-precision/20.euler.md)
* [英文名得分](https://pe-cn.github.io/22/)


### 除法
* [475. 大整数除法](https://oj.haizeix.com/problem/475)

* [476. 高精度取余2](https://oj.haizeix.com/problem/476)
